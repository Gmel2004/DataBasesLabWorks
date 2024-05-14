#include "entrance.h"
#include "ui_entrance.h"
#include <QDebug>

Entrance::Entrance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Entrance)
{
    ui->setupUi(this);
}

Entrance::~Entrance()
{
    delete ui;
}


void Entrance::on_logAsGuest_clicked()
{
    QWidget *chessTactics = new Tactics("guest");
    chessTactics->show();
    close();
}


void Entrance::on_logAsAdmin_clicked()
{
    if (ui->lineEdit->text() == "adminpas")
    {
        QWidget *chessTactics = new Tactics("admin");
        chessTactics->show();
        close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Wrong password!");
    }
}

