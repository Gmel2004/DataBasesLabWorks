/********************************************************************************
** Form generated from reading UI file 'UserEditor.ui'
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

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *nickName;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *lastName;
    QLabel *label;
    QLineEdit *name;
    QComboBox *country;
    QSpinBox *rating;
    QLabel *label_7;
    QComboBox *platform;
    QLabel *label_4;
    QComboBox *nickNameBox;
    QComboBox *rank;
    QPushButton *remove;
    QPushButton *add;
    QPushButton *change;
    QLabel *label_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(537, 382);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nickName = new QLineEdit(Dialog);
        nickName->setObjectName(QString::fromUtf8("nickName"));
        QFont font;
        font.setPointSize(14);
        nickName->setFont(font);

        gridLayout->addWidget(nickName, 0, 2, 1, 1);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lastName = new QLineEdit(Dialog);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setFont(font);

        gridLayout->addWidget(lastName, 3, 1, 1, 2);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        name = new QLineEdit(Dialog);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);

        gridLayout->addWidget(name, 2, 1, 1, 2);

        country = new QComboBox(Dialog);
        country->setObjectName(QString::fromUtf8("country"));
        country->setFont(font);

        gridLayout->addWidget(country, 5, 1, 1, 1);

        rating = new QSpinBox(Dialog);
        rating->setObjectName(QString::fromUtf8("rating"));
        rating->setFont(font);

        gridLayout->addWidget(rating, 6, 1, 1, 1);

        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        platform = new QComboBox(Dialog);
        platform->setObjectName(QString::fromUtf8("platform"));
        platform->setFont(font);

        gridLayout->addWidget(platform, 1, 1, 1, 1);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        nickNameBox = new QComboBox(Dialog);
        nickNameBox->setObjectName(QString::fromUtf8("nickNameBox"));
        nickNameBox->setFont(font);

        gridLayout->addWidget(nickNameBox, 0, 1, 1, 1);

        rank = new QComboBox(Dialog);
        rank->setObjectName(QString::fromUtf8("rank"));
        rank->setFont(font);

        gridLayout->addWidget(rank, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);

        remove = new QPushButton(Dialog);
        remove->setObjectName(QString::fromUtf8("remove"));

        gridLayout_2->addWidget(remove, 2, 2, 1, 1);

        add = new QPushButton(Dialog);
        add->setObjectName(QString::fromUtf8("add"));

        gridLayout_2->addWidget(add, 2, 1, 1, 1);

        change = new QPushButton(Dialog);
        change->setObjectName(QString::fromUtf8("change"));

        gridLayout_2->addWidget(change, 2, 0, 1, 1);

        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Rank", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Name", nullptr));
        label_6->setText(QApplication::translate("Dialog", "Country", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Platform", nullptr));
        label->setText(QApplication::translate("Dialog", "NickName", nullptr));
        label_7->setText(QApplication::translate("Dialog", "Current Rating", nullptr));
        label_4->setText(QApplication::translate("Dialog", "LastName", nullptr));
        remove->setText(QApplication::translate("Dialog", "Remove", nullptr));
        add->setText(QApplication::translate("Dialog", "Add", nullptr));
        change->setText(QApplication::translate("Dialog", "Change", nullptr));
        label_8->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Edit User</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEREDITOR_H
