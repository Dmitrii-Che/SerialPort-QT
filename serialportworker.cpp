#define Debug

#ifdef Debug
    #include<QDebug>
#endif

#include "serialportworker.h"
#include "ui_serialportworker.h"
#include "windows.h"
#include <QScrollBar>

enum class Modes {
    mode_material_part_control      = 0xD1,   // Mode - Material Part Control
    mode_line_checking              = 0xD2,   // Mode - Line Checking
    mode_normal_start               = 0xD3,   // Mode - Normal Start
    mode_extro_start                = 0xD4,   // Mode - Extro Start
    mode_synchro                    = 0xD5,   // Mode - Syncronization 10s
    mode_total_status               = 0xD6,     // Mode - Print Total Status
    mode_exit                       = 0xEE    // EXIT
};


SerialPortWorker::SerialPortWorker(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::SerialPortWorker)
{
    ui->setupUi(this);
    //    _port = new QSerialPort();
    _port = pPort(new QSerialPort());
    _ports = pPortList(new QList<QSerialPortInfo>(QSerialPortInfo::availablePorts()));
    makeConnections();
    makeMenu();
    initPort(0);
}

SerialPortWorker::~SerialPortWorker()
{
    _port->close();
    delete ui;
}

void SerialPortWorker::initPort(int COMPortN)
{
    if(_port->isOpen()) {
        _port->close();
    }

    _port->setPort(_ports->at(COMPortN));
    QObject::connect(_port.get(), &QSerialPort::readyRead, [&] {
        readData();
    });

    makePortSettings();
    checkCOMConnection();
}

void SerialPortWorker::makePortSettings()
{
    _port->setBaudRate(QSerialPort::Baud115200);//Speed115200
    _port->setDataBits(QSerialPort::Data8);
    _port->setStopBits(QSerialPort::OneStop);
    _port->setParity(QSerialPort::NoParity);
}

void SerialPortWorker::makeConnections()
{

}

void SerialPortWorker::checkCOMConnection()
{
    QString str = "XXX";
    str = _port->portName();

    if(!_port->open(QIODevice::ReadWrite)) {
        outPortStr.append(QString("\nconnection to: %1: is failure\n").arg(str));
        ui->textBrowser->setText(outPortStr);
    }
    else {
        outPortStr.append(QString("\nconnection to: %1: is active\n").arg(str));
        ui->textBrowser->setText(outPortStr);
    }
}

char* SerialPortWorker::readData()
{
    auto data = _port->readAll().data();
    addText(QString("%1").arg(data));
    return data;
}

void SerialPortWorker::writeData(const char* data, unsigned size)
{
    _port->write(data, size);
    _port->waitForBytesWritten();
}

void SerialPortWorker::writeData(char data)
{
    _port->write(&data, 1);
    _port->waitForBytesWritten();
}

void SerialPortWorker::makeMenu()
{
    /*Menu***************************************/
    QMenu* menu = new QMenu("Menu");
    menu->addAction("&Help", this, [ = ] {
        //        addText("\n***\nЗдравствуй, Дорогой друг.\nКогда-нибудь здесь будет открываться \nдоп окошко со справкой\n***\n");
        addText("\n***********************************************");
    }, Qt::Key_F1);

    menu->addSeparator();

    /*Entering COMs************************/
    int portN = 0;

    for(auto const &port : *_ports) {
        menu->addAction(port.portName(), this, [ = ] {
            initPort(portN);
        }, static_cast<int>((0x31 + portN)) | static_cast<int>(Qt::ALT));
        portN++;
    }

    /*End Entering Entering COMs***********/

    menu->addSeparator();
    menu->addAction(
        "&Exit", this, [this] { close(); }, /*Qt::CTRL |*/ Qt::Key_Q | Qt::ALT);
    menuBar()->addMenu(menu);
    /*END Menu***************************************/
}

void SerialPortWorker::addText(const QString &str, bool clr)
{
    if(clr) {
        outPortStr.clear();
    }
    else {
        outPortStr.append(str);
    }

    ui->textBrowser->setText(outPortStr);

    int max = ui->textBrowser->verticalScrollBar()->maximum();
    ui->textBrowser->verticalScrollBar()->setValue(max);
    update();
}

/************************************************************/
void SerialPortWorker::on_commandLinkButton_LC_clicked()
{
    writeData(static_cast<char>(Modes::mode_line_checking));
    addText("\nmode_line_checking");
}

void SerialPortWorker::on_commandLinkButton_NS_clicked()
{
    writeData(static_cast<char>(Modes::mode_normal_start));
    addText("\nmode_normal_start");
}

void SerialPortWorker::on_commandLinkButton_ES_clicked()
{
    writeData(static_cast<char>(Modes::mode_extro_start));
    addText("\nmode_extro_start");
}

void SerialPortWorker::on_commandLinkButton_EXIT_clicked()
{
    writeData(static_cast<char>(Modes::mode_exit));
    addText("\nmode_exit");
}

void SerialPortWorker::on_commandLinkButton_MPC_clicked()
{
    writeData(static_cast<char>(Modes::mode_material_part_control));
    addText("\nmode_material_part_control");
}

void SerialPortWorker::paintEvent(QPaintEvent* event)
{
    int max = ui->textBrowser->verticalScrollBar()->maximum();
    ui->textBrowser->verticalScrollBar()->setValue(max);
}
void SerialPortWorker::keyPressEvent(QKeyEvent* event)
{

}
void SerialPortWorker::on_pushButton_clicked()
{
    addText("", 1);
}

void SerialPortWorker::on_commandLinkButton_SYN_clicked()
{
    writeData(static_cast<char>(Modes::mode_synchro));
    addText("\nmode_synchro");
}

void SerialPortWorker::on_commandLinkButton_TOT_clicked()
{
    writeData(static_cast<char>(Modes::mode_total_status));
    addText("\nmode_total_status");
}
