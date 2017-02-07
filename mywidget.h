#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "edges.h"
#include "vertex.h"
#include <QWidget>
#include <QVector>



class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    bool koniec = false;
    bool dodaj = true;
    bool usun = false;
    bool skierowana = false;
    bool nieskierowana = false;
    bool V, E = false;
    QVector<Vertex> wierzcholki;
    QVector<Vertex> BFS;
    QVector<QVector<Vertex>::iterator> zaznaczone;
    QVector<QVector<double> > Macierz_przyleglosci;
    QVector<QVector<double> > Macierz_incydencji;
    QVector<Edges> krawedzie;
    void update_mi();
    void update_mp();
    QStringList combo();
    QString print_macierz_przyleglosci();
    QString print_macierz_incydencji();
    void BFS_odwiedzony();
signals:

public slots:

private:
    int  x =0;
    int  y =0;

    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void paintClean(QPaintEvent *event);


    QVector<Vertex>::iterator find_vertex(int x, int y);
    void add_edge(Vertex & s, Vertex & k, double weight, bool directed);
    void erase_edge(Vertex & s, Vertex & k);
    void draw_edge(QPainter & painter,  unsigned long p_id, unsigned long k_id,  double weigth, bool directed);
    void draw_arrow(QPainter & painter, int sx, int sy, int ex, int ey);

    int find_index(Vertex * v);
    int find_index(unsigned long id);
    QVector<Vertex>::iterator find_vertex_it(unsigned long id);

};

#endif // MYWIDGET_H
