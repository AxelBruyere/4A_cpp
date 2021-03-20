#include <QApplication>
#include "window.hpp"
#include "board.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    window fenetre;
    fenetre.show();

    return app.exec();
}
