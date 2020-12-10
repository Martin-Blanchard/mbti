#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QString>
#include <QCoreApplication>
#include <QLabel>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;

    QLabel *image1 = new QLabel();

    // On set le nouveau repertoire ou l'on va executer Qt
    QDir::setCurrent("../mbti");

    // Cette QString contient le chemin pour obtenir le repertoire courant de Qt (utilise lors de tests)
    // QString *dossier = new QString(QDir::currentPath());

    // On fait en sorte que l'image ne prenne pas toute la fenetre
    const int w = image1->width();
    const int h = image1->height();
    image1->setPixmap(QPixmap("./images/titre.png").scaled(h,w,Qt::KeepAspectRatio));

    QPushButton *bouton1 = new QPushButton("Commencer");
    QPushButton *bouton2 = new QPushButton("Scores");
    QPushButton *bouton3 = new QPushButton("Quitter");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(image1);
    layout->addWidget(bouton1);
    layout->addWidget(bouton2);
    layout->addWidget(bouton3);

    fenetre.setLayout(layout);

    fenetre.show();

    return app.exec();
}
