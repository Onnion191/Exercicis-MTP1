/* Determinar ordenar dos nombres */
// Entrada: un car�cter (caracter)
// Sortida: diu si �s o no un d�git

#include<iostream>
using namespace std;

bool es_digit(char caracter) {
//Pre: cert
//Post: cert si caracter �s un digit ('0' a '9')
    return caracter>='0' and caracter<='9';
}

int main()
{
	//Entrada
	char caracter;
	cout<<"Introdueix un car�cter: ";
	cin>>caracter;
	//C�lcul i Sortida
	if(es_digit(caracter)) cout<<"�s un d�git"<<endl;
	else cout<<"No es un d�git"<<endl;

	return 0;
}
