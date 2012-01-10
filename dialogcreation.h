#ifndef DIALOGCREATION_H
#define DIALOGCREATION_H

#include <QDialog>
#include "Bibli/Bibliotheque.h"

namespace Ui {
    class DialogCreation;
}

class DialogCreation : public QDialog {
    Q_OBJECT
public:    
    DialogCreation(QWidget *parent = 0, Bibliotheque::Bibliotheque *bibli = NULL);
    ~DialogCreation();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogCreation *ui;
    Bibliotheque::Bibliotheque *bibliModif;

private slots:
    void on_buttonBox_accepted();
    void on_VType_currentIndexChanged(QString type);
};

#endif // DIALOGCREATION_H
