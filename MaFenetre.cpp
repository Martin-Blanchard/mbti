#include "MaFenetre.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MaFenetre::MaFenetre() : QWidget()
{

    m_image = new QLabel();
    // On fait en sorte que l'image ne prenne pas toute la fenetre
    const int w = m_image->width();
    const int h = m_image->height();
    m_image->setPixmap(QPixmap("./images/titre.png").scaled(h,w,Qt::KeepAspectRatio));
    m_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // Creation des boutons
    m_bouton1 = new QPushButton("Commencer");
    m_bouton2 = new QPushButton("Scores");
    m_bouton3 = new QPushButton("Quitter");

    // Positionnement dans le layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_image);
    layout->addWidget(m_bouton1);
    layout->addWidget(m_bouton2);
    layout->addWidget(m_bouton3);

}

void MaFenetre::resizeEvent(QResizeEvent *e)
{
    const int w = m_image->width();
    const int h = m_image->height();
    m_image->setPixmap(QPixmap("./images/titre.png").scaled(h,w,Qt::KeepAspectRatio));
    m_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}
