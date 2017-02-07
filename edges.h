#ifndef EDGES_H
#define EDGES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "vertex.h"


class Edges
{
public:
    Edges();
    Edges(Vertex &p_, Vertex &k_, double weight_ = 1.0, bool skier = false);
    double  waga;
    unsigned long  p_id, k_id;
    QColor kolor;
    bool skierowana;
};

#endif // EDGES_H
