#ifndef QUADRILATER_H
#define QUADRILATER_H

#include "Poligon.h"

//Descripci�: Guarda la informaci� d'un quadril�ter 4 v�rtexs al pla
class Quadrilater: public Poligon
{
    public:
        Quadrilater();
         //Pre:--
        //Post: crea un quadrat degenerat amb 4 v�rtexs iguals

        //CONSULTOR
        void mostra()const;
        //Pre:--
        //Post: mostra la informaci� del quadril�ter

        //MODIFICADOR
        void llegir();
        //Pre:--
        //Post: llegeix els tres vertexs que formen el triangle

    private:
        //CONSULTOR
        double area ()const;
        //Pre:--
        //Post: retorna l'�rea del triangle
};

#endif // QUADRILATER_H
