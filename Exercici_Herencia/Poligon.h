#ifndef POLIGON
#define POLIGON

#include "Figura_Geometrica.h"

//Descripci�: Permet guardar un poligon al pla

class Poligon : public Figura_Geometrica
{
    public:
        Poligon();
        //Pre:--
        //Post: Crea un poligon degenerat de 5 costats
        Poligon (unsigned n);
        //Pre: n>2
        //Post: crea un poligon d'n costats degenerat
        Poligon(const Poligon& other);
        //Pre:--
        //Post: crea un pol�gon amb els mateixos v�rtexs que other

        virtual ~Poligon();
        //Pre:--
        //Post: allibera la mem�ria reservada pel pol�gon

        //CONSULTORS
        virtual double area()const;
        //Pre: --
        //Post: retorna l'�rea del pol�gon actual
        virtual void mostra() const;
        //Pre: --
        //Post: mostra els v�rtexs de pol�gon actual

        //MODIFICADORS
        virtual void llegir();
        //Pre: --
        //Post: crea el pol�gon indicat per teclat
        Poligon& operator=(const Poligon& other);
        //Pre:--
        //Post: el pol�gon actual t� els mateixos v�rtexs que other

    protected:
        Punt2D* a_t;
        unsigned a_n;

        //CONSULTOR
        void mostra_vertexs()const;
        //Pre:--
        //Post: mostra tots els v�rtexs del pol�gon

        //MODIFICADOR
        void llegir_vertexs();
        //Pre: --
        //Post: llegeix els v�rtexs del pol�gon


    private:
        //MODIFICADORS
        void reserva_memoria(unsigned n);
        //Pre:n>0
        //Post: reserva mem�ria per un poligon d'n punts
        void allibera();
        //Pre: --
        //Post: allibera la mem�ria reservada pel poligon si �s que en t�.
        void copia(const Poligon &o);
        //Pre:--
        //Post: el pol�gon actual t� exactament els mateixos v�rtexs que o
};

#endif
