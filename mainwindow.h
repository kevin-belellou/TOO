#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogcreation.h"
#include "Bibli/Bibliotheque.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    Bibliotheque::Bibliotheque bibli;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_boutonTri_clicked();
    void on_pushButton_clicked();
    void on_actionQuitter_triggered();
};

#endif // MAINWINDOW_H
