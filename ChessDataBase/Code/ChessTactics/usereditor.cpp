#include "usereditor.h"
#include "ui_usereditor.h"

UserEditor::UserEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserEditor)
{
    ui->setupUi(this);
}

UserEditor::~UserEditor()
{
    delete ui;
}

void UserEditor::on_change_clicked()
{
    emit edited();
}


void UserEditor::on_add_clicked()
{
    emit edited();
}


void UserEditor::on_remove_clicked()
{
    emit edited();
}


void UserEditor::on_nickNameBox_currentTextChanged(const QString &arg1)
{

}


void UserEditor::on_platform_currentIndexChanged(const QString &arg1)
{

}

