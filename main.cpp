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
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // On set le nouveau repertoire ou l'on va executer Qt
    QDir::setCurrent("../mbti");

    // Creation de notre fenetre
    MainWindow main_window;

    // Affichage de notre fenetre
    //main_window.show();

    return app.exec();
}
