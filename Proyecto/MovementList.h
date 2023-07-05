////////// templates could have made this easier

/*void use_thunderbolt(pokemon attacker,pokemon defender){
    attacker.atkPointer.PP -= 1;
    calculate_damage(attacker,defender);
    apply_paralysis(defender);
    //play animations
}*/
////////// movement functions area
void fake(pokemon *del,pokemon *rec){;}
void absorb(pokemon *dealer,pokemon *receiver){
    int power = 20,precision = 100,type = 12,category = 1;//0-physical 1-special 2-statuc
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
    dealer->setHP(dealer->getHP()+(damage+1)/2);
    printf("%s did %f damage to %s\n",dealer->getNAME(),damage,receiver->getNAME());
    printf("%s healed for %f\n",dealer->getNAME(),damage);
}
void acid(pokemon *dealer,pokemon *receiver){
    int power = 40,precision = 100,type = 4,category = 1;//0-physical 1-special 2-status
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
    printf("%s did %f damage to %s\n",dealer->getNAME(),damage,receiver->getNAME());
}
void acidArmor(pokemon *dealer,pokemon *receiver){
    int power = 40,precision = 100,type = 4,category = 1;//0-physical 1-special 2-status
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
    printf("%s did %f damage to %s\n",dealer->getNAME(),damage,receiver->getNAME());
}
void agility(pokemon *dealer,pokemon *receiver){
    int power = 40,precision = 100,type = 4,category = 1;//0-physical 1-special 2-status
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
}
void amnesia(pokemon *dealer,pokemon *receiver){
    int power = 40,precision = 100,type = 4,category = 1;//0-physical 1-special 2-status
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
}
void auroraBeam(pokemon *dealer,pokemon *receiver){
    int power = 40,precision = 100,type = 4,category = 1;//0-physical 1-special 2-status
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
    printf("%s did %f damage to %s\n",dealer->getNAME(),damage,receiver->getNAME());
}
void bite(pokemon *dealer,pokemon *receiver){
    int power = 60,precision = 100,type = 17,category = 0;//0-physical 1-special 2-status
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
    printf("%s did %f damage to %s\n",dealer->getNAME(),damage,receiver->getNAME());
}

void scratch(pokemon *dealer,pokemon *receiver){
    int power = 20,precision = 100,type = 1,category = 0;//0-physical 1-special 2-status
    bool priority = 0;//0-non 1-has
    float damage = calc_damage(*dealer,*receiver,power,1,type,category);
    receiver->setHP(receiver->getHP()-damage);
    printf("%s did %f damage to %s\n",dealer->getNAME(),damage,receiver->getNAME());
}
                           //accuracy tpe prio
                    //    ,pwr,   ,PP   cat   ptr
Movement move_list[165]={
    Movement("Missing"    ,  0,100, 0, 0,0,0,Fake),

    Movement("Absorb"     , 20,100,25,10,1,0,Absorb),
    Movement("Acid"       , 40,100,30, 4,1,0,Acid),
    Movement("Acid Armor" , 0,1000,20, 4,2,0,AcidArmor),
    Movement("Agility"    , 0,1000,30,14,2,0,Agility),
    Movement("Amnesia"    , 0,1000,20,14,2,0,Amnesia),
    Movement("Aurora Beam", 65,100,20,15,1,0,AuroraBeam),

    Movement("Barrage"    , 15, 85,20, 1,0,0,Barrage),
    Movement("Barrier"    , 0,1000,20,14,2,0,Barrier),
    Movement("Bide"       , 0,1000,10, 1,0,1,Bide),
    Movement("Bind"       , 15, 85,20, 1,0,0,Bind),
    Movement("Bite"       , 60,100,25,17,0,0,Bite),
    Movement("Blizzard"   ,110, 70, 5,15,1,0,Blizzard),
    Movement("Body Slam"  , 85,100,15, 1,0,0,BodySlam),
    Movement("Bone Club"  , 65, 85,20, 5,0,0,BoneClub),
    Movement("Bonemerang" , 50, 90,10, 5,0,0,Bonemerang),
    Movement("Bubble"     , 40,100,30,11,1,0,Bubble),
    Movement("Bubble Beam", 65,100,20,11,1,0,BubbleBeam),

    Movement("Clamp"      , 35, 85,15,11,0,0,Clamp),

    Movement("Scratch"   , 20,100,30,10,0,0,Scratch),
};

////// movesets area
levelUpMoves moveset1[5]={
    levelUpMoves(1,Scratch),
    levelUpMoves(2,Absorb),
};
levelUpMoves moveset2[5]={
    levelUpMoves(6,Scratch),
    levelUpMoves(12,Absorb),
};


levelUpMoves * MASTERSET[151]={
    (moveset1),
    (moveset2),
};

levelUpMoves * getMoveset(int pos){
    switch (pos)
    {
    case 1:return MASTERSET[1];break;
    case 2: return MASTERSET[2];break;
    case 4:case 5:case 6:
        return moveset2;
    default:
        perror("Error in getMoveset, POS not found\n");
        break;
    }
    return MASTERSET[0];
};
void LevelUpNewMoveCheck(pokemon *poke,int level){
    switch (level)
    {
    case 6:
        //offer new move
        moveset1[1];
        break;
    case 12:
    //offer new move
    break;
    default:
    //do nothing
        break;
    }
}

levelUpMoves::levelUpMoves(){level=0;NewMovement=NULL;}
levelUpMoves::levelUpMoves(int levelat,void(*Movement)(pokemon*dealer,pokemon*receiver)){
    level=levelat;this->NewMovement=Movement;
};
Movement::Movement(){};
Movement::Movement(char* name,int power,int pres,int pp,int tpe,int cat,int prio,void(*Ptr)(pokemon*,pokemon*)){
    namecpy(this->name,name);
    pwr=power;
    precision=pres;
    PPog=pp;
    PP=pp;
    type=tpe;
    category=cat;
    priority=prio;
    use=Ptr;
};
Dexes::Dexes():hp(0),atk(0),def(0),spatk(0),spdef(0),spd(0),crit(0),tpe(0),tpe2(0),pos(0){char nam[8]="missing";namecpy(name,nam);};
Dexes::Dexes(char* name,int lvl,int hp,int atk,int def,int spatk,int spdef,int spd,int crit,int tpe,int tpe2,int pos){
    namecpy(this->name,name);this->lvl=lvl;this->hp=hp;this->atk=atk;this->def=def;this->spatk=spatk,this->spdef=spdef,
    this->spd=spd;this->crit=crit;this->tpe=tpe;this->tpe2=tpe2,this->pos=pos;
}
basePoke::basePoke():pos(0),lvl(0),hp(0),atk(0),def(0),spatk(0),spdef(0),spd(0),crit(0),tpe(0),ohp(hp),oatk(atk),odef(def),ospatk(spatk),ospdef(spdef),ospd(spd){
    char nam[8]="missing";namecpy(name,nam);
    turnsAsleep   = 0;
    turnsConfused = 0;
}
pokemon::pokemon(){
    setHP(0);
    setATK(0);
    setDEF(0);
    setSPATK(0);
    setSPDEF(0);
    setSPD(0);
    setCRIT(0);
    setTYPE(0);
    setTYPE2(0);
    setohp(getHP());
    setoatk(getATK());
    setodef(getDEF());
    setospatk(getSPATK());
    setospdef(getSPDEF());
    setospd(getSPD());
    setNAME("missing");
    setLVL(1);
    turnsAsleep   = 0;
    turnsConfused = 0;
    moves[0] = move_list[0];
    moves[1] = move_list[0];
    moves[2] = move_list[0];
    moves[3] = move_list[0];
}
pokemon::pokemon(Dexes pdx){
    setNAME(pdx.name);
    setTYPE(pdx.tpe);
    setTYPE2(pdx.tpe2);
    setPOS(pdx.pos);
    setCRIT(pdx.crit);
    setohp(calcHP(pdx.hp,getHpIV(),pdx.lvl,1));
    setHP(getohp());//when we add natures, swap that 1;
    setoatk(calcStat(pdx.atk,getAtkIV(),pdx.lvl,1));
    setATK(getoatk());
    setodef(calcStat(pdx.def,getDefIV(),pdx.lvl,1));
    setDEF(getodef());
    setospatk(calcStat(pdx.spatk,getSpAtkIV(),pdx.lvl,1));
    setSPATK(getospatk());
    setospdef(calcStat(pdx.spdef,getSpDefIV(),pdx.lvl,1));
    setSPDEF(getospdef());
    setospd(calcStat(pdx.spd,getSpdIV(),pdx.lvl,1));
    setSPD(getospd());
    turnsAsleep   = 0;
    turnsConfused = 0;
    moves[0] = move_list[0];
    moves[1] = move_list[0];
    moves[2] = move_list[0];
    moves[3] = move_list[0];
}
pokemon::pokemon(Dexes pdx,int lvl){
    setNAME(pdx.name);
    setTYPE(pdx.tpe);
    setTYPE2(pdx.tpe2);
    setPOS(pdx.pos);
    setCRIT(pdx.crit);
    setohp(calcHP(pdx.hp,getHpIV(),lvl,1));
    setHP(getohp());//when we add natures, swap that 1;
    setoatk(calcStat(pdx.atk,getAtkIV(),lvl,1));
    setATK(getoatk());
    setodef(calcStat(pdx.def,getDefIV(),lvl,1));
    setDEF(getodef());
    setospatk(calcStat(pdx.spatk,getSpAtkIV(),lvl,1));
    setSPATK(getospatk());
    setospdef(calcStat(pdx.spdef,getSpDefIV(),lvl,1));
    setSPDEF(getospdef());
    setospd(calcStat(pdx.spd,getSpdIV(),lvl,1));
    setSPD(getospd());
    setLVL(lvl);
    turnsAsleep   = 0;
    turnsConfused = 0;
    moves[0] = move_list[0];
    moves[1] = move_list[0];
    moves[2] = move_list[0];
    moves[3] = move_list[0];
}
pokemon::pokemon(char* name,int hp,int atk,int def,int spatk,int spdef,int spd,int crit,int tpe,int tpe2,int pos){
    setNAME(name);
    setLVL(1);
    setHP(hp);
    setATK(atk);
    setDEF(def);
    setSPD(spd);
    setCRIT(crit);
    setTYPE(tpe);
    setTYPE2(tpe2);
    setPOS(pos);
    setohp(getHP());
    setoatk(getATK());
    setodef(getDEF());
    setospatk(getSPATK());
    setospdef(getSPDEF());
    setospd(getSPD());
    turnsAsleep   = 0;
    turnsConfused = 0;
    moves[0] = move_list[0];
    moves[1] = move_list[0];
    moves[2] = move_list[0];
    moves[3] = move_list[0];
}
pokemon::pokemon(char* name,int lvl,int hp,int atk,int def,int spatk,int spdef,int spd,int crit,int tpe,int tpe2,int pos){
    setNAME(name);
    setLVL(lvl);
    setohp(hp);
    setoatk(atk);
    setodef(def);
    setospatk(spatk);
    setospdef(spdef);
    setospd(spd);
    setHP(hp);
    setATK(atk);
    setDEF(def);
    setSPD(spd);
    setCRIT(crit);
    setTYPE(tpe);
    setTYPE2(tpe2);
    setPOS(pos);
    turnsAsleep   = 0;
    turnsConfused = 0;
    moves[0] = move_list[0];
    moves[1] = move_list[0];
    moves[2] = move_list[0];
    moves[3] = move_list[0];
}

Person::Person(){money=0;
    namecpy(name,"npc");
    int i = 0;
    for(i;i<6;i++){
        team[i]=NULL;
    }
};
Person::Person(int money){this->money=money;
    namecpy(name,"npc");
    int i = 0;
    for(i;i<6;i++){
        team[i]=NULL;
    }
};
Person::Person(int money,pokemon *poke0){
    namecpy(name,"npc");
    this->money=money;
    team[0]=poke0;
    int i = 1;
    for(i;i<6;i++){
        team[i]=NULL;
    }
};
Person::Person(int money,pokemon *poke0,pokemon *poke1){
    namecpy(name,"npc");
    this->money=money;
    team[0]=poke0;
    team[1]=poke1;
    int i = 2;
    for(i;i<6;i++){
        team[i]=NULL;
    }
};
Person::Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2){
    namecpy(name,"npc");
    this->money=money;
    team[0]=poke0;
    team[1]=poke1;
    team[2]=poke2;
    int i = 3;
    for(i;i<6;i++){
        team[i]=NULL;
    }
};
Person::Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3){
    namecpy(name,"npc");
    this->money=money;
    team[0]=poke0;
    team[1]=poke1;
    team[2]=poke2;
    team[3]=poke3;
    int i = 4;
    for(i;i<6;i++){
        team[i]=NULL;
    }
};
Person::Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3,pokemon *poke4){
    namecpy(name,"npc");
    this->money=money;
    team[0]=poke0;
    team[1]=poke1;
    team[2]=poke2;
    team[3]=poke3;
    team[4]=poke4;
    team[5]=NULL;
};
Person::Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3,pokemon *poke4,pokemon *poke5){
    namecpy(name,"npc");
    this->money=money;
    team[0]=poke0;
    team[1]=poke1;
    team[2]=poke2;
    team[3]=poke3;
    team[4]=poke4;
    team[5]=poke5;
};
Player::Player(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3,pokemon *poke4,pokemon *poke5){
    setName("player");
    this->money=money;
    team[0]=poke0;
    team[1]=poke1;
    team[2]=poke2;
    team[3]=poke3;
    team[4]=poke4;
    team[5]=poke5;
};
Player::Player(Person npc){
    setName("Player");
    this->money=money;
    team[0]=npc.team[0];
    team[1]=npc.team[1];
    team[2]=npc.team[2];
    team[3]=npc.team[3];
    team[4]=npc.team[4];
    team[5]=npc.team[5];
};
Player::Player(){
    setName("You");
    money=0;
    int i;
    for(i=0;i<6;i++){
        team[i]=NULL;
    }
};