#include "vertex.h"
#include  <QMouseEvent>
unsigned long Vertex::Counter = 1;

Vertex::Vertex(int x_, int y_, QColor color) : x(x_), y(y_), kolor(color), id(Vertex::Counter++)
{

}


Vertex::Vertex()
{


}



