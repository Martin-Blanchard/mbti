#include "MainWindow.h"
#include "Menu.h"
#include "Questionnaire.h"

#include <QWidget>

MainWindow::MainWindow()
{
    m_menu = new Menu();
    m_score = new Score();
    m_menu->show();

    QObject::connect(m_menu,SIGNAL(bouton_commencer()),this,SLOT(partie1()));
    QObject::connect(m_partie1,SIGNAL(partie_finie(int)),this,SLOT(partie_suivante(int)));
}

void MainWindow::partie1()
{
    m_partie1 = new Questionnaire(1);
    m_partie1->show();
}

void MainWindow::partie_finie(int a)
{
    switch(a)
    {
        case '1':
            delete m_partie1;
        break;
    }
}
