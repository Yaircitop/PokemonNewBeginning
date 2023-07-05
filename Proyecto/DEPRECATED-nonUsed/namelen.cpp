#include<iostream>

int namelen(char name[]){
    int i;
    for(i=1;;i++){
        if(name[i]=='\0')break;
        if(i>20)break;
    }
    return i;
}

int main(){
    char name[10];
    scanf("%s",&name);
    int j=namelen(name);
    printf("%d\n",j);
    return 0;
}