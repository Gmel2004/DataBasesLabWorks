#include "chesstactics.h"
#include "ui_chesstactics.h"

ChessTactics::ChessTactics(QString role, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessTactics)
{
    ui->setupUi(this);
    if (role == "guest")
    {
        ui->EditMenu->close();
    }
    ui->FiltresMenu->hide();
    ui->startDate->setDate(QDate(800, 8, 8));
    ui->endDate->setDate(QDate::currentDate());
    ui->FiltresMenu->setFocus();
}

ChessTactics::~ChessTactics()
{
    delete ui;
}

void ChessTactics::UpdateTable()
{
    qDebug("here");
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
    if (ui->FiltresMenu->isHidden())
    {
        ui->FiltresMenu->show();
        ui->pushFilters->setText("Filters/\\");
    }
    else
    {
        ui->FiltresMenu->hide();
        ui->pushFilters->setText("Filters\\/");
    }
}

