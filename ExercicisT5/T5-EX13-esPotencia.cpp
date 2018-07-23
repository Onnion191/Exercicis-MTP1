#include <iostream>
//Entrada: un natural (n) >1
//Sortida: diu si �s o no pot�ncia d'un natural < que n

using namespace std;

bool es_potencia_de(unsigned n, unsigned base){
//Pre: cert
//Post: cert si n �s base elevat a un natural, fals altrament
    unsigned resultat=1;
    while(resultat<n) resultat*=base;

    return resultat==n;
}

int main()
{
    //Entrada
    cout << "Entra un natural>1:" << endl;
    unsigned n;
    cin>>n;
    //C�lcul
    unsigned base=2;
    bool es_potencia=false;
    while(not es_potencia and base*base<=n){
        es_potencia=es_potencia_de(n,base);
        base++;
    }
    //Sortida
    cout<<"�s una pot�ncia? "<<boolalpha<<es_potencia<<endl;
    return 0;
}
