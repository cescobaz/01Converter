#include <iostream>
#include <QApplication>
#include <Presentation/MainWindow.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}