/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainmenu
{
public:
    QLabel *label;
    QPushButton *play_button;
    QPushButton *controls_button;
    QPushButton *quit_button;
    QLabel *label_2;

    void setupUi(QWidget *mainmenu)
    {
        if (mainmenu->objectName().isEmpty())
            mainmenu->setObjectName(QStringLiteral("mainmenu"));
        mainmenu->resize(880, 693);
        label = new QLabel(mainmenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 861, 71));
        QFont font;
        font.setFamily(QStringLiteral("Serif"));
        font.setPointSize(36);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        play_button = new QPushButton(mainmenu);
        play_button->setObjectName(QStringLiteral("play_button"));
        play_button->setGeometry(QRect(350, 240, 171, 91));
        QFont font1;
        font1.setFamily(QStringLiteral("Serif"));
        font1.setPointSize(22);
        play_button->setFont(font1);
        controls_button = new QPushButton(mainmenu);
        controls_button->setObjectName(QStringLiteral("controls_button"));
        controls_button->setGeometry(QRect(350, 390, 171, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("Serif"));
        font2.setPointSize(18);
        controls_button->setFont(font2);
        quit_button = new QPushButton(mainmenu);
        quit_button->setObjectName(QStringLiteral("quit_button"));
        quit_button->setGeometry(QRect(350, 500, 171, 71));
        quit_button->setFont(font2);
        label_2 = new QLabel(mainmenu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 801, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("Serif"));
        font3.setPointSize(15);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(mainmenu);
        QObject::connect(quit_button, SIGNAL(clicked()), mainmenu, SLOT(close()));

        QMetaObject::connectSlotsByName(mainmenu);
    } // setupUi

    void retranslateUi(QWidget *mainmenu)
    {
        mainmenu->setWindowTitle(QApplication::translate("mainmenu", "Dream Ships", 0));
        label->setText(QApplication::translate("mainmenu", "Dream Ships", 0));
        play_button->setText(QApplication::translate("mainmenu", "Play", 0));
        controls_button->setText(QApplication::translate("mainmenu", "Controls/Tips", 0));
        quit_button->setText(QApplication::translate("mainmenu", "Quit", 0));
        label_2->setText(QApplication::translate("mainmenu", "The totally serious starship dating simulator", 0));
    } // retranslateUi

};

namespace Ui {
    class mainmenu: public Ui_mainmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
