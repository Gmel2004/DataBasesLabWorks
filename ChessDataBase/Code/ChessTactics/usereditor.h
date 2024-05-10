#ifndef USEREDITOR_H
#define USEREDITOR_H

#include <QDialog>
#include "chesstactics.h"

namespace Ui {
class UserEditor;
}

class UserEditor : public QDialog
{
    Q_OBJECT

public:
    explicit UserEditor(QWidget *parent = nullptr);
    ~UserEditor();

private slots:
    void on_change_clicked();

    void on_add_clicked();

    void on_remove_clicked();

    void on_nickNameBox_currentTextChanged(const QString &arg1);

    void on_platform_currentIndexChanged(const QString &arg1);

private:
    Ui::UserEditor *ui;
    ChessTactics* tactics = nullptr;
};

#endif // USEREDITOR_H
