#include "note_app.h"

#include <QMenuBar>
#include <QStatusBar>

NoteApp::NoteApp(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Secure Note App");
    resize(800, 600);

    // Menu bar example
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = menuBar->addMenu("File");
    QAction *exitAction = fileMenu->addAction("Exit");
    connect(exitAction, &QAction::triggered, this, &NoteApp::close);

    // Status bar example
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    statusBar->showMessage("Welcome to Secure Note App", 5000);
}

NoteApp::~NoteApp() {
    // Destructor implementation
}