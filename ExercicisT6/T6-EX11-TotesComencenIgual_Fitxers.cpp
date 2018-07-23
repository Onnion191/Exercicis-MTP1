//Entrada: una seq��ncia de car�cters acabada en '#'
//Sortida: Diu si totes les paraules de la seq��ncia comencen igual
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
   if(not fitxer.eof()) fitxer.unget();//pot no ser necessari
}


char passar_paraula_obtenint_inici(ifstream& fitxer){
/*Pre: fitxer v�lid i apunt de llegir el 1r car�cter d�una paraula
  Post: s�ha llegit tota una paraula i es retorna el nombre de car�cters que la formen*/
   char inici=fitxer.get();
   char lletra=inici;
   while(not fitxer.eof() and not es_separador(lletra)){
      fitxer.get(lletra);
   }
   if(not fitxer.eof()) fitxer.unget(); //pot no ser necessari
   return inici;
}


bool totes_comencen_igual(ifstream& fitxer){
//Pre: fitxer valid
//Post: retorna cert si totes comencen igual, fals atlrament
    passar_separadors(fitxer);
    char inici=' ',inici_paraula=' ';
    if(not fitxer.eof()){
        inici=passar_paraula_obtenint_inici(fitxer);
        inici_paraula=inici;
        passar_separadors(fitxer);
        while(not fitxer.eof() and inici_paraula==inici){
            inici_paraula=passar_paraula_obtenint_inici(fitxer);
            passar_separadors(fitxer);
        }
    }
    return inici_paraula==inici; //si retorno fitxer.eof() la darrera pot comen�ar!=
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    cout<<"Totes les paraules comencen igual? "<<boolalpha<<totes_comencen_igual(fitxer)<<endl;;
    return 0;
}
