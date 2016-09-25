#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
main()
{
 char a[30];
 int i,mayus=0,minus=0,numero=0,caracter=0,espacio=0;;
 
 printf("Escriba el Texto (max 30 caracteres)\n");
 gets(a);
 for(i=0;a[i]!='\0';i++)
 {
  if(isspace(a[i])){
  	espacio++;
  }
  if( isupper(a[i])){
  	mayus++;
  }
  if( islower(a[i])){
    minus++;
  }
  if( isdigit(a[i])){
    numero++;
  }
  if( ispunct(a[i])){
    caracter++;
  }
 }
 
 printf("\n\nMayusculas: %d ",mayus);
 printf("\nMinusculas: %d ",minus);
 printf("\nNumeros: %d ",numero);
 printf("\nCaracteres Especiales: %d ",caracter);
 printf("\nEspacios: %d ",espacio);
 
 getch();
}
