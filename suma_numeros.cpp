#include<iostream>

using namespace std;
int division(int,int);
main()
{
      int size=5;              
      int array[size];          
      int sum=0;                
      for(int i=0;i<size;i++)   
      {
              cout << "Nombre: ARGUELLO RINCON CARLOS FELIPE" << endl;
			  cout<<"Ingrese numero "<<i+1<<endl;
              cin>>array[i];
              sum=sum+array[i];
      }
      cout<<"Promedio numeros "<<division(sum,size);
      
}
int division(int sum,int size)
{
    return sum/size;
}
