#include "mywidget.h"
#include  <QMouseEvent>
#include  <QPainter>
#include <QInputDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vertex.h"
#include <qdebug>
#include "math.h"

#include <QPen>

//const qreal Pi = 3.14;

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
}


QVector<Vertex>::iterator MyWidget::find_vertex(int x, int y){
    for(auto it=wierzcholki.begin(); it!=wierzcholki.end(); it++)
    {
        if (((it->x-50<x)&&(it->x+50>x)&&(it->y-50<y)&&(it->y+50>y))){
            return it;
        }
    }
    return wierzcholki.end();
}

//cała osbługa rysowania
void MyWidget::mousePressEvent( QMouseEvent *event )
{
    //dodawanie wierzchołka
    if((koniec==false)&&(dodaj==true)&&(V==true)){
        Vertex w(event->x(), event->y());
        if(wierzcholki.empty()){
            wierzcholki.push_back(w);
        }
        else{
            bool in=false;
        for(auto it=wierzcholki.begin(); it!=wierzcholki.end(); it++)
        {
            if (((it->x-50<w.x)&&(it->x+50>w.x)&&(it->y-50<w.y)&&(it->y+50>w.y)))
                in=true;

        }
        if(in==false)
        wierzcholki.push_back(w);
        }
    repaint();
    }
    //usuwanie wierzchołka
    if((koniec==false)&&(usun==true)&&(V==true)){
        QVector<Vertex>::iterator vit = find_vertex(event->x(), event->y());
        if(vit!=wierzcholki.end())
            for(auto it=krawedzie.begin(); it!=krawedzie.end();){
                if((vit==find_vertex_it(it->p_id)) || (vit==find_vertex_it(it->k_id))){
                    it = krawedzie.erase(it);
                }
                else {
                    ++it;
                }
            }
            wierzcholki.erase(vit);

        repaint();
    }


    //zaznaczanie krawędzi i podanie wagi
    if((koniec==false)&&(dodaj==true)&&(E==true)){
        QVector<Vertex>::iterator vit = find_vertex(event->x(), event->y());

        if(vit!=wierzcholki.end()){
            if(zaznaczone.contains(vit))
                zaznaczone.removeAt(zaznaczone.indexOf(vit));
            else
                zaznaczone.push_back(vit);
        }
        if(zaznaczone.size()==2){
            bool ok;
            double waga = QInputDialog::getDouble(this, "Waga", "Podaj wagę",1,0,100,1,&ok);
            if(ok){
                add_edge(*(zaznaczone[0]), *(zaznaczone[1]), waga, skierowana);
                zaznaczone.clear();
            } else {
                zaznaczone.pop_back();
            }
        }

        repaint();
    }

    //usuwanie krawędzi
    if((koniec==false)&&(usun==true)&&(E==true)){
        QVector<Vertex>::iterator vit = find_vertex(event->x(), event->y());

        if(vit!=wierzcholki.end()){
            if(zaznaczone.contains(vit))
                zaznaczone.removeAt(zaznaczone.indexOf(vit));
            else
                zaznaczone.push_back(vit);
        }
        if(zaznaczone.size()==2){
            erase_edge(*(zaznaczone[0]), *(zaznaczone[1]));
            zaznaczone.clear();
        }

        repaint();
    }
    if (koniec==true){
        QVector<Vertex>::iterator vit = find_vertex(event->x(), event->y());

        if(vit!=wierzcholki.end()){
            if(zaznaczone.contains(vit))
                zaznaczone.removeAt(zaznaczone.indexOf(vit));
            else
                zaznaczone.push_back(vit);
        }
    }
}


void MyWidget::erase_edge(Vertex &s, Vertex &k){
    for(auto it=krawedzie.begin(); it!=krawedzie.end(); ++it){
        if(((&s==find_vertex_it(it->p_id)) && (&k==find_vertex_it(it->k_id))) || ((&s==find_vertex_it(it->k_id)) && (&k==find_vertex_it(it->p_id)))){
            krawedzie.erase(it);
            return;
        }
    }

}

void MyWidget::add_edge(Vertex &s, Vertex &k, double weight, bool directed){
    if(krawedzie.size()>0){
        directed=krawedzie.first().skierowana;

    }

    Edges edge(s, k, weight, directed);       
    krawedzie.push_back(edge);

}




void MyWidget::draw_edge(QPainter & painter, unsigned long p_id, unsigned long k_id, double weigth, bool directed) {
     int sx = find_vertex_it(p_id)->x;
     int sy = find_vertex_it(p_id)->y;
     int ex = find_vertex_it(k_id)->x;
     int ey = find_vertex_it(k_id)->y;


    int tx;
    int ty;
    if(directed==true){
        painter.setPen(Qt::black);
    }
    else{
        painter.setPen(Qt::green);
    }

    painter.drawLine(sx, sy, ex, ey);
    painter.setPen(Qt::black);
    if(sx<ex){
        tx= (ex+sx)/2;}
    else{
        tx=(sx+ex)/2;
    }
    if(sy<ey){
        ty= (ey+sy)/2;}
    else{
        ty=(sy+ey)/2;
    }
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawRect(tx,ty,20,20);
    painter.setPen(Qt::black);
    painter.drawText(tx+4,ty+13,QString("%1").arg(weigth));
    painter.setPen(Qt::black);
    if(directed){
        draw_arrow(painter, sx, sy, ex, ey);
    }
}

void MyWidget::draw_arrow(QPainter & painter, int sx, int sy, int ex, int ey) {
   // painter.drawLine(sx, sy, ex, ey);
    //Rysowanie strzalki
    /*setLine(QLineF(intersectPoint, myStartItem->pos()));

    double angle = ::acos(line().dx() / line().length());
    if (line().dy() >= 0)
        angle = (Pi * 2) - angle;

    QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                    cos(angle + Pi / 3) * arrowSize);
    QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                    cos(angle + Pi - Pi / 3) * arrowSize);

    arrowHead.clear();
    arrowHead << line().p1() << arrowP1 << arrowP2;
    painter->drawLine(line());
    painter->drawPolygon(arrowHead);
    if (isSelected()) {
        painter->setPen(QPen(myColor, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);*/
}

//to tylko rysuje
void MyWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.fillRect( QRect(0,0,this->width(), this->height()), QBrush(Qt::white));
    for(int i=0; i<krawedzie.size(); i++)
    {

        draw_edge(painter, krawedzie[i].p_id, krawedzie[i].k_id,krawedzie[i].waga, krawedzie[i].skierowana);

    }
    for(auto it=wierzcholki.begin(); it<wierzcholki.end(); ++it)
    {
        //painter.drawPoint(wierzcholeki[i].x, wierzcholeki[i].y);

        if(zaznaczone.contains(it)){
           painter.setBrush(Qt::yellow);
        }
        else{
           painter.setBrush(Qt::white);
        }
        painter.drawEllipse(it->x-20, it->y-20,40 , 40);
        painter.drawText(it->x-12,it->y+5,QString("V%1").arg(it-wierzcholki.begin()+1));
    }

}


int MyWidget::find_index(Vertex * v){
    for(int i=0; i<wierzcholki.size(); ++i){
        if((v->x == wierzcholki[i].x) && (v->y == wierzcholki[i].y)){
            return i;
        }
    }
    return -1;
}

int MyWidget::find_index(unsigned long id){
    for(int i=0; i<wierzcholki.size(); ++i){
        if(wierzcholki[i].id == id){
            return i;
        }
    }
    return -1;
}
//macierz przyległości

void MyWidget::update_mp() {
    Macierz_przyleglosci.clear();
    for(int i=0; i<wierzcholki.size(); ++i){
        QVector<double> linia;
        for(int j=0; j<wierzcholki.size(); ++j){
            linia.push_back(0);
        }
        Macierz_przyleglosci.push_back(linia);
    }

    for(auto it=krawedzie.begin(); it!=krawedzie.end(); ++it){
        int index_p = find_index(it->p_id);
        int index_k = find_index(it->k_id);

        if(it->skierowana){
            Macierz_przyleglosci[index_p][index_k] = it->waga;
        }
        else{
            Macierz_przyleglosci[index_p][index_k] = it->waga;
            Macierz_przyleglosci[index_k][index_p] = it->waga;
        }
    }

}
QString MyWidget::print_macierz_przyleglosci(){
    QString str;
    str+="\t";
    for(int i=0; i<Macierz_przyleglosci.size(); i++){
        str+=QString ("V%1\t").arg(i+1);}
    str+="\n";
    str+="\t";
    for(int i=0; i<Macierz_przyleglosci.size(); i++){
        str+=QString ("--\t");}
    str+="\n";
    for(int i=0; i<Macierz_przyleglosci.size(); i++){
        str+=QString ("V%1|\t").arg(i+1);
        for(int j=0; j<Macierz_przyleglosci[i].size(); j++){

            str+=QString ("%1\t").arg(Macierz_przyleglosci[i][j]);
        }
        str+="\n";
    }

return str;
}


QVector<Vertex>::iterator  MyWidget::find_vertex_it(unsigned long id){
    for(auto it=wierzcholki.begin(); it<wierzcholki.end(); ++it)
    {
        if(it->id == id)
                return it;
    }
}


void MyWidget::update_mi() {
    Macierz_incydencji.clear();
    for(int i=0; i<wierzcholki.size(); ++i){
        QVector<double> linia_i;
        for(int j=0; j<krawedzie.size(); ++j){
            linia_i.push_back(0);
        }
        Macierz_incydencji.push_back(linia_i);
    }
/*
    for(auto it=krawedzie.begin(); it!=krawedzie.end(); ++it){
        int index_p = find_index(it->p_id);
        int index_k = find_index(it->k_id);
        //for (int i=0; i<krawedzie.size();  ++i){

        if(it->skierowana){
            Macierz_incydencji[index_p][it] = 1;
            Macierz_incydencji[index_k][it] = -1;
        }
        else{
            Macierz_incydencji[index_p][it] = 1;
            Macierz_incydencji[index_k][it] = 1;
       // }
        }
    }*/

}

QString MyWidget::print_macierz_incydencji(){
    QString str_mi;
    str_mi+="\t";
    for(int i=0; i<Macierz_incydencji.size(); i++){
        str_mi+=QString ("E%1\t").arg(i+1);}
    str_mi+="\n";
    str_mi+="\t";
    for(int i=1; i<Macierz_incydencji.size(); i++){
        str_mi+=QString ("--\t");}
    str_mi+="\n";
    for(int i=0; i<Macierz_incydencji.size(); i++){
        str_mi+=QString ("V%1|\t").arg(i+1);
        for(int j=0; j<Macierz_incydencji[i].size(); j++){

            str_mi+=QString ("%1\t").arg(Macierz_incydencji[i][j]);
        }
        str_mi+="\n";
    }

return str_mi;
}

QStringList MyWidget::combo(){
    QStringList str_combo;
    for(int i=0; i<wierzcholki.size(); ++i){
        str_combo<<QString("V%1").arg(i+1);
      //  return str_combo;
    }
    return str_combo;
}

void MyWidget:: BFS_odwiedzony(){
    BFS.clear();



}
