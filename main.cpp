#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QString>
#include <QCoreApplication>
#include <QLabel>
#include <QDir>
#include "MaFenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // On set le nouveau repertoire ou l'on va executer Qt
    QDir::setCurrent("../mbti");

    // Creation de notre fenetre
    MaFenetre fenetre;

    // Affichage de notre fenetre
    fenetre.show();

    return app.exec();
}
