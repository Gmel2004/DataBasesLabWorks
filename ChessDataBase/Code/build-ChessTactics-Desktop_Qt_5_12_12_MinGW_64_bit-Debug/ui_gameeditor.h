/********************************************************************************
** Form generated from reading UI file 'gameeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEEDITOR_H
#define UI_GAMEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_GameEditor
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *remove;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_11;
    QLineEdit *link;
    QLabel *label_10;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_8;
    QLineEdit *tactics;
    QLabel *label_9;
    QComboBox *linkBox;
    QSpinBox *sequenceToLength;
    QComboBox *tacticsBox;
    QComboBox *opening;
    QSpinBox *secondToAdd;
    QTimeEdit *startTime;
    QSpinBox *moveCount;
    QDateEdit *date;
    QComboBox *platform;
    QComboBox *blackNickName;
    QComboBox *whiteNickName;
    QComboBox *result;
    QPushButton *change;
    QPushButton *add;
    QLabel *label_12;
    QPushButton *moveBack;

    void setupUi(QDialog *GameEditor)
    {
        if (GameEditor->objectName().isEmpty())
            GameEditor->setObjectName(QString::fromUtf8("GameEditor"));
        GameEditor->resize(673, 588);
        gridLayout_2 = new QGridLayout(GameEditor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        remove = new QPushButton(GameEditor);
        remove->setObjectName(QString::fromUtf8("remove"));
        QFont font;
        font.setPointSize(14);
        remove->setFont(font);

        gridLayout_2->addWidget(remove, 3, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(GameEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_6 = new QLabel(GameEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_13 = new QLabel(GameEditor);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        label = new QLabel(GameEditor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(GameEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        label_2 = new QLabel(GameEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_11 = new QLabel(GameEditor);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        link = new QLineEdit(GameEditor);
        link->setObjectName(QString::fromUtf8("link"));
        link->setFont(font);

        gridLayout->addWidget(link, 8, 2, 1, 2);

        label_10 = new QLabel(GameEditor);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 11, 0, 1, 1);

        label_5 = new QLabel(GameEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_3 = new QLabel(GameEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_8 = new QLabel(GameEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        tactics = new QLineEdit(GameEditor);
        tactics->setObjectName(QString::fromUtf8("tactics"));
        tactics->setFont(font);

        gridLayout->addWidget(tactics, 6, 3, 1, 1);

        label_9 = new QLabel(GameEditor);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        linkBox = new QComboBox(GameEditor);
        linkBox->setObjectName(QString::fromUtf8("linkBox"));
        linkBox->setFont(font);

        gridLayout->addWidget(linkBox, 8, 1, 1, 1);

        sequenceToLength = new QSpinBox(GameEditor);
        sequenceToLength->setObjectName(QString::fromUtf8("sequenceToLength"));
        sequenceToLength->setFont(font);

        gridLayout->addWidget(sequenceToLength, 7, 1, 1, 3);

        tacticsBox = new QComboBox(GameEditor);
        tacticsBox->setObjectName(QString::fromUtf8("tacticsBox"));
        tacticsBox->setFont(font);

        gridLayout->addWidget(tacticsBox, 6, 1, 1, 2);

        opening = new QComboBox(GameEditor);
        opening->setObjectName(QString::fromUtf8("opening"));
        opening->setFont(font);

        gridLayout->addWidget(opening, 5, 1, 1, 3);

        secondToAdd = new QSpinBox(GameEditor);
        secondToAdd->setObjectName(QString::fromUtf8("secondToAdd"));
        secondToAdd->setFont(font);

        gridLayout->addWidget(secondToAdd, 4, 1, 1, 3);

        startTime = new QTimeEdit(GameEditor);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setFont(font);

        gridLayout->addWidget(startTime, 3, 1, 1, 3);

        moveCount = new QSpinBox(GameEditor);
        moveCount->setObjectName(QString::fromUtf8("moveCount"));
        moveCount->setFont(font);

        gridLayout->addWidget(moveCount, 2, 1, 1, 3);

        date = new QDateEdit(GameEditor);
        date->setObjectName(QString::fromUtf8("date"));
        date->setFont(font);

        gridLayout->addWidget(date, 1, 1, 1, 3);

        platform = new QComboBox(GameEditor);
        platform->setObjectName(QString::fromUtf8("platform"));
        platform->setFont(font);

        gridLayout->addWidget(platform, 0, 1, 1, 3);

        blackNickName = new QComboBox(GameEditor);
        blackNickName->setObjectName(QString::fromUtf8("blackNickName"));
        blackNickName->setFont(font);

        gridLayout->addWidget(blackNickName, 9, 1, 1, 3);

        whiteNickName = new QComboBox(GameEditor);
        whiteNickName->setObjectName(QString::fromUtf8("whiteNickName"));
        whiteNickName->setFont(font);

        gridLayout->addWidget(whiteNickName, 10, 1, 1, 3);

        result = new QComboBox(GameEditor);
        result->addItem(QString());
        result->addItem(QString());
        result->addItem(QString());
        result->setObjectName(QString::fromUtf8("result"));
        result->setFont(font);

        gridLayout->addWidget(result, 11, 1, 1, 3);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 3);

        change = new QPushButton(GameEditor);
        change->setObjectName(QString::fromUtf8("change"));
        change->setFont(font);

        gridLayout_2->addWidget(change, 3, 0, 1, 1);

        add = new QPushButton(GameEditor);
        add->setObjectName(QString::fromUtf8("add"));
        add->setFont(font);

        gridLayout_2->addWidget(add, 3, 1, 1, 1);

        label_12 = new QLabel(GameEditor);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout_2->addWidget(label_12, 1, 0, 1, 3);

        moveBack = new QPushButton(GameEditor);
        moveBack->setObjectName(QString::fromUtf8("moveBack"));
        moveBack->setFont(font);

        gridLayout_2->addWidget(moveBack, 0, 0, 1, 1);


        retranslateUi(GameEditor);

        QMetaObject::connectSlotsByName(GameEditor);
    } // setupUi

    void retranslateUi(QDialog *GameEditor)
    {
        GameEditor->setWindowTitle(QApplication::translate("GameEditor", "Dialog", nullptr));
        remove->setText(QApplication::translate("GameEditor", "Remove", nullptr));
        label_4->setText(QApplication::translate("GameEditor", "Second to add", nullptr));
        label_6->setText(QApplication::translate("GameEditor", "Sequence Length", nullptr));
        label_13->setText(QApplication::translate("GameEditor", "Tactics", nullptr));
        label->setText(QApplication::translate("GameEditor", "Platfom", nullptr));
        label_7->setText(QApplication::translate("GameEditor", "Link", nullptr));
        label_2->setText(QApplication::translate("GameEditor", "Date", nullptr));
        label_11->setText(QApplication::translate("GameEditor", "Start time", nullptr));
        label_10->setText(QApplication::translate("GameEditor", "Result", nullptr));
        label_5->setText(QApplication::translate("GameEditor", "Opening", nullptr));
        label_3->setText(QApplication::translate("GameEditor", "Move count", nullptr));
        label_8->setText(QApplication::translate("GameEditor", "Black", nullptr));
        tactics->setText(QApplication::translate("GameEditor", "ENTER NEW TACTICS...", nullptr));
        label_9->setText(QApplication::translate("GameEditor", "White", nullptr));
        result->setItemText(0, QApplication::translate("GameEditor", "white", nullptr));
        result->setItemText(1, QApplication::translate("GameEditor", "black", nullptr));
        result->setItemText(2, QApplication::translate("GameEditor", "draw", nullptr));

        change->setText(QApplication::translate("GameEditor", "Change", nullptr));
        add->setText(QApplication::translate("GameEditor", "Add", nullptr));
        label_12->setText(QApplication::translate("GameEditor", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Sequance Tactics Editor</span></p></body></html>", nullptr));
        moveBack->setText(QApplication::translate("GameEditor", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameEditor: public Ui_GameEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEEDITOR_H
