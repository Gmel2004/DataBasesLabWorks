/********************************************************************************
** Form generated from reading UI file 'chesstacticswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSTACTICSWINDOW_H
#define UI_CHESSTACTICSWINDOW_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessTactics
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *moveBack;
    QWidget *EditMenu;
    QVBoxLayout *layout;
    QPushButton *editGame;
    QPushButton *editUser;
    QTableWidget *table;
    QWidget *FiltresMenu;
    QGridLayout *layout_2;
    QLabel *label_4;
    QComboBox *platform;
    QDateEdit *startDate;
    QLabel *label_7;
    QLabel *label_5;
    QComboBox *opening;
    QLabel *label_3;
    QDateEdit *endDate;
    QComboBox *timeControl;
    QLabel *label_6;
    QComboBox *result;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushFilters;

    void setupUi(QDialog *ChessTactics)
    {
        if (ChessTactics->objectName().isEmpty())
            ChessTactics->setObjectName(QString::fromUtf8("ChessTactics"));
        ChessTactics->resize(1279, 756);
        gridLayout_2 = new QGridLayout(ChessTactics);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ChessTactics);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 3);

        moveBack = new QPushButton(ChessTactics);
        moveBack->setObjectName(QString::fromUtf8("moveBack"));
        QFont font;
        font.setPointSize(14);
        moveBack->setFont(font);

        gridLayout_2->addWidget(moveBack, 0, 0, 1, 1);

        EditMenu = new QWidget(ChessTactics);
        EditMenu->setObjectName(QString::fromUtf8("EditMenu"));
        layout = new QVBoxLayout(EditMenu);
        layout->setObjectName(QString::fromUtf8("layout"));
        editGame = new QPushButton(EditMenu);
        editGame->setObjectName(QString::fromUtf8("editGame"));
        editGame->setFont(font);

        layout->addWidget(editGame);

        editUser = new QPushButton(EditMenu);
        editUser->setObjectName(QString::fromUtf8("editUser"));
        editUser->setFont(font);

        layout->addWidget(editUser);


        gridLayout_2->addWidget(EditMenu, 0, 2, 1, 1);

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

        gridLayout_2->addWidget(table, 5, 0, 1, 3);

        FiltresMenu = new QWidget(ChessTactics);
        FiltresMenu->setObjectName(QString::fromUtf8("FiltresMenu"));
        layout_2 = new QGridLayout(FiltresMenu);
        layout_2->setObjectName(QString::fromUtf8("layout_2"));
        label_4 = new QLabel(FiltresMenu);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        layout_2->addWidget(label_4, 1, 0, 1, 1);

        platform = new QComboBox(FiltresMenu);
        platform->addItem(QString());
        platform->addItem(QString());
        platform->addItem(QString());
        platform->setObjectName(QString::fromUtf8("platform"));
        platform->setFont(font);

        layout_2->addWidget(platform, 0, 1, 1, 2);

        startDate = new QDateEdit(FiltresMenu);
        startDate->setObjectName(QString::fromUtf8("startDate"));
        startDate->setFont(font);

        layout_2->addWidget(startDate, 1, 1, 1, 1);

        label_7 = new QLabel(FiltresMenu);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        layout_2->addWidget(label_7, 4, 0, 1, 1);

        label_5 = new QLabel(FiltresMenu);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        layout_2->addWidget(label_5, 2, 0, 1, 1);

        opening = new QComboBox(FiltresMenu);
        opening->addItem(QString());
        opening->setObjectName(QString::fromUtf8("opening"));
        opening->setFont(font);

        layout_2->addWidget(opening, 3, 1, 1, 2);

        label_3 = new QLabel(FiltresMenu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        layout_2->addWidget(label_3, 0, 0, 1, 1);

        endDate = new QDateEdit(FiltresMenu);
        endDate->setObjectName(QString::fromUtf8("endDate"));
        endDate->setFont(font);

        layout_2->addWidget(endDate, 1, 2, 1, 1);

        timeControl = new QComboBox(FiltresMenu);
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->addItem(QString());
        timeControl->setObjectName(QString::fromUtf8("timeControl"));
        timeControl->setFont(font);

        layout_2->addWidget(timeControl, 2, 1, 1, 2);

        label_6 = new QLabel(FiltresMenu);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        layout_2->addWidget(label_6, 3, 0, 1, 1);

        result = new QComboBox(FiltresMenu);
        result->addItem(QString());
        result->addItem(QString());
        result->addItem(QString());
        result->addItem(QString());
        result->setObjectName(QString::fromUtf8("result"));
        result->setFont(font);

        layout_2->addWidget(result, 4, 1, 1, 2);


        gridLayout_2->addWidget(FiltresMenu, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushFilters = new QPushButton(ChessTactics);
        pushFilters->setObjectName(QString::fromUtf8("pushFilters"));
        pushFilters->setFont(font);
        pushFilters->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_2->addWidget(pushFilters, 1, 0, 1, 1);


        retranslateUi(ChessTactics);

        QMetaObject::connectSlotsByName(ChessTactics);
    } // setupUi

    void retranslateUi(QDialog *ChessTactics)
    {
        ChessTactics->setWindowTitle(QApplication::translate("ChessTactics", "Dialog", nullptr));
        label->setText(QApplication::translate("ChessTactics", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; font-style:italic;\">Chess Tactics</span></p></body></html>", nullptr));
        moveBack->setText(QApplication::translate("ChessTactics", "Back", nullptr));
        editGame->setText(QApplication::translate("ChessTactics", "Edit Sequance Tactics", nullptr));
        editUser->setText(QApplication::translate("ChessTactics", "Edit User", nullptr));
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
        label_4->setText(QApplication::translate("ChessTactics", "Start/End date", nullptr));
        platform->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));
        platform->setItemText(1, QApplication::translate("ChessTactics", "lichess.org", nullptr));
        platform->setItemText(2, QApplication::translate("ChessTactics", "chess.com", nullptr));

        label_7->setText(QApplication::translate("ChessTactics", "Result", nullptr));
        label_5->setText(QApplication::translate("ChessTactics", "Time Control", nullptr));
        opening->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));

        label_3->setText(QApplication::translate("ChessTactics", "Platform", nullptr));
        timeControl->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));
        timeControl->setItemText(1, QApplication::translate("ChessTactics", "bullet", nullptr));
        timeControl->setItemText(2, QApplication::translate("ChessTactics", "blitz", nullptr));
        timeControl->setItemText(3, QApplication::translate("ChessTactics", "rappid", nullptr));
        timeControl->setItemText(4, QApplication::translate("ChessTactics", "classic", nullptr));

        label_6->setText(QApplication::translate("ChessTactics", "Opening", nullptr));
        result->setItemText(0, QApplication::translate("ChessTactics", "all", nullptr));
        result->setItemText(1, QApplication::translate("ChessTactics", "white", nullptr));
        result->setItemText(2, QApplication::translate("ChessTactics", "black", nullptr));
        result->setItemText(3, QApplication::translate("ChessTactics", "draw", nullptr));

        pushFilters->setText(QApplication::translate("ChessTactics", "Filters\\/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessTactics: public Ui_ChessTactics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSTACTICSWINDOW_H
