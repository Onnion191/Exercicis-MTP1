#include "Quadrilater.h"

Quadrilater::Quadrilater():Poligon(4)
{
    //ctor
}


void Quadrilater::llegir(){
    llegir_vertexs();
}

void Quadrilater::mostra()const{
    cout<<"Quadrilater "<<endl;
    mostra_vertexs();
    //Figura_Geometrica::mostra(); //si s'hagu�s de mostrar una part comuna com podria ser l'�rea
}

double Quadrilater::area()const{
    return a_t[0].distancia(a_t[1])*a_t[1].distancia(a_t[2]);
}



