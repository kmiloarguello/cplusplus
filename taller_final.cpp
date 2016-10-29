#include <iostream>
using namespace std;

struct person {
	int id;
	string nombre;
	string sexo;
};

person leerDatos (person& j){
	cout << "id: ";
	cin >> j.id;
	
	cout << "Name: ";
	cin >> j.nombre;
	
	cout << "Sexo: ";
	cin >> j.sexo;
	
	return j;
}

bool duplicado( int array[], int n)
{

	return false;
}
void duplicado(struct person id){
	int i,j;
	
	for( i = 0; i < n; i++ ){
		for( j = i+1; j < n; j++ ){
			if( array[i] == array[j] )
				return true;
		}
	}
}

int main() {
	
	cout << "ARGUELLO RINCON CARLOS FELIPE" << endl;
	struct person id;
	person A;
	for(int i=0; i<3; i++){
		string res;
		leerDatos(A);
//		if(duplicado(A) == duplicado(A-i)){
//			cout << "repetido" << endl;
//		}else{
//			cout << "no repetido" << endl;
//		}
//		cout << "¿Desea añadir otro registro? (s/n)";
//		cin >> res;
//		if(res == "s"){
//			leerDatos(A);
//		}else{
//			cout << "gracias";
//		}
	}
	
	cout << endl << "nombre: " << A.nombre << endl << "sexo: " << A.sexo << endl;
	

	return 0;
}

