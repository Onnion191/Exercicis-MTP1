/* Determinar ordenar dos nombres */
// Entrada: tres enters
// Sortida: els enters ordenats de petit a gran

#include<iostream>
using namespace std;

void ordena2(int& a, int& b){
//Pre: a=A, b=B
//Post: a<=b i contenen una permutaci� d'A i B
    if(a<b){
        int c=a;
        a=b;
        b=c;
    }
}


void ordena3(int& a, int& b, int &c){
//Pre: a=A, b=B, c=C
//Post: a<=b<=c contenen una premutaci� d'A, B i C
    ordena2(a,b); //if(a>b) intercanvi(a,b);
    ordena2(a,c); //if(a>c) intercanvi(a,c);
    ordena2(b,c); //if(b>c) intercanvi(b,c);
}

int main()
{
	//Entrada
	int n1, n2, n3;
	cout<<"Introdueix tres enters: ";
	cin>>n1>>n2>>n3;
	//C�lcul
	ordena3(n1,n2,n3);
	//Sortida
	cout<<"Els nombres ordenats de gran a petit: "<<n1<<" "<<n2<<" "<<n3<<endl;

	return 0;
}
