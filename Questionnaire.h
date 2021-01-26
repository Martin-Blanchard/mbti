#ifndef FENETRETRANSITION_H
#define FENETRETRANSITION_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWizard>
#include <vector>
#include "Pages.h"

class Questionnaire : public QWizard
{
    Q_OBJECT

    public:
    Questionnaire(int a);
    void remplir_pages(int a);
    //Questionnaire();

public slots:
    void finish();

signals:
    void partie_finie(int);

    private:
    std::vector<Pages*> m_pages;
    int *m_partie;


};

#endif // FENETRETRANSITION_H
