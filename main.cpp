#include "testqt.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestQT w;
    w.show();
    return a.exec();
}
