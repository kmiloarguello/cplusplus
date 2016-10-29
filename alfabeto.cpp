#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<cstring>
using namespace std;

int posicion (char c)
{
    int pos;
    const char * alfabeto = "abcdefghijklmnopqrstuvwxyz";
    const char * encontra;

    c = tolower (c);
    encontra = strchr (alfabeto, c);
    pos = encontra - alfabeto;
    if (!encontra)
        pos = 0;
    else if (pos == 26)
        pos = 0;
    else
        pos++;
    return pos;
}

int main ()
{
    cout << "Nombre: ARGUELLO RINCON CARLOS FELIPE" << endl;
    cout << "Lista de caracteres" << endl;
    cout << " a, b , f , z , m, g " << endl;
	char tests[] = {'a', 'b', 'f', 'z', 'm', 'g'};
    char * c;
    for (c = tests; *c; c++) {
        printf ("%d\n", *c - 'a' + 1);
        printf ("%d\n", posicion (*c));
    }
    return 0;
}
