/********************************************************************************
** Form generated from reading UI file 'serialportworker.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTWORKER_H
#define UI_SERIALPORTWORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortWorker
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *commandLinkButton_MPC;
    QCommandLinkButton *commandLinkButton_LC;
    QCommandLinkButton *commandLinkButton_NS;
    QCommandLinkButton *commandLinkButton_ES;
    QCommandLinkButton *commandLinkButton_SYN;
    QCommandLinkButton *commandLinkButton_TOT;
    QCommandLinkButton *commandLinkButton_EXIT;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SerialPortWorker)
    {
        if (SerialPortWorker->objectName().isEmpty())
            SerialPortWorker->setObjectName(QString::fromUtf8("SerialPortWorker"));
        SerialPortWorker->resize(822, 533);
        centralWidget = new QWidget(SerialPortWorker);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        commandLinkButton_MPC = new QCommandLinkButton(centralWidget);
        commandLinkButton_MPC->setObjectName(QString::fromUtf8("commandLinkButton_MPC"));

        verticalLayout->addWidget(commandLinkButton_MPC);

        commandLinkButton_LC = new QCommandLinkButton(centralWidget);
        commandLinkButton_LC->setObjectName(QString::fromUtf8("commandLinkButton_LC"));
        commandLinkButton_LC->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(commandLinkButton_LC);

        commandLinkButton_NS = new QCommandLinkButton(centralWidget);
        commandLinkButton_NS->setObjectName(QString::fromUtf8("commandLinkButton_NS"));

        verticalLayout->addWidget(commandLinkButton_NS);

        commandLinkButton_ES = new QCommandLinkButton(centralWidget);
        commandLinkButton_ES->setObjectName(QString::fromUtf8("commandLinkButton_ES"));

        verticalLayout->addWidget(commandLinkButton_ES);

        commandLinkButton_SYN = new QCommandLinkButton(centralWidget);
        commandLinkButton_SYN->setObjectName(QString::fromUtf8("commandLinkButton_SYN"));

        verticalLayout->addWidget(commandLinkButton_SYN);

        commandLinkButton_TOT = new QCommandLinkButton(centralWidget);
        commandLinkButton_TOT->setObjectName(QString::fromUtf8("commandLinkButton_TOT"));

        verticalLayout->addWidget(commandLinkButton_TOT);

        commandLinkButton_EXIT = new QCommandLinkButton(centralWidget);
        commandLinkButton_EXIT->setObjectName(QString::fromUtf8("commandLinkButton_EXIT"));

        verticalLayout->addWidget(commandLinkButton_EXIT);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        SerialPortWorker->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SerialPortWorker);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 21));
        SerialPortWorker->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SerialPortWorker);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SerialPortWorker->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SerialPortWorker);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SerialPortWorker->setStatusBar(statusBar);

        retranslateUi(SerialPortWorker);

        QMetaObject::connectSlotsByName(SerialPortWorker);
    } // setupUi

    void retranslateUi(QMainWindow *SerialPortWorker)
    {
        SerialPortWorker->setWindowTitle(QApplication::translate("SerialPortWorker", "SerialPortWorker", nullptr));
        commandLinkButton_MPC->setText(QApplication::translate("SerialPortWorker", "mode_material_part_control      ", nullptr));
        commandLinkButton_LC->setText(QApplication::translate("SerialPortWorker", "mode_line_checking              ", nullptr));
        commandLinkButton_NS->setText(QApplication::translate("SerialPortWorker", "mode_normal_start               ", nullptr));
        commandLinkButton_ES->setText(QApplication::translate("SerialPortWorker", "mode_extro_start                      ", nullptr));
        commandLinkButton_SYN->setText(QApplication::translate("SerialPortWorker", "mode_synchro", nullptr));
        commandLinkButton_TOT->setText(QApplication::translate("SerialPortWorker", "mode_total_status", nullptr));
        commandLinkButton_EXIT->setText(QApplication::translate("SerialPortWorker", "mode_exit", nullptr));
        pushButton->setText(QApplication::translate("SerialPortWorker", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPortWorker: public Ui_SerialPortWorker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTWORKER_H
