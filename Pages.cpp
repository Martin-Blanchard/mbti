#include "Pages.h"
#include <QLabel>
#include <QRadioButton>
#include <QObject>

/* Constructeur d'une page sans argument donné
 * Non-utilisé dans le programme mais utile pour le futur peut-etre
 */
Pages::Pages()
{
    m_question = new QLabel();
    m_rep1 = new QRadioButton();
    m_rep2 = new QRadioButton();
    m_layout = new QVBoxLayout();

    m_layout->addWidget(m_question);
    m_layout->addWidget(m_rep1);
    m_layout->addWidget(m_rep2);

    this->setLayout(m_layout);
}

/* Constructeur des pages d'introduction des parties du test
 * Arguments : _introduction : ce que vous voulez afficher comme consigne (QString)
 * _a : numero de la partie (int)
 */
Pages::Pages(QString introduction,int a)
{
    // Declaration des widgets qui seront affiches
    m_question = new QLabel(introduction);
    m_layout = new QVBoxLayout();

    /* Declaration d'un bouton invisible (pour que le formulaire ne soit pas bloque a
    cause de la condition de validation (cf nv def de isComplete) */
    m_rep1 = new QRadioButton();

    // Gestion de l'affichage
    m_layout->addWidget(m_question);
    this->setLayout(m_layout);
    this->setTitle("Partie " + QString::number(a));

    // Gestion du bouton invisible
    m_rep1->setChecked(true);
    this->registerField("intro",m_rep1);
    QObject::connect(m_rep1,SIGNAL(toggled(bool)),this,SIGNAL(completeChanged()));
}

/* Constructeur des questions du formulaire
 * Arguments : _question : la question que vous voulez afficher (QString)
 * _rep1 : 1ere reponse (QString)
 * _rep2 : 2e reponse (QString)
 * _a : numero de la question (sert a ne pas dupliquer les fields)
 */
Pages::Pages(QString question, QString rep1, QString rep2, int a, char typeq, unsigned int score_type, unsigned int score_type_inv)
{
    // Definition des widgets qui seront affiches
    m_question = new QLabel(question);
    m_rep1 = new QRadioButton(rep1);
    m_rep2 = new QRadioButton(rep2);
    m_layout = new QVBoxLayout();

    // Definition des attributs de la question
    m_typeq = new char(typeq);
    m_score_r1 = new unsigned int(score_type);
    m_score_r2 = new unsigned int(score_type_inv);

    // Gestion de l'affichage par layout
    m_layout->addWidget(m_question);
    m_layout->addWidget(m_rep1);
    m_layout->addWidget(m_rep2);
    this->setLayout(m_layout);

    // Definition de l'obligation du choix de reponse pour continuer
    this->registerField("bouton"+QString::number(2*a)+"*",m_rep1);
    this->registerField("bouton"+QString::number(2*a+1)+"*",m_rep2);
    QObject::connect(m_rep1,SIGNAL(toggled(bool)),this,SIGNAL(completeChanged()));
    QObject::connect(m_rep2,SIGNAL(toggled(bool)),this,SIGNAL(completeChanged()));
}

bool Pages::isComplete() const
{
    return (m_rep1->isChecked() or m_rep2->isChecked());
}

bool Pages::button1Checked() const
{
    return m_rep1->isChecked();
}

char Pages::get_type() const
{
    return *m_typeq;
}

int Pages::get_score_input() const
{
    if(m_rep1->isChecked())
    {
        return *m_score_r1;
    }
    else
    {
        return *m_score_r2;
    }
}
