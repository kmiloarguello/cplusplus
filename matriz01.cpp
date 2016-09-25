#include<conio.h>
#include<stdio.h>

int main(){
	int filas = 9;
	int columnas = 7;	
	int i,j;
	int mat[filas][columnas] = {};
	int x,y,elemento;
	
	
	printf("Taller Programacion II \n"
         "\n"
		 "Este consiste en un cuadro de Dias Vs Horas.\n"
		 "Debes llenar los espacios en blanco, para ello debes escoger un día de la semana del 1 al 5 (Columnas) y luego esocges la hora poniendo un numero del 1 al 7. (Filas)"
		 "\n\n"
		 "La matriz estara compuesta por espacios en valor de 0 y la idea es reemplazarlos por los valores ingresados\n"
		 "No puedes superponer espacios."
		 "\n\n"
		 "Empecemos\n\n");
	
	printf("\nMatriz Inicial:\n"); 
	
	for(i=0; i<filas-1; i++){	
	    for(j=0;j<columnas-1;j++){
	    	mat[i+1][0] = 1 + i; // Sumar primer Columna hasta 7
	    	mat[0][1+j] = 1 + j; //Sumar primer fila suma de a 1
	    	mat[0][0]= 0;
	    	
            printf(" %d ",mat[i][j]);
		}
    printf("\n");
	}
	
	for(i=0; i<filas-1; i++){
	    for(j=0; j<columnas-1; j++){
	    	
	    	mat[i+1][0] = 1 + i; // Sumar primer Columna hasta 7
	    	mat[0][1+j] = 1 + j; //Sumar primer fila suma de a 1
	    	mat[0][0]= 0;
	    	x=i;
	    	y=j;
	
//	    	 Pedir Coordenadas mientras que este entre 0 y el numero de filas y columnas
            
            do{
	    		printf("coor X: ");
	            scanf("%d", &x);
	               
	            if(x > filas-1){
	               	printf("Error Numero Mayor a Filas\n");
	               	printf("coor X: ");
	               	scanf("%d", &x);
				}else if(x <= -1){
				   	printf("Error Numero Negativo\n");
	               	printf("coor X: ");
	               	scanf("%d", &x);
				}
	            
			}while(x > 1 && x < filas-1);
			
			x = x - 1;
	    	
	    	do{
			
			    printf("coor Y: ");
	            scanf("%d", &y);
	               
	            if(y > columnas-1){
	               	printf("Error Numero Mayor a Columnas\n");
	               	printf("coor Y: ");
	               	scanf("%d", &y);
				}else if(y <= -1){
				   	printf("Error Numero Negativo\n");
	               	printf("coor Y: ");
	               	scanf("%d", &y);
				}
			}
	        while(y < 1 || y > columnas-1);
	        
			y = y -1;
	            
	        mat[x][y] = 1;
	        printf("M[%d][%d] = %d\n",x+1,y+1,mat[x][y]);
	        	
	        for(i=0; i<filas-1; i++){	
				for(j=0;j<columnas-1;j++){
					mat[i+1][0] = 1 + i; // Sumar primer Columna hasta 7
					mat[0][1+j] = 1 + j; //Sumar primer fila suma de a 1
						
			printf(" %d ",mat[i][j]);
		}
    printf("\n");
	}       	
	}
	}	

}
