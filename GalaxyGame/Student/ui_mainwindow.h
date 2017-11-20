/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *score_label;
    QLCDNumber *score_LCD;
    QLabel *credits_label;
    QLCDNumber *credits_LCD;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1832, 1052);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1611, 1011));
        score_label = new QLabel(centralwidget);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(1620, 10, 81, 31));
        QFont font;
        font.setFamily(QStringLiteral("Cantarell"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        score_label->setFont(font);
        score_LCD = new QLCDNumber(centralwidget);
        score_LCD->setObjectName(QStringLiteral("score_LCD"));
        score_LCD->setGeometry(QRect(1710, 10, 71, 31));
        credits_label = new QLabel(centralwidget);
        credits_label->setObjectName(QStringLiteral("credits_label"));
        credits_label->setGeometry(QRect(1620, 70, 71, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        credits_label->setFont(font1);
        credits_LCD = new QLCDNumber(centralwidget);
        credits_LCD->setObjectName(QStringLiteral("credits_LCD"));
        credits_LCD->setGeometry(QRect(1710, 70, 71, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1640, 180, 121, 51));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1620, 230, 211, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1620, 270, 171, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1620, 300, 181, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1620, 670, 101, 51));
        pushButton->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        score_label->setText(QApplication::translate("MainWindow", "Score", 0));
        credits_label->setText(QApplication::translate("MainWindow", "Credits", 0));
        label->setText(QApplication::translate("MainWindow", "Controls", 0));
        label_2->setText(QApplication::translate("MainWindow", "Right/Left Arrow key: Turn", 0));
        label_3->setText(QApplication::translate("MainWindow", "Up Arrow Key: Forward", 0));
        label_4->setText(QApplication::translate("MainWindow", "Down Arrow Key: Backward", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Quit Game", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
