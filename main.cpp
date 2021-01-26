#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QString>
#include <QCoreApplication>
#include <QLabel>
#include <QDir>
#include <QWizard>
#include "Menu.h"
#include "Score.h"

Score *score = new Score();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // On set le nouveau repertoire ou l'on va executer Qt
    QDir::setCurrent("../mbti");

    // Creation de notre fenetre
    Menu menu;

    // Affichage de notre fenetre
    menu.show();

    return app.exec();
}
