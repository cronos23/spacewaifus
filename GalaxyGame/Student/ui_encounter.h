/********************************************************************************
** Form generated from reading UI file 'encounter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCOUNTER_H
#define UI_ENCOUNTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_encounter
{
public:
    QLabel *picture_label;
    QLabel *response_label;
    QPushButton *option1_button;
    QPushButton *option2_button;
    QPushButton *option3_button;
    QPushButton *info_button;

    void setupUi(QWidget *encounter)
    {
        if (encounter->objectName().isEmpty())
            encounter->setObjectName(QStringLiteral("encounter"));
        encounter->resize(1093, 758);
        picture_label = new QLabel(encounter);
        picture_label->setObjectName(QStringLiteral("picture_label"));
        picture_label->setGeometry(QRect(490, 180, 101, 91));
        picture_label->setTextFormat(Qt::AutoText);
        picture_label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/starship_teal.png")));
        picture_label->setScaledContents(false);
        picture_label->setWordWrap(false);
        response_label = new QLabel(encounter);
        response_label->setObjectName(QStringLiteral("response_label"));
        response_label->setGeometry(QRect(20, 410, 1041, 41));
        QFont font;
        font.setFamily(QStringLiteral("Serif"));
        response_label->setFont(font);
        response_label->setAlignment(Qt::AlignCenter);
        option1_button = new QPushButton(encounter);
        option1_button->setObjectName(QStringLiteral("option1_button"));
        option1_button->setGeometry(QRect(30, 470, 1031, 51));
        option1_button->setFont(font);
        option2_button = new QPushButton(encounter);
        option2_button->setObjectName(QStringLiteral("option2_button"));
        option2_button->setGeometry(QRect(30, 540, 1031, 51));
        option2_button->setFont(font);
        option3_button = new QPushButton(encounter);
        option3_button->setObjectName(QStringLiteral("option3_button"));
        option3_button->setGeometry(QRect(30, 610, 1031, 51));
        option3_button->setFont(font);
        info_button = new QPushButton(encounter);
        info_button->setObjectName(QStringLiteral("info_button"));
        info_button->setGeometry(QRect(30, 680, 1031, 51));
        info_button->setFont(font);

        retranslateUi(encounter);

        QMetaObject::connectSlotsByName(encounter);
    } // setupUi

    void retranslateUi(QWidget *encounter)
    {
        encounter->setWindowTitle(QApplication::translate("encounter", "A wild spaceship appears!", 0));
        picture_label->setText(QString());
        response_label->setText(QApplication::translate("encounter", "Hey there~", 0));
        option1_button->setText(QApplication::translate("encounter", "Compliment", 0));
        option2_button->setText(QApplication::translate("encounter", "Brag", 0));
        option3_button->setText(QApplication::translate("encounter", "Bribe", 0));
        info_button->setText(QApplication::translate("encounter", "Info", 0));
    } // retranslateUi

};

namespace Ui {
    class encounter: public Ui_encounter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCOUNTER_H
