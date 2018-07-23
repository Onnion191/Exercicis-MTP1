//Entrada: un fitxer de car�ctres
//Sortida: diu si totes les paraules del fitxer tenen igual llargada
#include<iostream>
#include<fstream>
using namespace std;

bool es_separador(char lletra){
/*Pre: cert
  Post: retorna cert si lletra �s un separador, fals altrament */
   bool separador=true;
   if(lletra>='a' and lletra <='z') separador= false;
   else if(lletra>='A' and lletra <='Z') separador= false;
   else if(lletra>='0' and lletra <='9') separador=false;
   else{  //considerem els car�cters especials catalans i castellans
      switch(lletra){
         case '�': case '�': case '�': case '�': case'�': case '�': case '�':
         case '�': case '�': case '�': case'�': case '�': case '�': case '�':
         case '�':
            separador=false; break;
      }
   }
   return separador;
}

void passar_separadors(ifstream& fitxer){
/*Pre: fitxer v�lid
  Post: s�han llegit tots els separadors */
   char lletra=' ';
   while(not fitxer.eof() and es_separador(lletra))
     fitxer.get(lletra);
   if(not fitxer.eof()) fitxer.unget();
}


unsigned passar_paraula_comptant(ifstream& fitxer){
/*Pre: fitxer v�lid i apunt de llegir el 1r car�cter d�una paraula
  Post: s�ha llegit tota una paraula i es retorna el nombre de car�cters que la formen*/
   char lletra=fitxer.get();
   unsigned comptador=0;
   while(not fitxer.eof() and not es_separador(lletra)){
      fitxer.get(lletra);
      comptador++;
   }
   if(not fitxer.eof()) fitxer.unget(); //pot no ser necessari
   return comptador;
}


bool totes_igual_llargada(ifstream& fitxer){
//Pre: fitxer valid
//Post: retorna cert si totes tenen la mateixa llargada, fals altr.
    passar_separadors(fitxer);
    if(not fitxer.eof()){
        unsigned llargada_primera=passar_paraula_comptant(fitxer);
        passar_separadors(fitxer);
        unsigned llargada_paraula=llargada_primera;
        while(not fitxer.eof() and llargada_primera==llargada_paraula){
            llargada_paraula=passar_paraula_comptant(fitxer);
            passar_separadors(fitxer);
        }
    }
    return fitxer.eof();
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    cout<<"Totes les paraules tenen igual llargada? "<<boolalpha<<totes_igual_llargada(fitxer)<<endl;
    return 0;
}
