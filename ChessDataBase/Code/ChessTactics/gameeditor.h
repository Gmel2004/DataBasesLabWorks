#ifndef GAMEEDITOR_H
#define GAMEEDITOR_H

#include <QDialog>

namespace Ui {
class GameEditor;
}

class GameEditor : public QDialog
{
    Q_OBJECT

public:
    explicit GameEditor(QWidget *parent = nullptr);
    ~GameEditor();

private slots:
    void on_tacticsBox_currentTextChanged(const QString &arg1);

    void on_linkBox_currentTextChanged(const QString &arg1);

    void on_change_clicked();

    void on_add_clicked();

    void on_remove_clicked();

    void on_moveBack_clicked();

private:
    Ui::GameEditor *ui;
};

#endif // GAMEEDITOR_H
