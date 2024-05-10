/********************************************************************************
** Form generated from reading UI file 'entrance.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRANCE_H
#define UI_ENTRANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Entrance
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *logAsGuest;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *logAsAdmin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Entrance)
    {
        if (Entrance->objectName().isEmpty())
            Entrance->setObjectName(QString::fromUtf8("Entrance"));
        Entrance->resize(800, 600);
        centralwidget = new QWidget(Entrance);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(320, 160, 183, 187));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        logAsGuest = new QPushButton(widget);
        logAsGuest->setObjectName(QString::fromUtf8("logAsGuest"));
        QFont font;
        font.setPointSize(14);
        logAsGuest->setFont(font);

        gridLayout->addWidget(logAsGuest, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        logAsAdmin = new QPushButton(widget);
        logAsAdmin->setObjectName(QString::fromUtf8("logAsAdmin"));
        logAsAdmin->setFont(font);

        gridLayout->addWidget(logAsAdmin, 3, 0, 1, 1);

        Entrance->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Entrance);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Entrance->setMenuBar(menubar);
        statusbar = new QStatusBar(Entrance);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Entrance->setStatusBar(statusbar);

        retranslateUi(Entrance);

        QMetaObject::connectSlotsByName(Entrance);
    } // setupUi

    void retranslateUi(QMainWindow *Entrance)
    {
        Entrance->setWindowTitle(QApplication::translate("Entrance", "Entrance", nullptr));
        logAsGuest->setText(QApplication::translate("Entrance", "Log in as a guest", nullptr));
        label->setText(QApplication::translate("Entrance", "<html><head/><body><p align=\"center\">OR</p><p align=\"center\">enter password</p></body></html>", nullptr));
        logAsAdmin->setText(QApplication::translate("Entrance", "log in as a admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Entrance: public Ui_Entrance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRANCE_H
