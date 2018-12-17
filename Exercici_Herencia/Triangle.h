#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Poligon.h"

//Descripci�: guarda els 3 v�rtexs d'un triangle al pla

class Triangle : public Poligon
{
    public:
        Triangle();
        //Pre:--
        //Post: crea un triangle degenerat amb 3 v�rtexs iguals

        void mostra()const;
        //Pre:--
        //Post: mostra la informaci� del triangle

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

#endif // TRIANGLE_H
