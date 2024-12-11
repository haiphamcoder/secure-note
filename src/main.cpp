#include <QApplication>
#include "note_app.h"
// #include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // QMainWindow mainWindow;
    // mainWindow.setWindowTitle("Secure Note");
    // mainWindow.resize(800, 600);
    // mainWindow.show();

    NoteApp noteApp;
    noteApp.show();


    return app.exec();
}