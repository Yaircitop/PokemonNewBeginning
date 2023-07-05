int namelen(char name[]){
    int i;
    for(i=1;;i++){
        if(name[i]=='\0')break;
        if(i>11)break;
    }
    return i;
}
void namecpy(char* destination,char* source){
    int i,j;
    for(j=0;j<11;j++){
        destination[j]='\000';///parche curita, llenar con ceros o algo
    }
    for(i=0;i<namelen(source);i++){
        destination[i]=source[i];
    }
}
int calcHP(int BASE,int IV, int LVL,int Nature){
    float EV = 0;
    int stat = ((((2*BASE+IV+((float)EV/4))*(float)LVL)/100)+10+LVL);
    return stat;
}
int calcStat(int BASE,int IV, int LVL,int Nature){
    float EV = 0;
    int stat = ((((2*BASE+IV+((float)EV/4))*(float)LVL)/100)+5)*Nature;
    return stat;
}
void getToLVL(pokemon *pkm,int lvl){
    Dexes temp = PKX[pkm->getPOS()];
    pkm->setohp(calcHP(temp.hp,pkm->getHpIV(),lvl,1));//when we add natures, swap that 1;
    pkm->setHP(pkm->getohp());
    pkm->setoatk(calcStat(temp.atk,pkm->getAtkIV(),lvl,1));
    pkm->setATK(pkm->getoatk());
    pkm->setodef(calcStat(temp.def,pkm->getDefIV(),lvl,1));
    pkm->setDEF(pkm->getodef());
    pkm->setospatk(calcStat(temp.spatk,pkm->getSpAtkIV(),lvl,1));
    pkm->setSPATK(pkm->getospatk());
    pkm->setospdef(calcStat(temp.spdef,pkm->getSpDefIV(),lvl,1));
    pkm->setSPDEF(pkm->getospdef());
    pkm->setospd(calcStat(temp.spd,pkm->getSpdIV(),lvl,1));
    pkm->setSPD(pkm->getospd());
    pkm->setLVL(lvl);
}
int showHP(pokemon *pk){
    return pk->getHP();
}
float typeModifier(int dealer,int receiver){
    float factor;
    switch(receiver){
        case 0:factor=1;
            break;
        case 1:(dealer==2)?factor=2:(dealer==8)?factor=0:factor=1;
            break;
        case 2:(dealer==3||dealer==14||dealer==18)?factor=2:
            (dealer==6||dealer==7||dealer==17)?factor=0.5:factor=1;
            break;
        case 3:(dealer==6||dealer==13||dealer==15)?factor=2:
            (dealer==2||dealer==7||dealer==12)?factor=0.5:(dealer==5)?factor=0:factor=1;
            break;
        case 4:(dealer==5||dealer==14)?factor=2:
            (dealer==2||dealer==4||dealer==7||dealer==12||dealer==18)?factor=0.5:factor=1;
            break;
        case 5:(dealer==11||dealer==12||dealer==15)?factor=2:
            (dealer==4||dealer==6)?factor=0.5:(dealer==13)?factor=0:factor=1;
            break;
        case 6:(dealer==2||dealer==5||dealer==9||dealer==11||dealer==12)?factor=2:
            (dealer==1||dealer==3||dealer==4||dealer==10)?factor=0.5:factor=1;
            break;
        case 7:(dealer==3||dealer==6||dealer==10)?factor=2:
            (dealer==2||dealer==5||dealer==12)?factor=0.5:factor=1;
            break;
        case 8:(dealer==8||dealer==17)?factor=2:
            (dealer==4||dealer==7)?factor=0.5:(dealer==1||dealer==2)?factor=0:factor=1;
            break;
        case 9:(dealer==2||dealer==5||dealer==10)?factor=2:
            (dealer==1||dealer==3||dealer==6||dealer==7||dealer==9||dealer==12||dealer==14||dealer==15||dealer==16||dealer==18)?factor=0.5:factor=1;
            break;
        case 10:(dealer==5||dealer==6||dealer==11)?factor=2:
            (dealer==7||dealer==9||dealer==10||dealer==12||dealer==15||dealer==18)?factor=0.5:factor=1;
            break;
        case 11:(dealer==12||dealer==13)?factor=2:
            (dealer==9||dealer==10||dealer==11||dealer==15)?factor=0.5:factor=1;
            break;
        case 12:(dealer==3||dealer==4||dealer==7||dealer==10||dealer==15)?factor=2:
            (dealer==11||dealer==12||dealer==13)?factor=0.5:factor=1;
            break;
        case 13:(dealer==5)?factor=2:
            (dealer==3||dealer==9||dealer==13)?factor=0.5:factor=1;
            break;
        case 14:(dealer==7||dealer==8||dealer==17)?factor=2:
            (dealer==2||dealer==14)?factor=0.5:factor=1;
            break;
        case 15:(dealer==2||dealer==6||dealer==9||dealer==10)?factor=2:
            (dealer==15)?factor=0.5:factor=1;
            break;
        case 16:(dealer==15||dealer==16||dealer==18)?factor=2:
            (dealer==10||dealer==11||dealer==12||dealer==13)?factor=0.5:factor=1;
            break;
        case 17:(dealer==2||dealer==18)?factor=2:(dealer==7||dealer==8||dealer==17)?factor=0.5:
            (dealer==14)?factor=0:factor=1;
            break;
        case 18:(dealer==4||dealer==9)?factor=2:(dealer==2||dealer==17)?factor=0.5:
            (dealer==16)?factor==0:factor=1;
            break;
        default: factor=1;
            break;
    }
    return factor;
}
float AtkTpeBonus(pokemon pk,int tpeAtk){
    if(pk.getTYPE()==tpeAtk||pk.getTYPE2()==tpeAtk)return 1.2;
    return 1;
}
void usemovement(pokemon *attacker,pokemon *defender,int selectedMove){
    //modifier will be 1 for now
    if(accuracyCheck(attacker->precision,attacker->moves[selectedMove].getPres(),defender->evasion,1)){
        attacker->moves[selectedMove].use(attacker,defender);
    }else{
        printf("%s attack missed!\n",attacker->getNAME());
    }
}
float calc_Max_damage(){
    return 0;
}
float calc_Min_damage(){
    return 0;
}
float calc_damage(pokemon attacker,pokemon defender,int Power,int Targets,int tpeAtk,int category){
//Targets=amount of targets ;
//not added yet: Weather & other(conditional multipliers like earthquake into dig)
    if(Targets==2){(float)Targets;Targets=0.75;}
    float randomModifier = (rand()%16+85)/(float)100;
    float STAB = AtkTpeBonus(attacker,tpeAtk);
    float TypeMultiplier = typeModifier(tpeAtk,defender.getTYPE())*typeModifier(tpeAtk,defender.getTYPE2());
    float PowerRatio = (float)Power/50;
    float BURN = 1;
    float AtkDefRatio;
    float Crit = 1;
    if(tpeAtk!=0 && rand()%100<attacker.getCRIT())Crit = 1.5;
    //if CRITICAL has to use ogstats
    if(category==0){//physical
        if(attacker.is_burned==true)BURN=0.5;
        if(Crit!=1)AtkDefRatio = (float)attacker.getoatk()/defender.getodef();
        else AtkDefRatio = (float)attacker.getATK()/defender.getDEF();
    }else if(category==1){//ranged
        if(Crit!=1)AtkDefRatio = (float)attacker.getospatk()/defender.getospdef();
        else AtkDefRatio = (float)attacker.getSPATK()/defender.getSPDEF();
    }
    float damage=((attacker.getLVL()*2/5)+2);
    damage*=AtkDefRatio;
    damage*=PowerRatio;
    damage+=2;
    damage*=Targets;
    damage*=randomModifier;
    damage*=STAB;
    damage*=TypeMultiplier;
    damage*=BURN;
    damage*=Crit;
    return damage;
}
bool statusCheck(pokemon *pkm){
    if(pkm->is_asleep){//animation of being asleep
        pkm->turnsAsleep++;
        if(pkm->turnsAsleep==1){
            if(4<pkm->turnsAsleep||rand()%32<12){//animation of weaking up
                pkm->is_asleep=false;
                pkm->turnsAsleep = 0;
            }else{
                //add animation of sleeping
                return true;
            }
        }else{
            //animation of sleeping
            return true;
        }
    
    }
    if(pkm->is_frozen){//animation of being frozen
        if(rand()%255<51){
            pkm->is_frozen=false;
        }else{//animation of being frozen
            return true;
        }
    }
    if(pkm->is_paralyzed){//animation of being paralized
        if(rand()%255<64){
            pkm->is_paralyzed=false;
            pkm->setSPD((float)pkm->getSPD()*4/3);
        }else{//animation of being paralized
            return true;
        }
    }
    if(pkm->is_confused){//animation of being confused
        pkm->turnsConfused++;
        if(1<pkm->turnsConfused){//animation of being asleep
            if(3<pkm->turnsConfused||rand()%32<16){//animation of weaking up
                pkm->is_confused=false;
                pkm->turnsConfused = 0;
                return false;
            }else{
                //display that it hit itself in its confusion
                pkm->setHP(pkm->getHP()-calc_damage(*pkm,*pkm,40,1,0,0));
                return true;
            }
        }else{
            //display that it hit itself in its confusion
            pkm->setHP(pkm->getHP()-calc_damage(*pkm,*pkm,40,1,0,0));
            return true;
        }
    }
    return false;
}
//accuracy is the attackers accuracy and evasion is the defender evasion
//both start at 100
int accuracyCheck(int precision,int accuracy,int evasion,int modifier){
    int threshold = precision*((float)accuracy/100)*((float)evasion/100)*modifier;
    int got = rand()%101;
    if(got<threshold)return 1;
    return 0;
}
/*void apply_paralysis(pokemon defender){
    if(rand() < 0.1)defender.is_paralyzed = true;
}*/
void assignDefaultMoves(Person * npc){
    int i;
    for(i=0;i<6;i++){
        if(npc->team[i]==NULL)return;
        npc->team[i]->moves[0]=move_list[19];
        npc->team[i]->moves[1]=move_list[1];
        npc->team[i]->moves[2]=move_list[2];
        npc->team[i]->moves[3]=move_list[11];
    }
}
void swapPokePlaces(pokemon **poke1,pokemon **poke2){
    pokemon * tempPoke = *poke1;
    *poke1 = *poke2;
    *poke2 = tempPoke;
//    copyPoke(tempPoke,poke1);
//    copyPoke(poke1,poke2);
//    copyPoke(*poke2,tempPoke);
    //poke2 = false;
    //reset volatile stats
}
void showTeam(Person * npc){
    int i;
    printf("Team:\n");
    for(i=0;i<6;i++){
        if(npc->team[i]==NULL)break;
        printf("%d) Name: %s Hp: %d\n",i+1,npc->team[i]->getNAME(),npc->team[i]->getHP());
        printf("%s PP:%d %s PP:%d\n%s PP:%d %s PP:%d\n",
            npc->team[i]->moves[0].getName(),npc->team[i]->moves[0].getPP(),
            npc->team[i]->moves[1].getName(),npc->team[i]->moves[1].getPP(),
            npc->team[i]->moves[2].getName(),npc->team[i]->moves[2].getPP(),
            npc->team[i]->moves[3].getName(),npc->team[i]->moves[3].getPP());
    }
}
int teamMemberStillHasHealth(Person * npc){
    int isAlive = 0;
    int i;
    for(i=0;i<6;i++){
        if(npc->team[i]==NULL)break;
        if(npc->team[i]->getHP()>0)isAlive=1;
    }
    return isAlive;
}
bool npcPokeFainted(Person *npc,Player *player){
    pokemon *tempPoke = NULL;
    float TypeMultiplier = 0;
    if(npc->team[1]!=NULL && 0<npc->team[1]->getHP()){
        //animation and text for the change
        int multiplier= typeModifier(npc->team[1]->getTYPE(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[1]->getTYPE2(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[1]->getTYPE(),player->team[0]->getTYPE2())+
                        typeModifier(npc->team[1]->getTYPE2(),player->team[0]->getTYPE2());
        if(TypeMultiplier<multiplier){
            TypeMultiplier = multiplier;
            tempPoke = npc->team[1];
        }
    }
    if(npc->team[2]!=NULL && 0<npc->team[2]->getHP()){
        //animation and text for the change
        int multiplier= typeModifier(npc->team[2]->getTYPE(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[2]->getTYPE2(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[2]->getTYPE(),player->team[0]->getTYPE2())+
                        typeModifier(npc->team[2]->getTYPE2(),player->team[0]->getTYPE2());
        if(TypeMultiplier<multiplier){
            TypeMultiplier = multiplier;
            tempPoke = npc->team[2];
        }
    }
    if(npc->team[3]!=NULL && 0<npc->team[3]->getHP()){
        //animation and text for the change
        int multiplier= typeModifier(npc->team[3]->getTYPE(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[3]->getTYPE2(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[3]->getTYPE(),player->team[0]->getTYPE2())+
                        typeModifier(npc->team[3]->getTYPE2(),player->team[0]->getTYPE2());
        if(TypeMultiplier<multiplier){
            TypeMultiplier = multiplier;
            tempPoke = npc->team[3];
        }
    }
    if(npc->team[4]!=NULL && 0<npc->team[4]->getHP()){
    //animation and text for the change
        int multiplier= typeModifier(npc->team[4]->getTYPE(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[4]->getTYPE2(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[4]->getTYPE(),player->team[0]->getTYPE2())+
                        typeModifier(npc->team[4]->getTYPE2(),player->team[0]->getTYPE2());
        if(TypeMultiplier<multiplier){
            TypeMultiplier = multiplier;
            tempPoke = npc->team[4];
        }
    }
    if(npc->team[5]!=NULL && 0<npc->team[5]->getHP()){
    //animation and text for the change
        int multiplier= typeModifier(npc->team[5]->getTYPE(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[5]->getTYPE2(),player->team[0]->getTYPE())+
                        typeModifier(npc->team[5]->getTYPE(),player->team[0]->getTYPE2())+
                        typeModifier(npc->team[5]->getTYPE2(),player->team[0]->getTYPE2());
        if(TypeMultiplier<multiplier){
            TypeMultiplier = multiplier;
            tempPoke = npc->team[5];
        }
    }
    if(tempPoke!=NULL){
        swapPokePlaces(&npc->team[0],&tempPoke);
        return false;
    }
    return true;
}
void showAvailableMoves(Player *player){
    printf("0:%s %d PP | 1:%s %d PP | 2:%s %d PP | 3:%s %d PP\n",
    player->team[0]->moves[0].getName(),player->team[0]->moves[0].getPP(),
    player->team[0]->moves[1].getName(),player->team[0]->moves[1].getPP(),
    player->team[0]->moves[2].getName(),player->team[0]->moves[2].getPP(),
    player->team[0]->moves[3].getName(),player->team[0]->moves[3].getPP());
}
bool hasPP(Player *player){
    if(player->team[0]->moves[0].getPP()==0 
    && player->team[0]->moves[1].getPP()==0 
    && player->team[0]->moves[2].getPP()==0 
    && player->team[0]->moves[3].getPP()==0){
        return false;
    }
    return true;
}
int playerSwap(Person * npc){
    int flag = 1;
    int input;
    while(flag){
        input = 1;
        printf("choose which pokemon to switch with ");
        scanf("%d",&input);
        input--;
            switch(input){
        case 1:
            if(npc->team[input]==NULL){
                printf("That space is vacant!\n");
                break;
            }
            if(npc->team[input]->getHP()>0){
                swapPokePlaces(&npc->team[0],&npc->team[input]);
                return 0;
            }
            printf("That pokemon has fainted!\n");
            break;
        case 2:
            if(npc->team[input]==NULL){
                printf("That space is vacant!\n");
                break;
            }
            if(npc->team[input]->getHP()>0){
                swapPokePlaces(&npc->team[0],&npc->team[input]);
                return 1;
            }
            printf("That pokemon has fainted!\n");
            break;
        case 3:
            if(npc->team[input]==NULL){
                printf("That space is vacant!\n");
                break;
            }
            if(npc->team[input]->getHP()>0){
                swapPokePlaces(&npc->team[0],&npc->team[input]);
                return 1;
            }
            printf("That pokemon has fainted!\n");
            break;
        case 4:
            if(npc->team[input]==NULL){
                printf("That space is vacant!\n");
                break;
            }
            if(npc->team[input]->getHP()>0){
                swapPokePlaces(&npc->team[0],&npc->team[input]);
                return 1;
            }
            printf("That pokemon has fainted!\n");
            break;
        case 5:
            if(npc->team[input]==NULL){
                printf("That space is vacant!\n");
                break;
            }
            if(npc->team[input]->getHP()>0){
                swapPokePlaces(&npc->team[0],&npc->team[input]);
                return 1;
            }
            printf("That pokemon has fainted!\n");
            break;
        case 6:
            if(npc->team[input]==NULL){
                printf("That space is vacant!\n");
                break;
            }
            if(npc->team[input]->getHP()>0){
                swapPokePlaces(&npc->team[0],&npc->team[input]);
                return 1;
            }
            printf("That pokemon has fainted!\n");
            break;
        default:
            scanf("%d",&input);
            printf("back to previous menu\n");
            flag = 0;
            break;
        }
    }
    return 0;
}
int swapOffer(Person * npc){
    if(!teamMemberStillHasHealth(npc)){
        printf("No more pokemon's available!\n%s faint from the shock of losing...\n",
            npc->getName());
        return 0;
    }
    showTeam(npc);
    if(playerSwap(npc))return 1;
    return -1;
}
int checkStatuses(Person * player){
        if(player->team[0]->is_burned){//animation
            printf("%s is sufering from it's burn!\n");
            player->team[0]->setHP(player->team[0]->getHP()-((float)player->team[0]->getohp()/16));
        }
        if(player->team[0]->getHP()<1){
            printf("%s pokemon fainted!\n\n",player->getName());
            if(!swapOffer(player)){
                printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                    player->getName());
                return 1;
            }
        }
        if(player->team[0]->is_badlyPoisoned){//animation
            printf("%s is sufering from it's poison!\n");
            player->team[0]->setHP(player->team[0]->getHP()-((float)player->team[0]->getohp()/16));
        }else{
            if(player->team[0]->is_poisoned){//animation
                printf("%s is sufering from it's poison!\n");
                player->team[0]->setHP(player->team[0]->getHP()-((float)player->team[0]->getohp()/16));
            }        
        }
        if(player->team[0]->getHP()<1){
            printf("%s pokemon fainted!\n\n",player->getName());
            if(!swapOffer(player)){
                printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                    player->getName());
                return 1;
            }
        }
        return 0;
}
int chooseMove(Player *player,Person *npc){//return 0:normal return 1:battle ended
    int input;
    if(!hasPP(player)){
        //no PP available at ALL, offer only the movement "Struggle"
        printf("0:Struggle\n");
        scanf("%d",&input);
        if(input==0){
            //use struggle
            if(statusCheck(player->team[0]))return 1;
            float damage = calc_damage(*player->team[0],*npc->team[0],50,1,0,0);
            npc->team[0]->setHP(npc->team[0]->getHP()-damage);
            player->team[0]->setHP(player->team[0]->getHP()-(damage*1/4));
            if(player->team[0]->getHP()<1){
                //offer change the poke
                if(!swapOffer(player))return 1;
                //if no poke available, go to black animation
            }
        }
        return 0;
    }

    //show moveset - name and PP
    showAvailableMoves(player);
    scanf("%d",&input);
    if(input!=0 && input!=1 && input!=2 && input!=3){
        printf("invalid input\n");
        return 0;
    }
    printf("you chose %s\n",player->team[0]->moves[input].getName());
    if(statusCheck(player->team[0])){
        printf("statusCheck failed!\n");
        return 1;
    }
    //0 no one died 1 player pokemon died 2 npc poke died    
    switch(input){
        case 0://choose a move
        case 1:
        case 2:
        case 3:
        if(player->team[0]->moves[input].getPP()<1){
            //no PP available, ask for another move
            printf("no PP!\n");
            return 0;
        }
        usemovement(player->team[0],npc->team[0],input);
        //animation and text of the movement
        if(npc->team[0]->getHP()<1){
            printf("npc pokemon fainted!\n\n");
            if(npcPokeFainted(npc,player)){//if no poke available
                //reward and end of battle animation
                int j = (rand()%npc->money/2)+npc->money/2;
                printf("All of %s pokemon's have fainted!\nEnd of battle, you steal %d from %s.",
                    j,npc->getName());
                npc->money-=j;
                player->money+=j;
                return 1;//out of combat, lets go back to the map
            }
        }else{
            int ran = rand()%4;
            printf("npc used %s\n",npc->team[0]->moves[ran].getName());
            usemovement(npc->team[0],player->team[0],ran);
        }
        if(player->team[0]->getHP()<1){
            printf("%s pokemon fainted!\n\n",player->getName());
            if(!swapOffer(player)){
                printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                    player->getName());
                return 1;
            }
        }
        if(player->team[0]->is_burned){//animation
            printf("%s is sufering from it's burn!\n");
            player->team[0]->setHP(player->team[0]->getHP()-((float)player->team[0]->getohp()/16));
        }
        if(player->team[0]->getHP()<1){
            printf("%s pokemon fainted!\n\n",player->getName());
            if(!swapOffer(player)){
                printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                    player->getName());
                return 1;
            }
        }
        if(player->team[0]->is_badlyPoisoned){//animation
            printf("%s is sufering from it's poison!\n");
            player->team[0]->setHP(player->team[0]->getHP()-((float)player->team[0]->getohp()/16));
        }else{
            if(player->team[0]->is_poisoned){//animation
                printf("%s is sufering from it's poison!\n");
                player->team[0]->setHP(player->team[0]->getHP()-((float)player->team[0]->getohp()/16));
            }        
        }
        if(player->team[0]->getHP()<1){
            printf("%s pokemon fainted!\n\n",player->getName());
            if(!swapOffer(player)){
                printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                    player->getName());
                return 1;
            }
        }
        return 0;
        default:
            printf("default return\n");
            return 0;
    }
}
int usersChoseMoves(Player * user1,int input1,Player * user2,int input2){
    Player * fast;
    Player * slow;
    int inputF,inputS;
    if(user1->team[0]->getSPD()<user2->team[0]->getSPD()){
        fast = user2;
        slow = user1;
        inputF = input2;
        inputS = input1;
    }else{
        fast = user1;
        slow = user2;
        inputF = input1;
        inputS = input2;
    }
    int flag = 0;
    printf("%s used %s\n",fast->getName(),fast->team[0]->moves[inputF].getName());
    usemovement(fast->team[0],slow->team[0],inputF);
    //animation and text of the movement
    if(slow->team[0]->getHP()<1){
        printf("%s pokemon fainted!\n\n",slow->getName());
        if(!swapOffer(slow)){
            printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                slow->getName());
            flag = 1;
        }
    }
    if(!flag){
        printf("%s used %s\n",slow->getName(),slow->team[0]->moves[inputS].getName());
        usemovement(slow->team[0],fast->team[0],inputS);
    }
    if(fast->team[0]->getHP()<1){
        printf("%s pokemon fainted!\n\n",fast->getName());
        if(!swapOffer(fast)){
            printf("All of %s pokemon's have fainted!\nEnd of the Match!\n",
                fast->getName());
            flag = 1;
        }
    }
    if(checkStatuses(fast))
        flag = 1;
    if(checkStatuses(slow))
        flag = 1;
    return flag;
}
void battle(Player *user1,Player *user2){
    static int turn = 1;
    int input1;
    int input2;
    int flag;
    int bs = 1;
    while(true){
        bs = 1;
        if(bs){
            printf("%s's pokemon: %s %dhp",user1->getName(),user1->team[0]->getNAME(),user1->team[0]->getHP());
            printf(" :: ");
            printf("%s's pokemon: %s %dhp\n",user2->getName(),user2->team[0]->getNAME(),user2->team[0]->getHP());
            bs = 0;
        }
        flag = 1;
        while(flag){
            printf("chose 0 to chose a moveset, 1 to see your team and 3 to flee. '4'to exit\n");
            printf("%s please choose your action ",user1->getName());
            scanf("%d",&input1);
            switch(input1){
                case 0:
                //show moves
                    showAvailableMoves(user1);
                    scanf("%d",&input1);
                    if(user1->team[0]->moves[input1].getPP()<1&&0<=input1<4){
                        //no PP available, ask for another move
                        printf("no PP!\n");
                    }else{
                    flag = 0;
                    break;
                    }
                    break;
                case 1:
                    if(swapOffer(user1))
                        flag=0;
                    bs = 1;
                    break;
                case 2:
                    printf("We are sorry, this feature will be coming SOON(TM)\n");
                    bs = 1;
                    break;
                case 3:
                    printf("You cant run away during a duel against another user!\n");
                    bs = 1;
                    break;
                case 4:
                    input1 = 4;
                    return;
                default:
                    bs = 1;
                    printf("please enter a valid input ");
                    scanf("%d",&input1);
            }
        }
        if(bs){
            printf("%s's pokemon: %s %dhp",user1->getName(),user1->team[0]->getNAME(),user1->team[0]->getHP());
            printf(" :: ");
            printf("%s's pokemon: %s %dhp\n",user2->getName(),user2->team[0]->getNAME(),user2->team[0]->getHP());
            bs = 0;
        }
        flag = 1;
        while(flag){
            printf("chose 0 to chose a moveset, 1 to see your team and 3 to flee\n");
            printf("%s please choose your action ",user2->getName());
            scanf("%d",&input2);
            switch(input2){
                case 0:
                    showAvailableMoves(user2);
                    scanf("%d",&input2);
                    if(user2->team[0]->moves[input2].getPP()<1&&0<=input2<4){
                        //no PP available, ask for another move
                        printf("no PP!\n");
                    }else{
                    flag = 0;
                    break;
                    }
                    break;
                case 1:
                    if(swapOffer(user2))
                        flag=0;
                    break;
                case 2:
                    printf("We are sorry, this feature will be coming SOON(TM)\n");
                    bs = 1;
                    break;
                case 3:
                    printf("You cant run away during a duel against another user!\n");
                    bs = 1;
                    break;
                case 'x':
                    input2 = 'x';
                    return;
                default:
                    bs = 1;
                    printf("please enter a valid input ");
                    scanf("%d",&input2);
            }
        }
        if(usersChoseMoves(user1,input1,user2,input2))return;
    }
}
void battle(Player *player,Person *npc){
    static int turn = 1;
    //create UI;
    int input; //input from player
    int selectedMove;
    int npcPos = 0;
    while(true){
        printf("%s's pokemon: %s %dhp",player->getName(),player->team[0]->getNAME(),player->team[0]->getHP());
        printf(" :: ");
        printf("%s's pokemon: %s %dhp\n",npc->getName(),npc->team[0]->getNAME(),npc->team[0]->getHP());
        printf("chose 0 to chose a moveset, 1 to see your team and 3 to flee\n");
        scanf("%d",&input);
        switch(input){
            case 0://choose a move
                if(chooseMove(player,npc)==1){
                    turn++;
                    return;
                };
                break;
            case 1://show team and info and allow change poke, ends turn
                swapOffer(player);
                break;
            case 2://show bag
                break;
            case 3: //flee like the coward you are
                turn = 1;
                return;
            default://do nothing
                scanf("%d",&input);
                break;
        }
    }
}
void wildBattle(Player *player){
    pokemon tempPoke(PKX[rand()%155]);
    Person tempPerson(0,&tempPoke);
    battle(player,&tempPerson);
}
void asignRandomTeam(Person * npc,int size){
    int i;
    if(size>6)size=6;
    for(i=0;i<size;i++){
        pokemon * temp = new pokemon(PKX[rand()%150+1],30);
        npc->team[i]=temp;
    }
}
void healTeamFully(Player *player){
    int i=0;
    for(i;i<6;i++){
        player->team[i]->setHP(player->team[i]->getohp());
    }
};
// -6  -5  -4  -3  -2  -1   0  +1  +2  +3  +4  +5  +6
// 2/8 2/7 2/6 2/5 2/4 2/3 2/2 3/2 4/2 5/2 6/2 7/2 8/2
void modifyAtkStage(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<incrementBy){
        while(0<incrementBy){
            float increment = (float)pkm->getoatk()*1/2;
            float setAs = pkm->getATK()+increment;
            if(setAs < pkm->getoatk()*4){
                pkm->setATK(setAs);
            }else{
                printf("Already at max!\n");
                return;
            }
            incrementBy--;
        }
    }
    if(0<decrementBy){
        while(0<decrementBy){
            int actAtk = pkm->getATK();
            int ogAtk = pkm->getoatk();
            if(actAtk == ogAtk*2/2){
                pkm->setATK(ogAtk*2/3);
            }else 
            if(actAtk == ogAtk*2/3){
                pkm->setATK(ogAtk*2/4);
            }else
            if(actAtk == ogAtk*2/4){
                pkm->setATK(ogAtk*2/5);
            }else
            if(actAtk == ogAtk*2/5){
                pkm->setATK(ogAtk*2/6);
            }else
            if(actAtk == ogAtk*2/6){
                pkm->setATK(ogAtk*2/7);
            }else
            if(actAtk == ogAtk*2/7){
                pkm->setATK(ogAtk*2/8);
            }else
            if(actAtk == ogAtk*2/8){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            decrementBy--;
        }
    }
}
void modifyDefStage(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<incrementBy){
        while(0<incrementBy){
            float increment = (float)pkm->getodef()*1/2;
            float setAs = pkm->getDEF()+increment;
            if(setAs < pkm->getodef()*4){
                pkm->setDEF(setAs);
            }else{
                printf("Already at max!\n");
                return;
            }
            incrementBy--;
        }
    }
    if(0<decrementBy){
        while(0<decrementBy){
            int actDef = pkm->getDEF();
            int ogDef = pkm->getodef();
            if(actDef == ogDef*2/2){
                pkm->setDEF(ogDef*2/3);
            }else 
            if(actDef == ogDef*2/3){
                pkm->setDEF(ogDef*2/4);
            }else
            if(actDef == ogDef*2/4){
                pkm->setDEF(ogDef*2/5);
            }else
            if(actDef == ogDef*2/5){
                pkm->setATK(ogDef*2/6);
            }else
            if(actDef == ogDef*2/6){
                pkm->setATK(ogDef*2/7);
            }else
            if(actDef == ogDef*2/7){
                pkm->setDEF(ogDef*2/8);
            }else
            if(actDef == ogDef*2/8){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            decrementBy--;
        }
    }
}
void modifySpAtkStage(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<incrementBy){
        while(0<incrementBy){
            float increment = (float)pkm->getospatk()*1/2;
            float setAs = pkm->getSPATK()+increment;
            if(setAs < pkm->getospatk()*4){
                pkm->setSPATK(setAs);
            }else{
                printf("Already at max!\n");
                return;
            }
            incrementBy--;
        }
    }
    if(0<decrementBy){
        while(0<decrementBy){
            int actSpAtk = pkm->getSPATK();
            int ogSpAtk = pkm->getospatk();
            if(actSpAtk == ogSpAtk*2/2){
                pkm->setSPATK(ogSpAtk*2/3);
            }else 
            if(actSpAtk == ogSpAtk*2/3){
                pkm->setSPATK(ogSpAtk*2/4);
            }else
            if(actSpAtk == ogSpAtk*2/4){
                pkm->setSPATK(ogSpAtk*2/5);
            }else
            if(actSpAtk == ogSpAtk*2/5){
                pkm->setATK(ogSpAtk*2/6);
            }else
            if(actSpAtk == ogSpAtk*2/6){
                pkm->setATK(ogSpAtk*2/7);
            }else
            if(actSpAtk == ogSpAtk*2/7){
                pkm->setSPATK(ogSpAtk*2/8);
            }else
            if(actSpAtk == ogSpAtk*2/8){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            decrementBy--;
        }
    }
}
void modifySpDefStage(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<incrementBy){
        while(0<incrementBy){
            float increment = (float)pkm->getospdef()*1/2;
            float setAs = pkm->getSPDEF()+increment;
            if(setAs < pkm->getospdef()*4){
                pkm->setSPDEF(setAs);
            }else{
                printf("Already at max!\n");
                return;
            }
            incrementBy--;
        }
    }
    if(0<decrementBy){
        while(0<incrementBy){
            int actSpDef = pkm->getSPDEF();
            int ogSpDef = pkm->getospdef();
            if(actSpDef == ogSpDef*2/2){
                pkm->setSPDEF(ogSpDef*2/3);
            }else 
            if(actSpDef == ogSpDef*2/3){
                pkm->setSPDEF(ogSpDef*2/4);
            }else
            if(actSpDef == ogSpDef*2/4){
                pkm->setSPDEF(ogSpDef*2/5);
            }else
            if(actSpDef == ogSpDef*2/5){
                pkm->setSPDEF(ogSpDef*2/6);
            }else
            if(actSpDef == ogSpDef*2/6){
                pkm->setSPDEF(ogSpDef*2/7);
            }else
            if(actSpDef == ogSpDef*2/7){
                pkm->setSPDEF(ogSpDef*2/8);
            }else
            if(actSpDef == ogSpDef*2/8){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            decrementBy--;
        }
    }
}
void modifySpdStage(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<incrementBy){
        while(0<incrementBy){
            float increment = (float)pkm->getospd()*1/2;
            float setAs = pkm->getSPD()+increment;
            if(setAs < pkm->getospd()*4){
                pkm->setSPD(setAs);
            }else{
                printf("Already at max!\n");
                return;
            }
            incrementBy--;
        }
    }
    if(0<decrementBy){
        while(0<incrementBy){
            int actSpd = pkm->getSPD();
            int ogSpd = pkm->getospd();
            if(actSpd == ogSpd*2/2){
                pkm->setSPD(ogSpd*2/3);
            }else 
            if(actSpd == ogSpd*2/3){
                pkm->setSPD(ogSpd*2/4);
            }else
            if(actSpd == ogSpd*2/4){
                pkm->setSPD(ogSpd*2/5);
            }else
            if(actSpd == ogSpd*2/5){
                pkm->setSPD(ogSpd*2/6);
            }else
            if(actSpd == ogSpd*2/6){
                pkm->setSPD(ogSpd*2/7);
            }else
            if(actSpd == ogSpd*2/7){
                pkm->setSPD(ogSpd*2/8);
            }else
            if(actSpd == ogSpd*2/8){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            decrementBy--;
        }
    }
}
void modifyAccuracy(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<incrementBy){
        while(0<incrementBy){
            float increment = (float)pkm->precision*1/3;
            float setAs = pkm->precision + increment;
            if(setAs<400){
                pkm->precision = setAs;
            }else{
                printf("Already at max!\n");
                return;
            }
            incrementBy--;
        }
    }
    if(0<decrementBy){
        while(0<decrementBy){
            if(pkm->precision == 300/3){
                pkm->precision=(300/4);
            }else 
            if(pkm->precision == 300/4){
                pkm->precision=(300/5);
            }else
            if(pkm->precision == 300/5){
                pkm->precision=(300/6);
            }else
            if(pkm->precision == 300/6){
                pkm->precision=(300/7);
            }else
            if(pkm->precision == 300/7){
                pkm->precision=(300/8);
            }else
            if(pkm->precision == 300/8){
                pkm->precision=(300/9);
            }else
            if(pkm->precision == 300/9){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            decrementBy--;
        }
    }
}
void modifyEvasion(pokemon *pkm,int incrementBy,int decrementBy){
    if(0<decrementBy){
        while(0<decrementBy){
            float decrement = (float)pkm->evasion*1/3;
            float setAs = pkm->precision + decrement;
            if(setAs<400){
                pkm->evasion = setAs;
            }else{
                printf("Already at max!\n");
                return;
            }
            decrementBy--;
        }
    }
    if(0<incrementBy){
        while(0<incrementBy){
            if(pkm->evasion == 300/3){
                pkm->evasion=(300/4);
            }else 
            if(pkm->evasion == 300/4){
                pkm->evasion=(300/5);
            }else
            if(pkm->evasion == 300/5){
                pkm->evasion=(300/6);
            }else
            if(pkm->evasion == 300/6){
                pkm->evasion=(300/7);
            }else
            if(pkm->evasion == 300/7){
                pkm->evasion=(300/8);
            }else
            if(pkm->evasion == 300/8){
                pkm->evasion=(300/9);
            }else
            if(pkm->evasion == 300/9){
                printf("Already at Min!\n");
            }else
            {
                printf("error at modifyStat-Decrement-\n");
            }
            //preguntar por comparacion en que etapa esta
            incrementBy--;
        }
    }
};
