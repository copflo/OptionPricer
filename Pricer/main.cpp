#include <QApplication>

#include "../View/optionwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OptionWindow w;
    w.show();
    return a.exec();
}
