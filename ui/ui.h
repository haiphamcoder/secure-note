#ifndef UI_H
#define UI_H

#include <QWidget>

class UI : public QWidget
{
    Q_OBJECT

public:
    explicit UI(QWidget *parent = nullptr);
};

#endif // UI_H