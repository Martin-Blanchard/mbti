#include "Questionnaire.h"
#include "Pages.h"
#include "Score.h"
#include <QLabel>
#include <QRadioButton>

extern Score *score;

Questionnaire::Questionnaire(int a)
{

    m_partie = new int(a);
    Pages *page_intro = new Pages("Pour chaque question, choisissez la manière d'agir qui vous correspond le mieux.\n \n" "Cliquez sur Next pour continuer.",a);
    this->addPage(page_intro);

    remplir_pages(a);

    for(int i = 0; i < 34; i++)
    {
        this->addPage(m_pages[i]);
    }
    QObject::connect(this->button(FinishButton),SIGNAL(pressed()),this,SLOT(finish()));

}

void Questionnaire::remplir_pages(int a)
{
    switch(a)
    {
        case 1:
            m_pages.push_back(new Pages("Est-il plutôt","facile de vous connaître","difficile de vous connaître",1,'e',1,-2));
            m_pages.push_back(new Pages("En accomplissant une tâche, avez-vous plutôt tendance à","commencer tôt de manière à pouvoir terminer en avance","travailler plus rapidement à la dernière minute",2,'j',0,-2));
            m_pages.push_back(new Pages("Vous trouvez","qu'il vous est facile de parler à pratiquement tout le monde aussi longtemps qu'il le faut","que vous n'avez beaucoup de choses à dire qu'à certaines personnes ou dans certaines situations",3,'e',2,-2));
            m_pages.push_back(new Pages("Préfériez-vous que l'on vous considère comme quelqu'un","de pratique","d'ingénieux",4,'n',-2,2));
            m_pages.push_back(new Pages("Si vous deviez collecter des fonds pour une association, ou des signatures pour une pétition, vos visites seraient","brèves et professionnelles","cordiales et amicales",5,'j',1,0));
            m_pages.push_back(new Pages("Êtes-vous généralement","sociable et ouvert","plutôt discret et réservé",6,'e',-2,2));
            m_pages.push_back(new Pages("Lorsqu'un évènement imprévu vous force à mettre de côté le programme de votre journée,","ce changement vous dérange","vous êtes heureux de cette diversion imprévue",7,'j',1,-1));
            m_pages.push_back(new Pages("Lorsque vous lisez pour votre plaisir,","vous aimez les façons inhabituelles et originales de présenter les choses","vous préférez les auteurs qui disent exactement ce qu'ils pensent",8,'n',1,-1));
            m_pages.push_back(new Pages("Est-ce un grand compliment d'être reconnu comme une personne","authentique","toujours raisonnable",9,'t',-1,2));
            m_pages.push_back(new Pages("Avez-vous tendance à entretenir","des relations amicales profondes avec peu de gens","des amitiés avec beaucoup de monde",10,'e',0,1));
            m_pages.push_back(new Pages("Vous suivez le plus souvent","votre coeur plutôt que votre tête","votre tête plutôt que votre coeur",11,'t',-1,1));
            m_pages.push_back(new Pages("Vous pouvez prolonger une conversation","seulement avec ceux qui ont les même goûts que vous","avec presque tout le monde",12,'e',-1,2));
            m_pages.push_back(new Pages("Suivre un programme est quelque chose qui","vous plaît","vous gêne",13,'j',2,-2));
            m_pages.push_back(new Pages("Lorsque vous commencez un grand projet qui doit être rendu dans une semaine","vous prenez le temps de faire une liste des différentes choses à réaliser et de l'ordre dans lequel elles doivent être effectuées","vous vous lancez immédiatement",14,'j',1,-2));
            m_pages.push_back(new Pages("Lorsque vous parlez à des amis","vous leur faites volontiers des confidences","vous leur confiez très rarement des choses que vous ne voudriez pas qu'ils répètent",15,'e',1,-1));
            m_pages.push_back(new Pages("Si vous êtiez enseignant, vous seriez plutôt du genre à faire un cours","basé sur les faits","comprenant de la théorie",16,'n',-2,2));
            m_pages.push_back(new Pages("Êtes-vous susceptible de faire","des éloges","des reproches",17,'t',0,1));
            m_pages.push_back(new Pages("En général","vous exprimez librement vos sentiments","vous gardez vos sentiments pour vous",18,'e',2,-1));
            m_pages.push_back(new Pages("Lorsque ce que vous devez faire est prévu depuis longtemps","vous appréciez de pouvoir vous organiser en conséquence","vous trouvez désagréable d'être ainsi lié",19,'j',1,-2));
            m_pages.push_back(new Pages("En général, vous vous entendez mieux avec","des personnes imaginatives","des personnes réalistes",20,'n',2,-2));
            m_pages.push_back(new Pages("Pensez-vous que c'est un plus gros défaut d'être","antipathique","déraisonnable",21,'t',-1,0));
            m_pages.push_back(new Pages("Lorsque des inconnus vous remarquent,","vous vous sentez mal à l'aise","cela ne vous dérange pas du tout",22,'e',-1,0));
            m_pages.push_back(new Pages("Si vous êtiez sur le point de faire quelque chose, à quel argument seriez-vous le plus sensible :","c'est ce que les gens attendent vraiment de vous","c'est ce qui vous semble le plus logique",23,'t',-1,0));
            m_pages.push_back(new Pages("Avez-vous l'habitude de","ne vous confier à personne, ou au plus une seule personne","vous confier à de nombreux amis",24,'e',0,1));
            m_pages.push_back(new Pages("Préférez-vous","organiser des rendez-vous et soirées à l'avance","garder la liberté de faire ce qui vous plaît le moment venu",25,'j',2,-2));
            m_pages.push_back(new Pages("Faire les choses à la dernière minute est plutôt","votre manière de faire normale","source de stress",26,'j',-2,2));
            m_pages.push_back(new Pages("Vous pensez que","tout ceux que vous aimez le savent","vous admirez certaines personnes depuis longtemps sans le leur avoir fait savoir",27,'e',0,-1));
            m_pages.push_back(new Pages("Lorsque vous faites quelque chose que de nombreux autres font aussi, vous préférez","le faire d'une manière reconnue","inventer votre manière à vous",28,'n',-2,1));
            m_pages.push_back(new Pages("Selon vous, le plus gros défaut est","d'avoir trop de sentiments","de ne pas en avoir assez",29,'t',1,0));
            m_pages.push_back(new Pages("Lorsque vous êtes dans un groupe, vous préférez généralement","participer à la discussion du groupe","parler à une personne à la fois",30,'e',1,-2));
            m_pages.push_back(new Pages("Vous pensez qu'établir un programme pour les activités quotidiennes est","une manière agréable de réaliser ces activités","quelque chose de désagréable même quand c'est nécessaire",31,'j',1,-2));
            m_pages.push_back(new Pages("Vous préférez avoir un style de vie","original","classique",32,'n',1,-2));
            m_pages.push_back(new Pages("Vous pensez qu'il est plus gênant d'être","trop chaleureux","pas assez chaleureux",33,'t',1,0));
            m_pages.push_back(new Pages("Parmi vos amis, vous êtes","un des derniers à apprendre ce qui se passe","toujours au courant de tout sur tout le monde",34,'e',-2,2));
            m_pages.push_back(new Pages("En général, le sentiment a pour vous","plus de valeur que la logique","moins de valeur que la logique",35,'t',-2,2));
            m_pages.push_back(new Pages("Lors de réunions amicales","vous essayez plutôt de prendre à part quelqu'un à qui vous souhaitez parler","vous socialisez avec l'ensemble du groupe",36,'e',2,-1));
            m_pages.push_back(new Pages("Lorsque vous avez un travail particulier à accomplir, vous préférez","l'organiser avec soin avant de commencer","découvrir ce qui est nécessaire au fur et à mesure",37,'j',2,-2));
            m_pages.push_back(new Pages("Seriez-vous plus à l'aise si","les procédures vous venaient plus naturellement","la varieté vous venait plus naturellement",38,'j',-1,1));
            m_pages.push_back(new Pages("Dans les soirées","il vous arrive souvent de vous ennuyer","vous vous amusez presque tout le temps",39,'n',-2,1));
            m_pages.push_back(new Pages("Lorsque vous terminez quelque chose dans votre vie personnelle,","vous savez déjà ce que vous allez faire ensuite et vous êtes prêt à vous y mettre","vous êtes content de vous relaxer en attendant l'inspiration suivante",40,'t',2,-2));
        break;
    }
}

void Questionnaire::finish()
{
    switch(*m_partie)
        {
        case 1:
            /*QWidget *fenetre = new QWidget();
            fenetre->show();
            close();*/
            for(int i = 0; i < 4; i++)
            {
                score->ajout_score(m_pages[i]->get_type(),m_pages[i]->get_score_input());
            }
            QWidget *fenetre = new QWidget();
            fenetre->setWindowTitle(QString::number(score->get_score('i')));
            //fenetre->setWindowTitle(QString::number(m_pages[2]->get_score_input()));
            fenetre->show();
            close();
        }
}
