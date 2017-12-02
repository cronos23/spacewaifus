/********************************************************************************
** Form generated from reading UI file 'game_over.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OVER_H
#define UI_GAME_OVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_over
{
public:
    QLabel *header_lable;
    QLabel *dated_label;
    QLabel *rejected_label;
    QLabel *points_label;
    QPushButton *pushButton;

    void setupUi(QWidget *game_over)
    {
        if (game_over->objectName().isEmpty())
            game_over->setObjectName(QStringLiteral("game_over"));
        game_over->resize(580, 701);
        header_lable = new QLabel(game_over);
        header_lable->setObjectName(QStringLiteral("header_lable"));
        header_lable->setGeometry(QRect(60, 20, 451, 131));
        QFont font;
        font.setFamily(QStringLiteral("Serif"));
        font.setPointSize(30);
        header_lable->setFont(font);
        header_lable->setAlignment(Qt::AlignCenter);
        dated_label = new QLabel(game_over);
        dated_label->setObjectName(QStringLiteral("dated_label"));
        dated_label->setGeometry(QRect(60, 170, 461, 41));
        QFont font1;
        font1.setPointSize(18);
        dated_label->setFont(font1);
        rejected_label = new QLabel(game_over);
        rejected_label->setObjectName(QStringLiteral("rejected_label"));
        rejected_label->setGeometry(QRect(60, 230, 491, 41));
        rejected_label->setFont(font1);
        points_label = new QLabel(game_over);
        points_label->setObjectName(QStringLiteral("points_label"));
        points_label->setGeometry(QRect(60, 330, 441, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Serif"));
        font2.setPointSize(30);
        font2.setBold(false);
        font2.setWeight(50);
        points_label->setFont(font2);
        pushButton = new QPushButton(game_over);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 590, 131, 81));
        QFont font3;
        font3.setFamily(QStringLiteral("Serif"));
        font3.setPointSize(20);
        pushButton->setFont(font3);

        retranslateUi(game_over);
        QObject::connect(pushButton, SIGNAL(clicked()), game_over, SLOT(close()));

        QMetaObject::connectSlotsByName(game_over);
    } // setupUi

    void retranslateUi(QWidget *game_over)
    {
        game_over->setWindowTitle(QApplication::translate("game_over", "Form", 0));
        header_lable->setText(QApplication::translate("game_over", "Time's up!", 0));
        dated_label->setText(QApplication::translate("game_over", "You dated x spaceships!", 0));
        rejected_label->setText(QApplication::translate("game_over", "You got rejected by x spaceships", 0));
        points_label->setText(QApplication::translate("game_over", "Your points :  xx", 0));
        pushButton->setText(QApplication::translate("game_over", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class game_over: public Ui_game_over {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OVER_H
