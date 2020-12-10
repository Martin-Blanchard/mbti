#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    public:
    MaFenetre();

    private:
    QLabel *m_image;
    QPushButton *m_bouton1;
    QPushButton *m_bouton2;
    QPushButton *m_bouton3;

};


#endif // MAFENETRE_H
