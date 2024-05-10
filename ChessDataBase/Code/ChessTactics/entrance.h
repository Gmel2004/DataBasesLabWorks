#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <QMainWindow>
#include "tactics.h"
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Entrance; }
QT_END_NAMESPACE

class Entrance : public QMainWindow
{
    Q_OBJECT

public:
    Entrance(QWidget *parent = nullptr);
    ~Entrance();

private slots:
    void on_logAsGuest_clicked();

    void on_logAsAdmin_clicked();

private:
    Ui::Entrance *ui;
};
#endif // ENTRANCE_H
