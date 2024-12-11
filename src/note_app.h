#ifndef NOTE_APP_H
#define NOTE_APP_H

#include <QMainWindow>

class NoteApp : public QMainWindow {
    Q_OBJECT

public:
    explicit NoteApp(QWidget *parent = nullptr);
    ~NoteApp() override;
};

#endif // NOTE_APP_H