//Entrada: una seq��ncia de car�cters acabada en '#'
//Sortida: Diu si totes les paraules de la seq��ncia comencen igual
#include<iostream>
using namespace std;

const char EOS='#';

bool es_separador(char lletra){
/*Pre: cert
  Post: retorna cert si lletra �s un separador, fals altrament */
   bool separador=true;
   if(lletra>='a' and lletra <='z') separador= false;
   else if(lletra>='A' and lletra <='Z') separador= false;
   else if(lletra>='0' and lletra <='9') separador=false;
   else if (lletra==EOS) separador=false;
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

void passar_separadors(){
/*Pre: fitxer v�lid
  Post: s�han llegit tots els separadors */
   char lletra=' ';
   while(lletra!=EOS and es_separador(lletra))
     cin.get(lletra);
   cin.unget();
}


bool fi_sequencia(){
/*Pre: EOS no llegida
  Post: retorna cert si es detecta EOS, fals altrament */
   char lletra=cin.get(); //agafem el seg�ent car�cter
   bool final=lletra==EOS; //mirem si indica el final
   if(not final) cin.unget(); //si no �s EOS es retorna pq sigui llegit
   return final;
}

char passar_paraula_obtenint_inici(){
/*Pre: fitxer v�lid i apunt de llegir el 1r car�cter d�una paraula
  Post: s�ha llegit tota una paraula i es retorna el nombre de car�cters que la formen*/
   char inici=cin.get(); //lletra=cin.get();
   char lletra=inici;
   while(inici!=EOS and not es_separador(lletra)){
      cin.get(lletra); //lletra=cin.get();
   }
   cin.unget(); //pot no ser necessari
   return inici;
}

bool totes_comencen_igual(){
//Pre: cert
//Post: retorna cert si totes les paraules fins a EOS comencen igual, fals atlrament
    char inici=' ', inici_paraula=' ';
    passar_separadors();
    if(not fi_sequencia()){
        inici=passar_paraula_obtenint_inici();
        inici_paraula=inici;
        passar_separadors();
        while(not fi_sequencia() and inici_paraula==inici){
            inici_paraula=passar_paraula_obtenint_inici();
            passar_separadors();
        }
    }
    return inici_paraula==inici; //he de validar que totes, inclosa la darrera comencin igual
}

int main(){
    cout<<"Entra la seq��ncia acabada en "<<EOS<<endl;
    cout<<"Totes les paraules comencen igual? "<<boolalpha<<totes_comencen_igual()<<endl;;
    return 0;
}
