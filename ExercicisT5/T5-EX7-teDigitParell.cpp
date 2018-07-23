/* Determinar si un nombre �s parell utilitzant un subprograma */
// Entrada: un natural (n)
// Sortida: indica si n �s parell o no

#include<iostream>
using namespace std;

bool es_parell(unsigned n){
//Pre: cert
//Post: cert si n �s parell, fals altrament
	return n%2==0;
}

bool te_digit_parell(unsigned n){
//Pre: cert
//Post: cert si n t� un d�git parell, fals altrament

    unsigned digit=n%10;
    //FI: n tingui un �nic d�git o el d�git analitzat �s parell
    while(not es_parell(digit) and n>9){
        cout<<"- "<<digit<<" no parell"<<endl;
        n=n/10;
        digit=n%10;
    }
    return es_parell(digit);
}

int main()
{
	//Entrada
	unsigned n;
	cout<<"Introdueix un natural: ";
	cin>>n;

	//Sortida
	if(te_digit_parell(n)) cout<<"T� un d�git parell"<<endl;
	else cout<<"No t� cap d�git parell"<<endl;

	return 0;
}
