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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "graphicsviewcontrols.hh"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    GraphicsViewControls *graphicsView;
    QLabel *score_label;
    QLCDNumber *score_LCD;
    QLabel *credits_label;
    QLCDNumber *credits_LCD;
    QPushButton *Quit_Button;
    QLabel *dated_label;
    QLCDNumber *saved_LCD;
    QLabel *lost_label;
    QLCDNumber *lost_LCD;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1692, 897);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new GraphicsViewControls(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1411, 871));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setAutoFillBackground(false);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setInteractive(true);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        graphicsView->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);
        score_label = new QLabel(centralwidget);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(1490, 10, 81, 31));
        QFont font;
        font.setFamily(QStringLiteral("Serif"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        score_label->setFont(font);
        score_LCD = new QLCDNumber(centralwidget);
        score_LCD->setObjectName(QStringLiteral("score_LCD"));
        score_LCD->setGeometry(QRect(1580, 10, 91, 41));
        score_LCD->setDigitCount(6);
        credits_label = new QLabel(centralwidget);
        credits_label->setObjectName(QStringLiteral("credits_label"));
        credits_label->setGeometry(QRect(1490, 70, 71, 31));
        credits_label->setFont(font);
        credits_LCD = new QLCDNumber(centralwidget);
        credits_LCD->setObjectName(QStringLiteral("credits_LCD"));
        credits_LCD->setGeometry(QRect(1580, 70, 91, 41));
        credits_LCD->setSmallDecimalPoint(false);
        credits_LCD->setDigitCount(6);
        credits_LCD->setProperty("value", QVariant(0));
        Quit_Button = new QPushButton(centralwidget);
        Quit_Button->setObjectName(QStringLiteral("Quit_Button"));
        Quit_Button->setGeometry(QRect(1570, 810, 111, 51));
        Quit_Button->setFont(font);
        dated_label = new QLabel(centralwidget);
        dated_label->setObjectName(QStringLiteral("dated_label"));
        dated_label->setGeometry(QRect(1440, 200, 111, 31));
        dated_label->setFont(font);
        saved_LCD = new QLCDNumber(centralwidget);
        saved_LCD->setObjectName(QStringLiteral("saved_LCD"));
        saved_LCD->setGeometry(QRect(1580, 190, 91, 41));
        saved_LCD->setSmallDecimalPoint(false);
        saved_LCD->setDigitCount(6);
        saved_LCD->setProperty("value", QVariant(0));
        lost_label = new QLabel(centralwidget);
        lost_label->setObjectName(QStringLiteral("lost_label"));
        lost_label->setGeometry(QRect(1420, 280, 141, 31));
        lost_label->setFont(font);
        lost_LCD = new QLCDNumber(centralwidget);
        lost_LCD->setObjectName(QStringLiteral("lost_LCD"));
        lost_LCD->setGeometry(QRect(1580, 270, 91, 41));
        lost_LCD->setSmallDecimalPoint(false);
        lost_LCD->setDigitCount(6);
        lost_LCD->setProperty("value", QVariant(0));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(Quit_Button, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dream Ships", 0));
        score_label->setText(QApplication::translate("MainWindow", "Score", 0));
        credits_label->setText(QApplication::translate("MainWindow", "Credits", 0));
        Quit_Button->setText(QApplication::translate("MainWindow", "Quit Game", 0));
        dated_label->setText(QApplication::translate("MainWindow", "Ships dated", 0));
        lost_label->setText(QApplication::translate("MainWindow", "Times rejected", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
