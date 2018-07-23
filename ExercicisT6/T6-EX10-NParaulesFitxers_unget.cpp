//Entrada: un fitxer de car�cters
//Sortida: quantes paraule t� el fitxer
#include<iostream>
#include<fstream>
#include<string>
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
   char lletra;
   fitxer.get(lletra);
   while(not fitxer.eof() and es_separador(lletra))
     fitxer.get(lletra);
  fitxer.unget(); //pot no ser necessari
}


void passar_paraula(ifstream& fitxer){
/*Pre: fitxer v�lid i apunt de llegir el 1r car�cter d�una paraula
  Post: s�ha llegit tota una paraula */
   char lletra=fitxer.get(); //lletra=cin.get();
   while(not fitxer.eof() and not es_separador(lletra)){
      fitxer.get(lletra); //lletra=cin.get();
   }
   cout<<endl;
   fitxer.unget(); //pot no ser necessari
}

unsigned nombre_paraules(ifstream& fitxer){
//Pre: fitxer v�lid
//Post: retorna el nombre de paraules de fitxer, eof llegit
    unsigned n_paraules=0;
    passar_separadors(fitxer);
    while(not fitxer.eof()){
        passar_paraula(fitxer);
        n_paraules++;
        passar_separadors(fitxer);
    }
    return n_paraules;
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fentrada(nom_fitxer.c_str());
    cout<<"Cont� "<<nombre_paraules(fentrada)<<" paraules."<<endl;;
    return 0;
}
