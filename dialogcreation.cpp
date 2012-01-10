#include "dialogcreation.h"
#include "ui_dialogcreation.h"

DialogCreation::DialogCreation(QWidget *parent, Bibliotheque::Bibliotheque *bibli) :
    QDialog(parent),
    ui(new Ui::DialogCreation)
{
    ui->setupUi(this);
    ui->LTypeRoman->hide();
    ui->VTypeRoman->hide();
    ui->LDessinateur->hide();
    ui->VDessinateur->hide();
    this->bibliModif = bibli;
}

DialogCreation::~DialogCreation()
{
    delete ui;
}

void DialogCreation::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DialogCreation::on_VType_currentIndexChanged(QString type)
{
    if (type == "Livre")
    {
        ui->LTypeRoman->hide();
        ui->VTypeRoman->hide();
        ui->LDessinateur->hide();
        ui->VDessinateur->hide();
    }
    else if (type == "Roman")
    {
        ui->LTypeRoman->show();
        ui->VTypeRoman->show();
        ui->LDessinateur->hide();
        ui->VDessinateur->hide();
    }
    else
    {
        ui->LTypeRoman->hide();
        ui->VTypeRoman->hide();
        ui->LDessinateur->show();
        ui->VDessinateur->show();
    }
}

void DialogCreation::on_buttonBox_accepted()
{
    if (ui->VType->currentText() == "Livre")
    {
        Livre::Livre tmp(ui->VTitre->text().toStdString(), ui->VAuteur->text().toStdString(), ui->VEditeur->text().toStdString());
        this->bibliModif->ajouter(&tmp);
    }
    else if (ui->VType->currentText() == "Roman")
    {
        Roman::Roman tmp(ui->VTitre->text().toStdString(), ui->VAuteur->text().toStdString(), ui->VEditeur->text().toStdString(), ui->VTypeRoman->text().toStdString());
        this->bibliModif->ajouter(&tmp);
    }
    else
    {
        BD::BD tmp(ui->VTitre->text().toStdString(), ui->VAuteur->text().toStdString(), ui->VEditeur->text().toStdString(), ui->VDessinateur->text().toStdString());
        this->bibliModif->ajouter(&tmp);
    }
}
