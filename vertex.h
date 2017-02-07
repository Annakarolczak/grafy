#ifndef VERTEX_H
#define VERTEX_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Vertex
{
public:
    Vertex();
    Vertex(int x_, int y_, QColor color=Qt::black);
    int x, y;
    QColor kolor;
    unsigned long id;

    static unsigned long Counter;
};

#endif // VERTEX_H
