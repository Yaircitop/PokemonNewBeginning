#include <stdio.h>
#include<iostream>
#include<time.h>
void imprime(int a)
{ 
  float randomModifier = (rand()%15+85)/(float)100;
  float m = (float)(a)/7;
  float t = (float)3/5;
  int y =(((float)2/5)*2)+5;
  int g = (((2+5)-2)*3)/2;
   printf("Imprimiendo un message %f %f\n",m,randomModifier);
   printf("%d\n",rand()%2);
   printf("%f\n",(float)3/5);
   printf("%d\n",y);
   printf("%d\n",g);
}
int  main()
{  
  srand(time(0));

    int b=57;
    void(*Bubble)(int);
    void (*ptr_funct)(int);
    ptr_funct=imprime; //le asigno imprime
    ptr_funct(b); //Llama a imprime
    Bubble = ptr_funct; //copia la direccion
//    Bubble(b); //llama a imprime
    return 0;
}