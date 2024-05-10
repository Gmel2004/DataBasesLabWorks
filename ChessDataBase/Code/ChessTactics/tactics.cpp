#include "tactics.h"
#include "ui_tactics.h"

Tactics::Tactics(QString role, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tactics)
{
    ui->setupUi(this);
    if (role == "guest")
    {
        ui->EditMenu->close();
    }
    ui->FiltresMenu->hide();
    ui->startDate->setDate(QDate(800, 8, 8));
    ui->endDate->setDate(QDate::currentDate());
    ui->pushFilters->setFocus();
    connect(gameEditor, &GameEditor::edited, this, &Tactics::UpdateTable);
    connect(userEditor, &UserEditor::edited, this, &Tactics::UpdateTable);
}

Tactics::~Tactics()
{
    delete ui;
}

void Tactics::UpdateTable()
{
    qDebug("here");
}


void Tactics::on_moveBack_clicked()
{
    QWidget *entrance = new Entrance();
    entrance->show();
    close();
}


void Tactics::on_editGame_clicked()
{
    gameEditor->show();
}


void Tactics::on_editUser_clicked()
{
    userEditor->show();
}


void Tactics::on_platform_currentTextChanged(const QString &arg1)
{

}


void Tactics::on_startDate_userDateChanged(const QDate &date)
{

}


void Tactics::on_endDate_userDateChanged(const QDate &date)
{

}


void Tactics::on_timeControl_currentTextChanged(const QString &arg1)
{

}


void Tactics::on_opening_currentTextChanged(const QString &arg1)
{

}


void Tactics::on_result_currentTextChanged(const QString &arg1)
{

}


void Tactics::on_pushFilters_clicked()
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

