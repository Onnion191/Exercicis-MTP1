//Entrada: una seq��ncia de naturals acabada en 0
//Sortida: diu si la seq��ncia t� o no un m�ltiple de 7

#include<iostream>
#include<fstream>
using namespace std;
const unsigned EOS=0;
bool conte_un_multiple(unsigned divisor){
//Pre: divisor>0
//Post: retorna cert si es llegeix un m�liple de divisor !=EOS, fals altrament
     unsigned nombre;
     cin>>nombre; //primer element
     while(nombre!=EOS and nombre%divisor!=0) //mentre no fi
        cin>>nombre; //seg�ent
     return nombre!=EOS;
}

int main(){
    cout<<"Entra una seq��ncia de naturals acabada en "<<EOS<<endl;
    cout<<"Cont� un multiple de 7? "<<boolalpha<<conte_un_multiple(7)<<endl;
    return 0;
}
