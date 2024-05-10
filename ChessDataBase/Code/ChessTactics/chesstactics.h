#ifndef CHESSTACTICS_H
#define CHESSTACTICS_H

#include <QDialog>
#include <entrance.h>
#include <usereditor.h>
#include <gameeditor.h>

namespace Ui {
class ChessTactics;
}

class ChessTactics : public QDialog
{
    Q_OBJECT

public:
    explicit ChessTactics(QString role, QWidget *parent = nullptr);
    ~ChessTactics();
    void UpdateTable();

private slots:
    void on_moveBack_clicked();

    void on_editGame_clicked();

    void on_editUser_clicked();

    void on_platform_currentTextChanged(const QString &arg1);

    void on_startDate_userDateChanged(const QDate &date);

    void on_endDate_userDateChanged(const QDate &date);

    void on_timeControl_currentTextChanged(const QString &arg1);

    void on_opening_currentTextChanged(const QString &arg1);

    void on_result_currentTextChanged(const QString &arg1);

    void on_pushFilters_clicked();

private:
    Ui::ChessTactics *ui;
    QWidget *userEditor = new UserEditor(this);
    QWidget *gameEditor = new GameEditor(this);
};

#endif // CHESSTACTICS_H
