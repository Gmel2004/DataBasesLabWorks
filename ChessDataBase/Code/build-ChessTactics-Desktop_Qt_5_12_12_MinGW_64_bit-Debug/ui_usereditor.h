/********************************************************************************
** Form generated from reading UI file 'usereditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEREDITOR_H
#define UI_USEREDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_UserEditor
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *change;
    QPushButton *remove;
    QPushButton *add;
    QLabel *label_8;
    QGridLayout *gridLayout;
    QLineEdit *nickName;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *lastName;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_7;
    QLabel *label_4;
    QComboBox *nickNameBox;
    QComboBox *platform;
    QComboBox *rank;
    QComboBox *country;
    QSpinBox *rating;
    QPushButton *moveBack;

    void setupUi(QDialog *UserEditor)
    {
        if (UserEditor->objectName().isEmpty())
            UserEditor->setObjectName(QString::fromUtf8("UserEditor"));
        UserEditor->resize(502, 382);
        gridLayout_2 = new QGridLayout(UserEditor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        change = new QPushButton(UserEditor);
        change->setObjectName(QString::fromUtf8("change"));
        QFont font;
        font.setPointSize(14);
        change->setFont(font);

        gridLayout_2->addWidget(change, 3, 0, 1, 1);

        remove = new QPushButton(UserEditor);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setFont(font);

        gridLayout_2->addWidget(remove, 3, 2, 1, 1);

        add = new QPushButton(UserEditor);
        add->setObjectName(QString::fromUtf8("add"));
        add->setFont(font);

        gridLayout_2->addWidget(add, 3, 1, 1, 1);

        label_8 = new QLabel(UserEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 1, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nickName = new QLineEdit(UserEditor);
        nickName->setObjectName(QString::fromUtf8("nickName"));
        nickName->setFont(font);

        gridLayout->addWidget(nickName, 0, 2, 1, 1);

        label_5 = new QLabel(UserEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(UserEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(UserEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(UserEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lastName = new QLineEdit(UserEditor);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setFont(font);

        gridLayout->addWidget(lastName, 3, 1, 1, 2);

        label = new QLabel(UserEditor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        name = new QLineEdit(UserEditor);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);

        gridLayout->addWidget(name, 2, 1, 1, 2);

        label_7 = new QLabel(UserEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_4 = new QLabel(UserEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        nickNameBox = new QComboBox(UserEditor);
        nickNameBox->addItem(QString());
        nickNameBox->setObjectName(QString::fromUtf8("nickNameBox"));
        nickNameBox->setFont(font);

        gridLayout->addWidget(nickNameBox, 0, 1, 1, 1);

        platform = new QComboBox(UserEditor);
        platform->addItem(QString());
        platform->addItem(QString());
        platform->setObjectName(QString::fromUtf8("platform"));
        platform->setFont(font);

        gridLayout->addWidget(platform, 1, 1, 1, 2);

        rank = new QComboBox(UserEditor);
        rank->addItem(QString());
        rank->addItem(QString());
        rank->addItem(QString());
        rank->addItem(QString());
        rank->addItem(QString());
        rank->setObjectName(QString::fromUtf8("rank"));
        rank->setFont(font);

        gridLayout->addWidget(rank, 4, 1, 1, 2);

        country = new QComboBox(UserEditor);
        country->addItem(QString());
        country->setObjectName(QString::fromUtf8("country"));
        country->setFont(font);

        gridLayout->addWidget(country, 5, 1, 1, 2);

        rating = new QSpinBox(UserEditor);
        rating->setObjectName(QString::fromUtf8("rating"));
        rating->setFont(font);

        gridLayout->addWidget(rating, 6, 1, 1, 2);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 3);

        moveBack = new QPushButton(UserEditor);
        moveBack->setObjectName(QString::fromUtf8("moveBack"));
        moveBack->setFont(font);

        gridLayout_2->addWidget(moveBack, 0, 0, 1, 1);


        retranslateUi(UserEditor);

        QMetaObject::connectSlotsByName(UserEditor);
    } // setupUi

    void retranslateUi(QDialog *UserEditor)
    {
        UserEditor->setWindowTitle(QApplication::translate("UserEditor", "Dialog", nullptr));
        change->setText(QApplication::translate("UserEditor", "Change", nullptr));
        remove->setText(QApplication::translate("UserEditor", "Remove", nullptr));
        add->setText(QApplication::translate("UserEditor", "Add", nullptr));
        label_8->setText(QApplication::translate("UserEditor", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Edit User</span></p></body></html>", nullptr));
        nickName->setText(QApplication::translate("UserEditor", "NEW USER...", nullptr));
        label_5->setText(QApplication::translate("UserEditor", "Rank", nullptr));
        label_3->setText(QApplication::translate("UserEditor", "Name", nullptr));
        label_6->setText(QApplication::translate("UserEditor", "Country", nullptr));
        label_2->setText(QApplication::translate("UserEditor", "Platform", nullptr));
        label->setText(QApplication::translate("UserEditor", "NickName", nullptr));
        label_7->setText(QApplication::translate("UserEditor", "Current Rating", nullptr));
        label_4->setText(QApplication::translate("UserEditor", "LastName", nullptr));
        nickNameBox->setItemText(0, QApplication::translate("UserEditor", "none", nullptr));

        platform->setItemText(0, QApplication::translate("UserEditor", "lichess.org", nullptr));
        platform->setItemText(1, QApplication::translate("UserEditor", "chess.com", nullptr));

        rank->setItemText(0, QApplication::translate("UserEditor", "none", nullptr));
        rank->setItemText(1, QApplication::translate("UserEditor", "CM", nullptr));
        rank->setItemText(2, QApplication::translate("UserEditor", "FM", nullptr));
        rank->setItemText(3, QApplication::translate("UserEditor", "IM", nullptr));
        rank->setItemText(4, QApplication::translate("UserEditor", "GM", nullptr));

        country->setItemText(0, QApplication::translate("UserEditor", "none", nullptr));

        moveBack->setText(QApplication::translate("UserEditor", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserEditor: public Ui_UserEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEREDITOR_H
