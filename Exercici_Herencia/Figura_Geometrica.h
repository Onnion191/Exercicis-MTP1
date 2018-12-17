#ifndef FIGURA_GEOMETRICA
#define FIGURA_GEOMETRICA

#include "Punt2D.h"

//Descripci�: Classe abstracta de la que deriven diferents tipus de figures geom�triques

class Figura_Geometrica
{
    public:

        Figura_Geometrica();
        //Constructor per defect

        //virtual ~Figura_Geometrica();
        // Alguna de les classe derivades treballa amb mem�ria din�mica cal indicar que el destructor �s virtual
        // Si enlloc d'implementar-lo buit es fes abstracte caldria implementar-lo a totes les classes derivades

        // CONSULTORS
        virtual void mostra() const=0;//m�tode abstracte
        // m�tode virtual per mostrar les diferents figures geom�triques, no hi ha cap part del mostrar
        // que sigui com�, per aix� es fa virtual, si calgu�s mostrar una part comuna
        // s'implementaria
        bool te_menor_area(Figura_Geometrica *f)const;
        //Pre: f!=NULL
        //Post: retorna cert si la figura actual t� area menor que l'apuntada per f

        //MODIFICADORS
        virtual void llegir()=0; //m�tode abstracte
        //No hi ha cap part del llegir que sigui com�, no s'implementa

    protected:
        static const double PI;//=3.14159;
        //Constant accessible des de totes les classes derivades

        virtual double area()const=0;
        // el c�lcul de l'�rea �s espec�fic de cada tipus de figura geom�trica, no s'implementa a la classe base

    private:
};

#endif
