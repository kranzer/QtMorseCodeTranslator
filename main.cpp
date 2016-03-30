#include "qtmorsecodetranslator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtMorseCodeTranslator w;
    w.show();

    return a.exec();
}
