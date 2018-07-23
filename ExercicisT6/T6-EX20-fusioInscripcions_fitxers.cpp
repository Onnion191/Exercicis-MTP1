//Entrada: Dos fitxers amb una seq�encia de dates ordenades i nombre d'inscripcions acabada en ws
//Sortida: Crea un fitxer fusi� de dates ordenades amb el nombre conjunt d'inscripcions separades per salts de l�nia
#include <iostream>
#include<fstream>
using namespace std;

void llegir(unsigned& dia, unsigned& mes, unsigned& any, unsigned& n, ifstream& dades){
//Pre: dades valid (si t� un natural per llegir en t� 4)
//Post: si dades cont� un unsigned dia, mes, any i n s�n els 4 primers naturals de dades
    dades>>dia;
    if(not dades.eof()){
        dades>>mes>>any>>n;
    }
}

void escriure(unsigned dia, unsigned mes, unsigned any, unsigned n, ofstream& sortida){
//Pre: sortdia valid
//Post: s'ha escrit dia mes any n salt de linia a sortida
    sortida<<dia<<" "<<mes<<" "<<any<<" "<<n<<endl;
}

bool es_menor(unsigned dia1,unsigned mes1,unsigned any1,unsigned dia2,unsigned mes2,unsigned any2){
//Pre: dia1 mes1 any1 una data dia2 mes2 any2 una altra data
//Post: retorna cert si la data1 �s menor que la data 2
    bool menor=false;
    if(any1<any2) menor=true;
    else if(any1==any2){
        if(mes1<mes2) menor=true;
        else if(mes1==mes2 and dia1<dia2) menor=true;
    }
    return menor;
}

void acabar(unsigned dia, unsigned mes, unsigned any, unsigned n, ifstream& dades, ofstream& sortida){
//Pre: sortida v�lid
//Post: si dades es valid mostra en uns l�nia dia mes any n i a sota hi copia el contingut que queda per llegir de dades a sortida separant dates diferents en l�nies diferent
    while(not dades.eof()){
		escriure(dia,mes,any,n,sortida);
		llegir(dia,mes,any,n,dades);
	}
}


int main(){
    ifstream dades1("dades1.txt");
    ifstream dades2("dades2.txt");
    ofstream sortida("dades.dat");
    unsigned dia1,mes1,any1,dia2,mes2,any2,n1,n2;
    llegir(dia1,mes1,any1,n1,dades1);
    llegir(dia2,mes2,any2,n2,dades2);
    while(not dades1.eof() and not dades2.eof()){
        if(any1==any2 and mes1==mes2 and dia1==dia2){
            escriure(dia1,mes1,any1,n1+n2,sortida);
            llegir(dia1,mes1,any1,n1,dades1);
            llegir(dia2,mes2,any2,n2,dades2);
        }
        else if(es_menor(dia1,mes1,any1,dia2,mes2,any2)){
            escriure(dia1,mes1,any1,n1,sortida);
            llegir(dia1,mes1,any1,n1,dades1);
        }
        else{
            escriure(dia2,mes2,any2,n2,sortida);
            llegir(dia2,mes2,any2,n2,dades2);
        }
    }
	acabar(dia1,mes1,any1,n1,dades1,sortida);
	acabar(dia2,mes2,any2,n2,dades2,sortida);
    return 0;
}
