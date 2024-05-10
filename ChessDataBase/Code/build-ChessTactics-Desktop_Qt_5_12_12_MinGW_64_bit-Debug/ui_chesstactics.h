/********************************************************************************
** Form generated from reading UI file 'chesstactics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSTACTICS_H
#define UI_CHESSTACTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChessTactics
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *EditMenu;
    QPushButton *editGame;
    QPushButton *editUser;
    QLabel *label;
    QGridLayout *FiltresMenu;
    QLabel *label_4;
    QDateEdit *startDate;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *endDate;
    QComboBox *platform;
    QComboBox *timeControl;
    QComboBox *opening;
    QComboBox *result;
    QSpacerItem *horizontalSpacer;
    QPushButton *moveBack;
    QLabel *label_2;
    QPushButton *pushFilters;
    QTableWidget *table;

    void setupUi(QDialog *ChessTactics)
    {
        if (ChessTactics->objectName().isEmpty())
            ChessTactics->setObjectName(QString::fromUtf8("ChessTactics"));
        ChessTactics->resize(1274, 756);
        gridLayout_2 = new QGridLayout(ChessTactics);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        EditMenu = new QVBoxLayout();
        EditMenu->setObjectName(QString::fromUtf8("EditMenu"));
        editGame = new QPushButton(ChessTactics);
        editGame->setObjectName(QString::fromUtf8("editGame"));
        QFont font;
        font.setPointSize(14);
        editGame->setFont(font);

        EditMenu->addWidget(editGame);

        editUser = new QPushButton(ChessTactics);
        editUser->setObjectName(QString::fromUtf8("editUser"));
        editUser->setFont(font);

        EditMenu->addWidget(editUser);


        gridLayout_2->addLayout(EditMenu, 0, 3, 1, 1);

        label = new QLabel(ChessTactics);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 5, 0, 1, 4);

        FiltresMenu = new QGridLayout();
        FiltresMenu->setObjectName(QString::fromUtf8("FiltresMenu"));
        label_4 = new QLabel(ChessTactics);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        FiltresMenu->addWidget(label_4, 1, 0, 1, 1);

        startDate = new QDateEdit(ChessTactics);
        startDate->setObjectName(QString::fromUtf8("startDate"));
        startDate->setFont(font);

        FiltresMenu->addWidget(startDate, 1, 1, 1, 1);

        label_7 = new QLabel(ChessTactics);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        FiltresMenu->addWidget(label_7, 4, 0, 1, 1);

        label_3 = new QLabel(ChessTactics);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        FiltresMenu->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(ChessTactics);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        FiltresMenu->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(ChessTactics);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        FiltresMenu->addWidget(label_6, 3, 0, 1, 1);

        endDate = new QDateEdit(ChessTactics);
        endDate->setObjectName(QString::fromUtf8("endDate"));
        endDate->setFont(font);

        FiltresMenu->addWidget(endDate, 1, 2, 1, 1);

        platform = new QComboBox(ChessTactics);
        platform->addItem(QString());
        platform->addItem(QString());
        platform->addItem(QString());
        platform->setObjectName(QString::fromUtf8("platform"));
        platform->setFont(font);

        FiltresMenu->addWidget(platform, 0, 1, 1, 2);

        timeControl = new QComboBox(ChessTactics);
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->setObjectName(QString::fromUtf8("timeControl"));
        timeControl->setFont(font);

        FiltresMenu->addWidget(timeControl, 2, 1, 1, 2);

        opening = new QComboBox(ChessTactics);
        opening->addItem(QString());
        opening->setObjectName(QString::fromUtf8("opening"));
        opening->setFont(font);

        FiltresMenu->addWidget(opening, 3, 1, 1, 2);

        result = new QComboBox(ChessTactics);
        result->addItem(QString());
        result->addItem(QString());
        result->addItem(QString());
        result->addItem(QString());
        result->setObjectName(QString::fromUtf8("result"));
        result->setFont(font);

        FiltresMenu->addWidget(result, 4, 1, 1, 2);


        gridLayout_2->addLayout(FiltresMenu, 3, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        moveBack = new QPushButton(ChessTactics);
        moveBack->setObjectName(QString::fromUtf8("moveBack"));
        moveBack->setFont(font);

        gridLayout_2->addWidget(moveBack, 0, 0, 1, 1);

        label_2 = new QLabel(ChessTactics);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 2);

        pushFilters = new QPushButton(ChessTactics);
        pushFilters->setObjectName(QString::fromUtf8("pushFilters"));
        pushFilters->setFont(font);

        gridLayout_2->addWidget(pushFilters, 1, 0, 1, 1);

        table = new QTableWidget(ChessTactics);
        if (table->columnCount() < 10)
            table->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        table->setObjectName(QString::fromUtf8("table"));
        table->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));

        gridLayout_2->addWidget(table, 6, 0, 1, 4);


        retranslateUi(ChessTactics);

        QMetaObject::connectSlotsByName(ChessTactics);
    } // setupUi

    void retranslateUi(QDialog *ChessTactics)
    {
        ChessTactics->setWindowTitle(QApplication::translate("ChessTactics", "Dialog", nullptr));
        editGame->setText(QApplication::translate("ChessTactics", "Edit Sequance Tactics", nullptr));
        editUser->setText(QApplication::translate("ChessTactics", "Edit User", nullptr));
        label->setText(QApplication::translate("ChessTactics", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; font-style:italic;\">Chess Tactics</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("ChessTactics", "Start/End date", nullptr));
        label_7->setText(QApplication::translate("ChessTactics", "Result", nullptr));
        label_3->setText(QApplication::translate("ChessTactics", "Platform", nullptr));
        label_5->setText(QApplication::translate("ChessTactics", "Time Control", nullptr));
        label_6->setText(QApplication::translate("ChessTactics", "Opening", nullptr));
        platform->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));
        platform->setItemText(1, QApplication::translate("ChessTactics", "lichess.org", nullptr));
        platform->setItemText(2, QApplication::translate("ChessTactics", "chess.com", nullptr));

        timeControl->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));
        timeControl->setItemText(1, QApplication::translate("ChessTactics", "bullet", nullptr));
        timeControl->setItemText(2, QApplication::translate("ChessTactics", "blitz", nullptr));
        timeControl->setItemText(3, QApplication::translate("ChessTactics", "rappid", nullptr));
        timeControl->setItemText(4, QApplication::translate("ChessTactics", "classic", nullptr));

        opening->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));

        result->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));
        result->setItemText(1, QApplication::translate("ChessTactics", "white", nullptr));
        result->setItemText(2, QApplication::translate("ChessTactics", "black", nullptr));
        result->setItemText(3, QApplication::translate("ChessTactics", "draw", nullptr));

        moveBack->setText(QApplication::translate("ChessTactics", "Back", nullptr));
        label_2->setText(QString());
        pushFilters->setText(QApplication::translate("ChessTactics", "Filters\\/", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ChessTactics", "Platform", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ChessTactics", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ChessTactics", "MoveCount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ChessTactics", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ChessTactics", "Opening", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ChessTactics", "Tactics", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ChessTactics", "SequanceLength", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ChessTactics", "Link", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ChessTactics", "Black", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ChessTactics", "ChessPlayers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessTactics: public Ui_ChessTactics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSTACTICS_H
