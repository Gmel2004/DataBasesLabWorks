#include "usereditor.h"
#include "ui_usereditor.h"

UserEditor::UserEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserEditor)
{
    ui->setupUi(this);
    tactics = (ChessTactics *)parent;
}

UserEditor::~UserEditor()
{
    delete ui;
}

void UserEditor::on_change_clicked()
{
    tactics->UpdateTable();
}


void UserEditor::on_add_clicked()
{
    tactics->UpdateTable();
}


void UserEditor::on_remove_clicked()
{
    tactics->UpdateTable();
}


void UserEditor::on_nickNameBox_currentTextChanged(const QString &arg1)
{

}


void UserEditor::on_platform_currentIndexChanged(const QString &arg1)
{

}

