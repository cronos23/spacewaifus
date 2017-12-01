/********************************************************************************
** Form generated from reading UI file 'controls.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLS_H
#define UI_CONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controls
{
public:
    QLabel *title_label;
    QLabel *controlsTitle_label;
    QLabel *controls_label;
    QLabel *tipsTitle_label;
    QLabel *tips_label;
    QPushButton *cancel_button;

    void setupUi(QWidget *controls)
    {
        if (controls->objectName().isEmpty())
            controls->setObjectName(QStringLiteral("controls"));
        controls->resize(851, 702);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(controls->sizePolicy().hasHeightForWidth());
        controls->setSizePolicy(sizePolicy);
        controls->setMinimumSize(QSize(851, 702));
        controls->setMaximumSize(QSize(851, 702));
        title_label = new QLabel(controls);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(10, 10, 831, 111));
        QFont font;
        font.setFamily(QStringLiteral("Serif"));
        font.setPointSize(22);
        font.setBold(false);
        font.setWeight(50);
        title_label->setFont(font);
        title_label->setAlignment(Qt::AlignCenter);
        controlsTitle_label = new QLabel(controls);
        controlsTitle_label->setObjectName(QStringLiteral("controlsTitle_label"));
        controlsTitle_label->setGeometry(QRect(40, 110, 151, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Serif"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        controlsTitle_label->setFont(font1);
        controlsTitle_label->setAlignment(Qt::AlignCenter);
        controls_label = new QLabel(controls);
        controls_label->setObjectName(QStringLiteral("controls_label"));
        controls_label->setGeometry(QRect(70, 170, 401, 141));
        QFont font2;
        font2.setFamily(QStringLiteral("Serif"));
        controls_label->setFont(font2);
        controls_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        tipsTitle_label = new QLabel(controls);
        tipsTitle_label->setObjectName(QStringLiteral("tipsTitle_label"));
        tipsTitle_label->setGeometry(QRect(20, 300, 151, 51));
        tipsTitle_label->setFont(font1);
        tipsTitle_label->setAlignment(Qt::AlignCenter);
        tips_label = new QLabel(controls);
        tips_label->setObjectName(QStringLiteral("tips_label"));
        tips_label->setGeometry(QRect(80, 360, 721, 221));
        tips_label->setFont(font2);
        tips_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        cancel_button = new QPushButton(controls);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(660, 590, 171, 91));
        QFont font3;
        font3.setFamily(QStringLiteral("Serif"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setWeight(50);
        cancel_button->setFont(font3);

        retranslateUi(controls);
        QObject::connect(cancel_button, SIGNAL(clicked()), controls, SLOT(close()));

        QMetaObject::connectSlotsByName(controls);
    } // setupUi

    void retranslateUi(QWidget *controls)
    {
        controls->setWindowTitle(QApplication::translate("controls", "Controls and Tips", 0));
        title_label->setText(QApplication::translate("controls", "Controls and Tips", 0));
        controlsTitle_label->setText(QApplication::translate("controls", "Controls", 0));
        controls_label->setText(QApplication::translate("controls", "<html><head/><body><p>Up arrow key - Move forward</p><p>Left/Right arrow key - Turn</p><p>Mouse wheel - Zoom</p><p>Click and drag with mouse - Move the map</p></body></html>", 0));
        tipsTitle_label->setText(QApplication::translate("controls", "Tips", 0));
        tips_label->setText(QApplication::translate("controls", "<html><head/><body><p>The point of the game is to travel across different star systems to search for spaceships </p><p>to date. Your time is limited so act fast! The more spaceships you &quot;befriend&quot; </p><p>the more points you get! It's like speed dating. </p><p>Being rejected lowers your points so first you need to find out the right things to say. </p></body></html>", 0));
        cancel_button->setText(QApplication::translate("controls", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class controls: public Ui_controls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLS_H
