#include <iostream>
#include <cstdlib>
#include <time.h>
 
using namespace std;
 
void imprimir (char **Matriz,int dim);
void colocar_minas (char **Matriz,int dim);
void borrar (int **M,int dim);
void borrar_char (char **M,int dim);
 
int main(void) {
  srand((unsigned) time(NULL));
  int dim,n;
  char ch=219;
 
  cout << "Introduzca la dimension de la matriz: ";
  cin >> dim;
  char **Matriz = new char *[dim];
  for (int j = 0; j < dim; j++)
    Matriz[j] = new char [dim];
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++)
      Matriz[i][j]='0';
  colocar_minas  (Matriz,dim);
  imprimir (Matriz,dim);
 
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++){
      n = rand() % 5 ;
      if (n<2 && Matriz[i][j]=='0')
        Matriz[i][j]=ch;
      else if (n==2 || n==3)
        Matriz[i][j]='*';
    }
  imprimir (Matriz,dim);
 
  borrar_char (Matriz,dim);
  return EXIT_SUCCESS;
}
 
void imprimir (char **Matriz,int dim) {
    for (int i = 0; i < dim; i++) {
      cout << "\t\t" ;
      for (int j = 0; j < dim; j++){
        cout << ' '  << Matriz[i][j] << ' ' ;
      }
      cout << "\n\n";
    }
    cout << "\n\n";
}
 
 
void colocar_minas (char **Matriz,int dim){
  int **cont;
  cont = new int *[dim];
  for (int j = 0; j < dim; j++)
    cont[j] = new int [dim];
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++)
      cont[i][j]=0;
  int numero,fil,col,k,l,contador=0;
  cout << "\nIntroduzca numero de minas (numero):";
  cin >> numero;
  for (int i = 0; i < numero; i++){
    cout << "\nColocando la mina : "<<i+1<<endl;
    do{
      cout << "Introduzca fila (1-numero): ";
      cin >> fil;
    }while(fil<1 || fil>dim);
    fil=fil-1;
 
    do{
      cout << "Introduzca columna (1-numero): ";
      cin >> col;
    }while(col<1 || col>dim);
    col=col-1;
    Matriz[fil][col]='1';
    cout<<"\tM["<<fil+1<<","<<col+1<<"]="<<Matriz[fil][col]<< "\n\n";
  }
  imprimir (Matriz,dim);
 
  for ( fil = 0 ;fil < dim; fil++) {
    for ( col = 0; col < dim; col++){
    contador=0;
      for ( k = -1; k < 2; k++) {
        for ( l = -1; l < 2; l++){
          if (fil+k < 0 || col+l < 0 || fil+k > dim-1 || col+l > dim-1)
            continue;
          else{
            contador+=(Matriz[fil+k][col+l]-'0');
          }
        }
      }
      cont[fil][col]=contador;
    }
  }
  for ( fil = 0 ;fil < dim; fil++)
    for ( col = 0; col < dim; col++)
      Matriz[fil][col]=cont[fil][col]+48;
  borrar (cont,dim);
}
 
void borrar_char (char **M,int dim) {
  for (int i = 0; i < dim; i++)
    delete[] M[i];
  delete[] M;
}
 
void borrar (int **M,int dim) {
  for (int i = 0; i < dim; i++)
    delete[] M[i];
  delete[] M;
}
