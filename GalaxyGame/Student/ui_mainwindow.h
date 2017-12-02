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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    GraphicsViewControls *graphicsView;
    QLabel *score_label;
    QLCDNumber *score_LCD;
    QLabel *credits_label;
    QLCDNumber *credits_LCD;
    QLabel *dated_label;
    QLCDNumber *saved_LCD;
    QLabel *lost_label;
    QLCDNumber *lost_LCD;
    QLabel *label;
    QListWidget *distress_signals;
    QPushButton *Quit_Button;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1692, 897);
        MainWindow->setMinimumSize(QSize(1692, 897));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/player_ship.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new GraphicsViewControls(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
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
        graphicsView->setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
        graphicsView->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);

        gridLayout->addWidget(graphicsView, 0, 0, 7, 1);

        score_label = new QLabel(centralwidget);
        score_label->setObjectName(QStringLiteral("score_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Serif"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        score_label->setFont(font1);

        gridLayout->addWidget(score_label, 0, 1, 1, 1);

        score_LCD = new QLCDNumber(centralwidget);
        score_LCD->setObjectName(QStringLiteral("score_LCD"));
        score_LCD->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        score_LCD->setDigitCount(6);

        gridLayout->addWidget(score_LCD, 0, 2, 1, 1);

        credits_label = new QLabel(centralwidget);
        credits_label->setObjectName(QStringLiteral("credits_label"));
        credits_label->setFont(font1);
        credits_label->setScaledContents(false);

        gridLayout->addWidget(credits_label, 1, 1, 1, 1);

        credits_LCD = new QLCDNumber(centralwidget);
        credits_LCD->setObjectName(QStringLiteral("credits_LCD"));
        credits_LCD->setStyleSheet(QLatin1String("\n"
"background-color: rgb(33, 33, 33);"));
        credits_LCD->setSmallDecimalPoint(false);
        credits_LCD->setDigitCount(6);
        credits_LCD->setProperty("value", QVariant(0));

        gridLayout->addWidget(credits_LCD, 1, 2, 1, 1);

        dated_label = new QLabel(centralwidget);
        dated_label->setObjectName(QStringLiteral("dated_label"));
        QFont font2;
        font2.setFamily(QStringLiteral("Serif"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setKerning(true);
        dated_label->setFont(font2);
        dated_label->setScaledContents(false);

        gridLayout->addWidget(dated_label, 2, 1, 1, 1);

        saved_LCD = new QLCDNumber(centralwidget);
        saved_LCD->setObjectName(QStringLiteral("saved_LCD"));
        saved_LCD->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        saved_LCD->setSmallDecimalPoint(false);
        saved_LCD->setDigitCount(6);
        saved_LCD->setProperty("value", QVariant(0));

        gridLayout->addWidget(saved_LCD, 2, 2, 1, 1);

        lost_label = new QLabel(centralwidget);
        lost_label->setObjectName(QStringLiteral("lost_label"));
        lost_label->setFont(font1);

        gridLayout->addWidget(lost_label, 3, 1, 1, 1);

        lost_LCD = new QLCDNumber(centralwidget);
        lost_LCD->setObjectName(QStringLiteral("lost_LCD"));
        lost_LCD->setStyleSheet(QStringLiteral("background-color: rgb(33, 33, 33);"));
        lost_LCD->setSmallDecimalPoint(false);
        lost_LCD->setDigitCount(6);
        lost_LCD->setProperty("value", QVariant(0));

        gridLayout->addWidget(lost_LCD, 3, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QStringLiteral("Serif"));
        font3.setPointSize(14);
        label->setFont(font3);

        gridLayout->addWidget(label, 4, 1, 1, 2);

        distress_signals = new QListWidget(centralwidget);
        distress_signals->setObjectName(QStringLiteral("distress_signals"));

        gridLayout->addWidget(distress_signals, 5, 1, 1, 2);

        Quit_Button = new QPushButton(centralwidget);
        Quit_Button->setObjectName(QStringLiteral("Quit_Button"));
        Quit_Button->setFont(font1);

        gridLayout->addWidget(Quit_Button, 6, 1, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

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
        dated_label->setText(QApplication::translate("MainWindow", "Ships dated", 0));
        lost_label->setText(QApplication::translate("MainWindow", "Times rejected", 0));
        label->setText(QApplication::translate("MainWindow", "Distress Signals", 0));
        Quit_Button->setText(QApplication::translate("MainWindow", "Quit Game", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
