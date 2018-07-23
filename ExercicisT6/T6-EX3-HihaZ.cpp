//Entrada: una seq��ncia de car�cters acabada en '#'
//Sortida: diu si la seq��ncia t� o no una 'z'

#include<iostream>
#include<fstream>
using namespace std;
const char EOS='#';
bool conte_caracter(char lletra){
//Pre: cert
//Post: retorna cert si s'ha entrat la lletra per teclat, fals altrament
     char caracter; //inicialitzar tractament
     cin>>caracter; //primer element
     while(caracter!=EOS and caracter!=lletra) //mentre no fi
        cin>>caracter; //seg�ent
     return caracter!=EOS;
}

int main(){
    cout<<"Entra una seq��ncia de caracters acabada en "<<EOS<<endl;
    cout<<"Cont� una 'z'? :"<<boolalpha<<conte_caracter('z')<<endl;
    return 0;
}
