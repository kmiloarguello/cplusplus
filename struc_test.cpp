#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int total = 10;
int c1;

struct person {
  int id;
  string nombre;
  string sexo;
} man;

void printimprime (person imprime);

void preguntas(person){
	
	string mystr;
	int i;

		cout << "\nIngresa el id: ";
		getline (cin,mystr);
		stringstream(mystr) >> man.id;
		
		cout << "Ingresa el nombre: ";
		getline (cin,man.nombre);
		
		cout << "Ingresa el sexo: ";
		getline (cin,man.sexo);
}

int main ()
{
  string mystr;
  string input;
  int i;

  cout << "TALLER FINAL\n";
  cout << "ARGUELLO RINCON CARLOS FELIPE";
  preguntas(man);
  for(i=0; i<total; i++){

	cout << "Desea ingresar otro registro (s/n)";
	cin >> input;

	if(input == "s"){
		cout << "\nEligio si\n";
		cout << "Ingresa id: ";
		getline (cin,mystr);
		stringstream(mystr) >> man.id;
		if(man.id == man.id-i){
			cout << "Ese id ya está usado, escoja otro" << endl;
			cout << "Ingresa id: ";
			getline (cin,mystr);
			stringstream(mystr) >> man.id;
			preguntas(man);
		}else{
			preguntas(man);
		}
		
	
	}
	else if(input == "n"){
		cout << "\nEligio no\n";
		
		cout << "Ingresa el id de la persona a consultar: ";
		cin >> c1;

		if(c1 == man.id){
			cout << "\nDatos:\n";
			printimprime (man);
		}

	}else{
		cout << "Porfa escribe S o N ;)";
	}
  }
  printimprime (man);
  
  return 0;
}

void printimprime (person imprime)
{
  cout << "id --> " << imprime.id << endl;
  cout << "nombre --> " << imprime.nombre << endl;
  cout << "sexo --> " << imprime.sexo << endl;

}
