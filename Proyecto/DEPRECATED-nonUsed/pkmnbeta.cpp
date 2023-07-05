#include<iostream>
//#include"pkmnalpha.h"
#include"pokedex.h"
#include<time.h>
void healing(pokemon *pk){pk->heal(float(pk->getATK()*1.5));if(pk->getohp()<pk->getHP()){pk->setHP(pk->getohp());};};
float detATK(pokemon *pm,int x){
    switch(x){
        case 0:return pm->atk1();
        case 1:return pm->atk2();
        case 2:healing(pm);return 0;
        case 3:pm->setDEF(pm->getDEF()*1.2);return 0;
        default:std::cout<<"bad, error in detAtk(pokemon,int)\n"<<std::endl;
    return 0;};
};

pokemon combat(pokemon *pk, pokemon *pm){
    std::cout<<pk->getNAME()<<" hp: "<<pk->getHP()<<std::endl;
    std::cout<<" VS "<<std::endl;
    std::cout<<pm->getNAME()<<" hp: "<<pm->getHP()<<std::endl;
    do{
    int cri=rand()%10;int cri2=rand()%10;
    int at=rand()%3;int at2=rand()%3;
    iscrit(pk,cri);iscrit(pm,cri2);
    pk->deal=detATK(pk,at);
    pm->deal=detATK(pm,at2);
    if(pk->getSPD()==pm->getSPD()){
        if(rand()%2==0){
            pm->hurt(pk->deal*multiplier(pm->getTYPE(),pk->getTYPE()));
        if((pm->getHP())>0)
            pk->hurt(pm->deal*multiplier(pk->getTYPE(),pm->getTYPE()));
        }else{
                    pk->hurt(pm->deal*multiplier(pk->getTYPE(),pm->getTYPE()));
        if(pk->getHP()>0)
            pm->hurt(pk->deal*multiplier(pm->getTYPE(),pk->getTYPE()));
        }
    }else if(pk->getSPD()>pm->getSPD()){
        pm->hurt(pk->deal*multiplier(pm->getTYPE(),pk->getTYPE()));
        if((pm->getHP())>0)
            pk->hurt(pm->deal*multiplier(pk->getTYPE(),pm->getTYPE()));
    }else /*if(pk->getSPD()<=pm->getSPD())*/
    {
        pk->hurt(pm->deal*multiplier(pk->getTYPE(),pm->getTYPE()));
        if(pk->getHP()>0)
            pm->hurt(pk->deal*multiplier(pm->getTYPE(),pk->getTYPE()));
    };
    wascrit(pk,cri);wascrit(pm,cri2);
    if(pk->getDEF()==10)pk->setDEF(pk->getodf());
    if(pm->getDEF()==10)pm->setDEF(pm->getodf());
    std::cout<<"\n";
    std::cout<<pk->getNAME()<<" hp: "<<showHP(pk)<<std::endl;
    std::cout<<" VS "<<std::endl;
    std::cout<<pm->getNAME()<<" hp: "<<showHP(pm)<<std::endl;
    }while(pk->getHP()>0&&pm->getHP()>0);
    
    if(showHP(pk)<=0&&showHP(pm)<=0)std::cout<<"Dual K.O.\n";
    if(showHP(pm)<=0)return *pk;
    if(showHP(pk)<=0)return *pm;
};

int main(){
    //normal1 fighting2 flying3 poison4 ground5 rock6 bug7 ghost8 steel9 fire10
    //water11 grass12 electric13 psychich14 ice15 dragon16 dark17 rairy18
    pokemon pkms[68];
    pkms[0]=pokemon (((char *)"Bulbasour"),100,10,5,4,3,12);
    pkms[1]=pokemon (((char *)"Ivysour"),150,14,6,3,3,12);
    pkms[2]=pokemon (((char *)"Venasour"),200,17,6,3,3,12);
    pkms[3]=pokemon (((char *)"Pikachu"),50,16,3,8,2,10);
    pkms[67]=pokemon (((char *)"eevee"),70,10,5,5,2,1);
    pokemon *pika=&pkms[3];
    //pika.setTYPE(10);eevee.setTYPE(11);
    //pika.setTYPE(2);eevee.setTYPE(1);
    srand(time(0));
    pokemon WINNER=combat(&pkms[3],&pkms[67]);
    std::cout<<WINNER.getNAME()<<" WINS\n";return 0;}
