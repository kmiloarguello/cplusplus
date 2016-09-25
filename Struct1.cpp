#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int total = 2;
int c1;

struct estudiante {
  int codigo;
  int codigo1;
  string title;
  string materia;
  int year;
  int semestre;
  float n1;
  float n2;
  float n3;
} alumno;

void printimprime (estudiante imprime);

void preguntas(estudiante){
	
	string mystr;
	int i;

		cout << "\nIngresa el codigo: ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.codigo;
		
		cout << "Ingresa el nombre del estudiante: ";
		getline (cin,alumno.title);
		
		cout << "Ingresa la materia: ";
		getline (cin,alumno.materia);
		
		cout << "Ingresa year: ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.year;
		
		cout << "Ingresa el semestre: ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.semestre;
		
		cout << "Ingresa la nota 1 (30%): ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.n1;
		
		cout << "Ingresa la nota 2 (30%): ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.n2;
		
		cout << "Ingresa la nota 3 (40%): ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.n3;

}


int main ()
{
  string mystr;
  string input;
  int i;

  cout << "TALLER 3\n";
  cout << "ARGUELLO RINCON CARLOS FELIPE";
  preguntas(alumno);
  for(i=0; i<total; i++){

	cout << "Desea ingresar otro registro (S/N)";
	cin >> input;

	if(input == "S"){
		cout << "\nEligio SI\n";
		cout << "Ingresa el codigo: ";
		getline (cin,mystr);
		stringstream(mystr) >> alumno.codigo;
		preguntas(alumno);
	}
	else if(input == "N"){
		cout << "\nEligio NO\n";
		
		cout << "Ingresa el codigo del estudiante a consultar: ";
		cin >> c1;

		if(c1 == alumno.codigo){
			cout << "\nDatos:\n";
			printimprime (alumno);
		}

	}else{
		cout << "Porfa escribe S o N ;)";
	}
  }
  printimprime (alumno);
  
  return 0;
}

void printimprime (estudiante imprime)
{
  cout << "Codigo --> " << imprime.codigo << endl;
  cout << "Nombre --> " << imprime.title << endl;
  cout << "Materia --> " << imprime.materia << endl;
  cout << "Year --> " << imprime.year << endl;
  cout << "Semestre --> " << imprime.semestre << endl;
  cout << "Nota 1 30% --> " << imprime.n1 << endl;
  cout << "Nota 2 30% --> " << imprime.n2 << endl;
  cout << "Nota 3 40% --> " << imprime.n3 << endl;
  cout << "Nota Final % --> " << (imprime.n1 * 0.3) + (imprime.n2 * 0.3) + (imprime.n3 * 0.4) << endl;
}
