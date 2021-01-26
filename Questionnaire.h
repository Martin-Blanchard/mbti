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

class Questionnaire : public QWizard // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    Questionnaire(int a);
    void remplir_pages(int a);
    //~Questionnaire();

public slots:
    void finish();

    private:
    std::vector<Pages*> m_pages;
    int *m_partie;


};

#endif // FENETRETRANSITION_H
