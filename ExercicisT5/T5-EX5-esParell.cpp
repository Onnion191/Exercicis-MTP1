/* Determinar si un nombre �s parell utilitzant un subprograma */
// Entrada: un natural (n) 
// Sortida: indica si n �s parell o no

#include<iostream>
using namespace std;

bool es_parell(unsigned n){
//Pre: cert
//Post: retorna cert si n �s parell, fals altrament

	return n%2==0;
}

int main()
{
	//Entrada
	unsigned n;
	cout<<"Introdueix un natural: ";
	cin>>n;

	//Sortida
	cout<<"Parell: "<<boolalpha<<es_parell(n)<<endl;
	return 0;
}

