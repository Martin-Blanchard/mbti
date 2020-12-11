#include "MaFenetre.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MaFenetre::MaFenetre() : QWidget()
{

    // Taille initiale de la fenetre pour que ce soit joli au lancement
    this->resize(1080,620);
    m_image = new QLabel();
    // On fait en sorte que l'image ne prenne pas toute la fenetre
    m_image->setPixmap(QPixmap("./images/titre.png"));
    m_image->setScaledContents(true);
    m_image->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    m_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // Creation des boutons
    m_bouton1 = new QPushButton("Commencer");
    m_bouton2 = new QPushButton("Scores");
    m_bouton3 = new QPushButton("Quitter");

    // Positionnement dans le layout
    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(m_image);
    m_layout->addWidget(m_bouton1);
    m_layout->addWidget(m_bouton2);
    m_layout->addWidget(m_bouton3);

    // Connexion du bouton "Quitter"
    QObject::connect(m_bouton3, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MaFenetre::~MaFenetre()
{
    delete m_image;
    delete m_bouton1;
    delete m_bouton2;
    delete m_bouton3;
    delete m_layout;

    m_image = 0;
    m_bouton1 = 0;
    m_bouton2 = 0;
    m_bouton3 = 0;
    m_layout = 0;
}
