#include "edges.h"

Edges::Edges() {


}


Edges::Edges(Vertex &p_, Vertex &k_, double weight_, bool skier) : p_id(p_.id), k_id(k_.id), waga(weight_), kolor(Qt::black), skierowana(skier)
{

}
