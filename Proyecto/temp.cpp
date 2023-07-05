#include<stdio.h>
#include<iostream>

int main(){
    int a = 2;
    int b = [function(x){return x*x},20];
    b[0](b[1]);
    printf("%d\n",a);
}