#ifndef MENU_H
#define MENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class Menu : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    Menu();
    ~Menu();

public slots:
    void commencer();

    private:
    QLabel *m_image;
    QPushButton *m_bouton1;
    QPushButton *m_bouton2;
    QPushButton *m_bouton3;
    QVBoxLayout *m_layout;

};


#endif // MENU_H
