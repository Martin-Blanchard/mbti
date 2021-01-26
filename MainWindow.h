#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include "Questionnaire.h"
#include "Menu.h"
#include "Score.h"

class MainWindow : public QWidget
{

    Q_OBJECT

public:
    MainWindow();

public slots:
    void partie1();
    void partie_finie(int a);

private:
    Menu *m_menu;
    Questionnaire *m_partie1;
    Questionnaire *m_partie2;
    Questionnaire *m_partie3;
    Score *m_score;
};


#endif // MAINWINDOW_H
