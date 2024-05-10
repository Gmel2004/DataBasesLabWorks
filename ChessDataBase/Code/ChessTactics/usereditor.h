#ifndef USEREDITOR_H
#define USEREDITOR_H

#include <QDialog>

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

    void on_moveBack_clicked();

private:
    Ui::UserEditor *ui;
};

#endif // USEREDITOR_H
