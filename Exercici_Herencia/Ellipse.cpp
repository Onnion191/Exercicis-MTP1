#include "Ellipse.h"

Ellipse::Ellipse()
{
    a_a=a_b=0;
}

double Ellipse::area()const{
    return PI*a_a*a_b;
}

void Ellipse::mostra() const{
    cout<<"EL.LIPSE:"<<endl;
    cout<<" Semi dist�ncia a l'eix x = "<<a_a<<endl;
    cout<<" Semi dist�ncia a l'eix y = "<<a_b<<endl;
    cout<<" Centre = "; a_centre.mostra(); cout<<endl;
    //Figura_Geometrica::mostra();//si hi hagu�s part a mostrar comuna (l'�rea??)
}

void Ellipse::llegir(){
    cout<<"Centre: "; a_centre.llegir();
    cout<<"Semidistancia als eixos x/y: "; cin>>a_a>>a_b;
}

