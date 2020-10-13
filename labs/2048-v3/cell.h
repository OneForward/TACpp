#ifndef CELL_H
#define CELL_H

#include <QLabel>

class Cell : public QLabel
{
    Q_OBJECT
public:
    Cell(int value);

    void draw();
private:

    int value;
};

#endif // CELL_H
