#include "gameeditor.h"
#include "ui_gameeditor.h"

GameEditor::GameEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameEditor)
{
    ui->setupUi(this);
}

GameEditor::~GameEditor()
{
    delete ui;
}


void GameEditor::on_tacticsBox_currentTextChanged(const QString &arg1)
{

}


void GameEditor::on_linkBox_currentTextChanged(const QString &arg1)
{

}


void GameEditor::on_change_clicked()
{
    emit edited();
}


void GameEditor::on_add_clicked()
{
    emit edited();
}


void GameEditor::on_remove_clicked()
{
    emit edited();
}
