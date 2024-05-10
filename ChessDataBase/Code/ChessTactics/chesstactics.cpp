#include "chesstactics.h"
#include "ui_chesstactics.h"

ChessTactics::ChessTactics(QString role, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessTactics)
{
    ui->setupUi(this);
    if (role == "guest")
    {
        ui->editGame->hide();
        ui->editUser->hide();
    }
}

ChessTactics::~ChessTactics()
{
    delete ui;
}

void ChessTactics::UpdateTable()
{

}

void ChessTactics::on_moveBack_clicked()
{
    QWidget *entrance = new Entrance();
    entrance->show();
    close();
}


void ChessTactics::on_editGame_clicked()
{
    gameEditor->show();
}


void ChessTactics::on_editUser_clicked()
{
    userEditor->show();
}


void ChessTactics::on_platform_currentTextChanged(const QString &arg1)
{

}


void ChessTactics::on_startDate_userDateChanged(const QDate &date)
{

}


void ChessTactics::on_endDate_userDateChanged(const QDate &date)
{

}


void ChessTactics::on_timeControl_currentTextChanged(const QString &arg1)
{

}


void ChessTactics::on_opening_currentTextChanged(const QString &arg1)
{

}


void ChessTactics::on_result_currentTextChanged(const QString &arg1)
{

}


void ChessTactics::on_pushFilters_clicked()
{

}

