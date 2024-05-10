#ifndef TACTICS_H
#define TACTICS_H

#include <QDialog>
#include "entrance.h"
#include "usereditor.h"
#include "gameeditor.h"

namespace Ui {
class Tactics;
}

class Tactics : public QDialog
{
    Q_OBJECT

public:
    explicit Tactics(QString role, QWidget *parent = nullptr);
    ~Tactics();

private slots:
    void UpdateTable();

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
    Ui::Tactics *ui;
    UserEditor *userEditor = new UserEditor(this);
    GameEditor *gameEditor = new GameEditor(this);
};

#endif // TACTICS_H
