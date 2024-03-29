#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    DialogCreation polo(this, &bibli);
    polo.show();
    polo.exec();
}

void MainWindow::on_boutonTri_clicked()
{
    bibli.tri(ui->choixTri->currentText().toStdString());
}
