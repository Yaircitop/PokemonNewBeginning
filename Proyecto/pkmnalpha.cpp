#include"pkmnHeader.h" //movement.h doesnt like not having the include itself
#include"movement.h"
#include"MovementList.h"
#include"pokedex.h"
#include"pkmnalpha.h"

int main(){
    srand(time(0));
    //normal1 fighting2 flying3 poison4 ground5 rock6 bug7 ghost8 steel9 fire10
    //water11 grass12 electric13 psychich14 ice15 dragon16 dark17 fairy18
//    int maxpkx=PKX[];
    printf("Welcome to Pokemon New Beginnings!\n\n");
    printf("press 'D' to have a random Duel against the cpu\n"
        "'P' to have a PvP local match\n"
        "'X' to close the program.\n");
    char input = '0';
    while(1){
        scanf("%c",&input);
        switch(input){
            case 'd':
            case 'D':
                {
                Player * P1 = new Player(10,NULL,NULL,NULL,NULL,NULL,NULL);
                Person * npc = new Person();
                P1->setName("You");
                npc->setName("Rival");
                asignRandomTeam(P1,3);
                asignRandomTeam(npc,3);
                assignDefaultMoves(P1);
                assignDefaultMoves(npc);
                battle(P1,npc);
                }
                break;
            case 'p':
            case 'P'://do stuff
                {
                int size = 0;
                printf("choose the size (up to 6) of the teams ");
                while(size!=1&&size!=2&&size!=3&&size!=4&&size!=5&&size!=6){
                    scanf("%d",&size);
                }
                Player * P1 = new Player(10,NULL,NULL,NULL,NULL,NULL,NULL);
                Player * npc = new Player();
                P1->setName("Player_1");
                npc->setName("Player_2");
                asignRandomTeam(P1,size);
                asignRandomTeam(npc,size);
                assignDefaultMoves(P1);
                assignDefaultMoves(npc);
                battle(P1,npc);
                }
                return 0;
                break;
            case 'x':
            case 'X':
                return 0;
                break;
            default:
                break;
        }
    }
/*    int a,b,c,d,e,f,g,h,i;
    a=rand()%150+1;
    pokemon a1(PKX[a],50);
    pokemon a2(PKX[b],50);
    pokemon a3(PKX[c],50);
    pokemon a4(PKX[d]);
    pokemon a5(PKX[e]);
    pokemon a6(PKX[f]);
    pokemon a7(PKX[g]);
    pokemon a8(PKX[h]);
    pokemon a9(PKX[i]);

    Person player1(5,&a7,&a8,&a9);
    Player player2(10,&a1,&a2,&a6,&a4,&a5,&a6);

//    getToLVL(&a1,50);
//    getToLVL(&a2,50);
//    getToLVL(&a3,50);
    getToLVL(&a4,50);
    getToLVL(&a5,50);
    getToLVL(&a6,30);
    getToLVL(&a7,50);
    getToLVL(&a8,50);
    getToLVL(&a9,50);

    a1.moves[0]=move_list[19];
    a1.moves[1]=move_list[1];
    a1.moves[2]=move_list[2];
    a1.moves[3]=move_list[11];

    a3.moves[0]=move_list[19];
    a3.moves[1]=move_list[1];
    a3.moves[2]=move_list[2];
    a3.moves[3]=move_list[11];
    
    a7.moves[0]=move_list[19];
    a7.moves[1]=move_list[1];
    a7.moves[2]=move_list[2];
    a7.moves[3]=move_list[11];
    
    for(int i=0;i<6;i++){
        printf("pokemon nº%d: %s\n",i+1,player2.team[i]->getNAME());
    }
    
    battle(&player2,&player1);
*/
    return 0;}