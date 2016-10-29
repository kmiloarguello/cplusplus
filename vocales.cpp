#include<iostream>
#include<cstring>
using namespace std;

int vocales ( char *);

int main(){
	cout << "Nombre: ARGUELLO RINCON CARLOS FELIPE" << endl << endl;
	char palabra[80];
	cout << "Ingresa una palabra:";
	cin.getline (palabra, 80);
	cout << "Numero de vocales: " << vocales(palabra) << endl;

return 0;
}


int vocales ( char * pCh){
	int vocal = 0;

	while(*pCh){
		if(strspn(pCh, "aeiou"))
			vocal++;
		pCh++;
	}

	return vocal;
}
