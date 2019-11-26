/********************************************************************************
** Form generated from reading UI file 'testqt.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQT_H
#define UI_TESTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQT
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Standby;
    QPushButton *pushButton_TestButton;
    QPushButton *pushButton_SaleMode;
    QPushButton *pushButtonFillingMode;
    QPushButton *pushButton_ServiceMode;
    QPushButton *pushButton_ServiceMode_2;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QTextBrowser *textBrowser_4;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QLabel *label_11;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestQT)
    {
        if (TestQT->objectName().isEmpty())
            TestQT->setObjectName(QString::fromUtf8("TestQT"));
        TestQT->resize(953, 529);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(12);
        TestQT->setFont(font);
        centralWidget = new QWidget(TestQT);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_Standby = new QPushButton(centralWidget);
        pushButton_Standby->setObjectName(QString::fromUtf8("pushButton_Standby"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Standby->sizePolicy().hasHeightForWidth());
        pushButton_Standby->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        pushButton_Standby->setFont(font1);

        horizontalLayout->addWidget(pushButton_Standby);

        pushButton_TestButton = new QPushButton(centralWidget);
        pushButton_TestButton->setObjectName(QString::fromUtf8("pushButton_TestButton"));
        sizePolicy.setHeightForWidth(pushButton_TestButton->sizePolicy().hasHeightForWidth());
        pushButton_TestButton->setSizePolicy(sizePolicy);
        pushButton_TestButton->setFont(font1);

        horizontalLayout->addWidget(pushButton_TestButton);

        pushButton_SaleMode = new QPushButton(centralWidget);
        pushButton_SaleMode->setObjectName(QString::fromUtf8("pushButton_SaleMode"));
        sizePolicy.setHeightForWidth(pushButton_SaleMode->sizePolicy().hasHeightForWidth());
        pushButton_SaleMode->setSizePolicy(sizePolicy);
        pushButton_SaleMode->setFont(font1);

        horizontalLayout->addWidget(pushButton_SaleMode);

        pushButtonFillingMode = new QPushButton(centralWidget);
        pushButtonFillingMode->setObjectName(QString::fromUtf8("pushButtonFillingMode"));
        sizePolicy.setHeightForWidth(pushButtonFillingMode->sizePolicy().hasHeightForWidth());
        pushButtonFillingMode->setSizePolicy(sizePolicy);
        pushButtonFillingMode->setFont(font1);

        horizontalLayout->addWidget(pushButtonFillingMode);

        pushButton_ServiceMode = new QPushButton(centralWidget);
        pushButton_ServiceMode->setObjectName(QString::fromUtf8("pushButton_ServiceMode"));
        sizePolicy.setHeightForWidth(pushButton_ServiceMode->sizePolicy().hasHeightForWidth());
        pushButton_ServiceMode->setSizePolicy(sizePolicy);
        pushButton_ServiceMode->setFont(font1);

        horizontalLayout->addWidget(pushButton_ServiceMode);

        pushButton_ServiceMode_2 = new QPushButton(centralWidget);
        pushButton_ServiceMode_2->setObjectName(QString::fromUtf8("pushButton_ServiceMode_2"));
        sizePolicy.setHeightForWidth(pushButton_ServiceMode_2->sizePolicy().hasHeightForWidth());
        pushButton_ServiceMode_2->setSizePolicy(sizePolicy);
        pushButton_ServiceMode_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_ServiceMode_2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_4);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_5);

        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(7);
        sizePolicy2.setVerticalStretch(6);
        sizePolicy2.setHeightForWidth(textBrowser_4->sizePolicy().hasHeightForWidth());
        textBrowser_4->setSizePolicy(sizePolicy2);
        textBrowser_4->setMinimumSize(QSize(0, 69));
        textBrowser_4->setMaximumSize(QSize(16777212, 83));
        textBrowser_4->setFont(font1);

        verticalLayout_6->addWidget(textBrowser_4);


        gridLayout_3->addLayout(verticalLayout_6, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_11, 0, 1, 1, 1);

        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowser_2->sizePolicy().hasHeightForWidth());
        textBrowser_2->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        textBrowser_2->setFont(font2);

        gridLayout_2->addWidget(textBrowser_2, 1, 0, 1, 1);

        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        sizePolicy4.setHeightForWidth(textBrowser_3->sizePolicy().hasHeightForWidth());
        textBrowser_3->setSizePolicy(sizePolicy4);
        textBrowser_3->setFont(font2);

        gridLayout_2->addWidget(textBrowser_3, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy5);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 212, 0);"));

        verticalLayout_2->addWidget(pushButton_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy5.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(pushButton_8, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy5.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(pushButton_9, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy5.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy5.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy6);
        QFont font3;
        font3.setPointSize(14);
        textBrowser->setFont(font3);

        verticalLayout_3->addWidget(textBrowser);


        gridLayout_4->addLayout(verticalLayout_3, 1, 1, 1, 1);

        TestQT->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestQT);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 24));
        TestQT->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestQT);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestQT->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestQT);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestQT->setStatusBar(statusBar);

        retranslateUi(TestQT);

        QMetaObject::connectSlotsByName(TestQT);
    } // setupUi

    void retranslateUi(QMainWindow *TestQT)
    {
        TestQT->setWindowTitle(QCoreApplication::translate("TestQT", "TestQT", nullptr));
        pushButton_Standby->setText(QCoreApplication::translate("TestQT", "Standby", nullptr));
        pushButton_TestButton->setText(QCoreApplication::translate("TestQT", "Button", nullptr));
        pushButton_SaleMode->setText(QCoreApplication::translate("TestQT", "Sale mode", nullptr));
        pushButtonFillingMode->setText(QCoreApplication::translate("TestQT", "Filling mode", nullptr));
        pushButton_ServiceMode->setText(QCoreApplication::translate("TestQT", "Service mode", nullptr));
        pushButton_ServiceMode_2->setText(QCoreApplication::translate("TestQT", "Reopen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("TestQT", "Update list", nullptr));
        label_5->setText(QCoreApplication::translate("TestQT", "FileModes:", nullptr));
        label_10->setText(QCoreApplication::translate("TestQT", "\320\241\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\265 \321\205\320\276\320\273\320\276\320\264\320\270\320\273\321\214\320\275\320\270\320\272\320\260", nullptr));
        label_11->setText(QCoreApplication::translate("TestQT", "\320\232\321\203\320\277\320\273\320\265\320\275\320\275\321\213\320\265 \321\202\320\276\320\262\320\260\321\200\321\213", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("TestQT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu Mono'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu Mono'; font-size:15pt;\"><br /></p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("TestQT", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu Mono'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu Mono'; font-size:14pt;\"><br /></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TestQT", "RFID READER RUN", nullptr));
        pushButton_8->setText(QCoreApplication::translate("TestQT", "RFID ENABLE", nullptr));
        pushButton_9->setText(QCoreApplication::translate("TestQT", "OUT_1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TestQT", "SENSOR", nullptr));
        pushButton->setText(QCoreApplication::translate("TestQT", "OUT_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestQT: public Ui_TestQT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQT_H
