#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{

    public:
    MaFenetre();
    ~MaFenetre();

    private:
    QLabel *m_image;
    QPushButton *m_bouton1;
    QPushButton *m_bouton2;
    QPushButton *m_bouton3;
    QVBoxLayout *m_layout;

};


#endif // MAFENETRE_H
