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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Entrance
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *logAsGuest;
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
        widget->setGeometry(QRect(230, 220, 284, 83));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        logAsGuest = new QPushButton(widget);
        logAsGuest->setObjectName(QString::fromUtf8("logAsGuest"));
        QFont font;
        font.setPointSize(14);
        logAsGuest->setFont(font);

        verticalLayout->addWidget(logAsGuest);

        logAsAdmin = new QPushButton(widget);
        logAsAdmin->setObjectName(QString::fromUtf8("logAsAdmin"));
        logAsAdmin->setFont(font);

        verticalLayout->addWidget(logAsAdmin);

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
        logAsAdmin->setText(QApplication::translate("Entrance", "log in as a admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Entrance: public Ui_Entrance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRANCE_H
