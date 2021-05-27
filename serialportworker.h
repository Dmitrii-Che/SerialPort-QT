#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#include <QMainWindow>

#include<QCoreApplication>
#include<QSerialPort>
#include<QSerialPortInfo>
#include<iostream>


namespace Ui {
    class SerialPortWorker;
}

using pPortList = QSharedPointer<QList<QSerialPortInfo>>;
using pPort = QSharedPointer<QSerialPort>;

class SerialPortWorker : public QMainWindow {
        Q_OBJECT

    public:
        explicit SerialPortWorker(QWidget* parent = nullptr);
        ~SerialPortWorker();
        void initPort(int COMPortN = 0);
        void makePortSettings();
        void makeConnections();
        void checkCOMConnection();
        char* readData();
        void writeData(const char* data, unsigned size);
        void writeData(char data);
        void stopTransmission();

        bool _transmissionIsActiv = false;
    private:
        void makeMenu();
        void addText(const QString &str, bool clr = 0);

    private slots:
        void on_commandLinkButton_LC_clicked();
        void on_commandLinkButton_NS_clicked();
        void on_commandLinkButton_ES_clicked();
        void on_commandLinkButton_EXIT_clicked();
        void on_commandLinkButton_MPC_clicked();

        void on_pushButton_clicked();

        void on_commandLinkButton_SYN_clicked();

        void on_commandLinkButton_TOT_clicked();

    private:
        Ui::SerialPortWorker* ui = nullptr;
        pPortList _ports = nullptr;
        pPort _port  = nullptr;
        QString outPortStr;
    protected:
        void paintEvent(QPaintEvent* event);

        // QWidget interface
    protected:
        void keyPressEvent(QKeyEvent* event);
};

#endif // SERIALPORTWORKER_H
