#include<iostream>
#include<time.h>
//#include<cstring>

void namecpy(char* destination,char* source);
int calcHP(int BASE,int IV, int LVL,int Nature);
int calcStat(int BASE,int IV, int LVL,int Nature);

class basePoke;
class pokemon;
class item;
class Person;
class Player;

struct Dexes{
    Dexes();
    //name,hp,atk,def,spd,crit,tpe
    Dexes(char* name,int lvl,int hp,int atk,int def,int spatk,int spdef,int spd,int crit,int tpe,int tpe2,int pos);
    char* getNAME();
    int hp,lvl,atk,def,spatk,spdef,spd,crit,tpe,tpe2,pos;
    char name[11];
};
struct Movement{
    Movement();
    Movement(char* name,int pwr,int precision,int PP,int tpe,int cat,int prio);
    Movement(char* name,int pwr,int precision,int PP,int tpe,int cat,int prio,void(*Ptr)(pokemon*,pokemon*));
    void (*use)(pokemon *dealer,pokemon *receiver);
    int getPP(),getPPog(),getPwr(),getPres(),getTargets(),getType(),getCategory(),getPrio();
    char *getName();
    void setPP(int newValue);
    private:
    int PPog,PP,pwr,precision,targets,type,category,priority;
    char name[11];
};
class basePoke{
    public:
    basePoke();

    void setPOS(int pos);
    void setLVL(int lvl);
    void setHP(int hp);
    void setATK(int atk);
    void setDEF(int def);
    void setSPATK(int spatk);
    void setSPDEF(int spdef);
    void setSPD(int spd);
    void setCRIT(int crit);
    void setohp(int ohp);
    void setoatk(int oatk);
    void setodef(int odef);
    void setospatk(int spatk);
    void setospdef(int spdef);
    void setospd(int ospd);
    void setTYPE(int type);
    void setTYPE2(int type2);
    int getPOS();
    int getLVL();
    int getHP();
    int getATK();
    int getDEF();
    int getSPATK();
    int getSPDEF();
    int getSPD();
    int getCRIT();
    int getohp();
    int getoatk();
    int getodef();
    int getospatk();
    int getospdef();
    int getospd();
    int getTYPE();
    int getTYPE2();
    int getHpIV();
    int getAtkIV();
    int getDefIV();
    int getSpAtkIV();
    int getSpDefIV();
    int getSpdIV();

    void setNAME(char* nm);
    char* getNAME();

    Movement moves[4];
    void (*movgroup[4])(pokemon *dealer,pokemon *receiver);
/*  void (*movPtr1)(pokemon *dealer,pokemon *receiver);
    void (*movPtr2)(pokemon *dealer,pokemon *receiver);
    void (*movPtr3)(pokemon *dealer,pokemon *receiver);
    void (*movPtr4)(pokemon *dealer,pokemon *receiver);*/

    //STATUSES
    bool is_paralyzed = false;
    bool is_burned    = false;
    bool is_confused  = false;
    bool is_asleep    = false;
    bool is_frozen    = false;
    bool is_poisoned  = false;
    bool is_badlyPoisoned = false;
    int turnsAsleep   =0;
    int turnsConfused =0;

    int precision=100,evasion=100;//battle stats, should alwats be 100 after a fight
    private: //stats
    int hp, atk, def, spatk, spdef, spd;            //stats
    int ohp, oatk, odef, ospatk, ospdef, ospd;      //og stats
    int lvl, tpe, tpe2, pos, crit;                  //identifiers
    char name[11];
    //random ivs
    int hpiv=rand()%32;
    int atkiv=rand()%32;
    int defiv=rand()%32;
    int spatkiv=rand()%32;
    int spdefiv=rand()%32;
    int spdiv=rand()%32;
};
class pokemon:public basePoke{
    public:
    pokemon();
    pokemon(char* name,int hp,int atk,int def,int spatk,int spdef,int spd,int crit,int tpe,int tpe2,int pos);
    pokemon(char* name,int lvl,int hp,int atk,int def,int spatk,int spdef,int spd,int crit,int tpe,int tpe2,int pos);
    pokemon(Dexes pdx);
    pokemon(Dexes pdx,int lvl);
};
struct levelUpMoves{
    int level;
    void (*NewMovement)(pokemon *dealer,pokemon *receiver);
    levelUpMoves();
    levelUpMoves(int level,void(*NewMovement)(pokemon*dealer,pokemon*receiver));
};
class item{
    char name[10];
    int amount;
//pointer to function or something
};
struct Bag{
    item pokeballs[1];
};
class Person{
    public:
    Person();
    Person(int money);
    Person(int money,pokemon *poke0);
    Person(int money,pokemon *poke0,pokemon *poke1);
    Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2);
    Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3);
    Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3,pokemon *poke4);
    Person(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3,pokemon *poke4,pokemon *poke5);

    char * getName();
    void setName(char * newName);

    int money;
    pokemon * team[6];
    private:
    char name[11];
};
class Player:public Person{
    public:
    Player();
    Player(Person);
    Bag myBag;
    Player(int money,pokemon *poke0,pokemon *poke1,pokemon *poke2,pokemon *poke3,pokemon *poke4,pokemon *poke5);
};

void basePoke::setPOS(int pos){this->pos=pos;}
void basePoke::setLVL(int lvl){this->lvl=lvl;}
void basePoke::setHP(int hp){this->hp=hp;}
void basePoke::setATK(int atk){this->atk=atk;}
void basePoke::setDEF(int def){this->def=def;}
void basePoke::setSPATK(int spatk){this->spatk=spatk;}
void basePoke::setSPDEF(int spdef){this->spdef=spdef;}
void basePoke::setSPD(int spd){this->spd=spd;}
void basePoke::setCRIT(int crit){this->crit=crit;}
void basePoke::setohp(int oghp){this->ohp=oghp;}
void basePoke::setoatk(int oatk){this->oatk=oatk;}
void basePoke::setodef(int odef){this->odef=odef;}
void basePoke::setospatk(int spatk){this->ospatk=spatk;}
void basePoke::setospdef(int spdef){this->ospdef=spdef;}
void basePoke::setospd(int ospd){this->ospd=ospd;}
void basePoke::setTYPE(int type){this->tpe=type;}
void basePoke::setTYPE2(int type2){this->tpe2=type2;}
void basePoke::setNAME(char* nm){namecpy(name,nm);namecpy(name,nm);}
char* basePoke::getNAME(){return this->name;}
int basePoke::getPOS(){return pos;}
int basePoke::getLVL(){return lvl;}
int basePoke::getHP(){return hp;}
int basePoke::getATK(){return atk;}
int basePoke::getDEF(){return def;}
int basePoke::getSPATK(){return spatk;}
int basePoke::getSPDEF(){return spdef;}
int basePoke::getSPD(){return spd;}
int basePoke::getCRIT(){return crit;}
int basePoke::getohp(){return ohp;}
int basePoke::getoatk(){return oatk;}
int basePoke::getodef(){return odef;}
int basePoke::getospatk(){return ospatk;}
int basePoke::getospdef(){return ospdef;}
int basePoke::getospd(){return ospd;}
int basePoke::getTYPE(){return tpe;}
int basePoke::getTYPE2(){return tpe2;}
int basePoke::getHpIV(){return hpiv;};
int basePoke::getAtkIV(){return atkiv;};
int basePoke::getDefIV(){return defiv;};
int basePoke::getSpAtkIV(){return spatkiv;};
int basePoke::getSpDefIV(){return spdefiv;};
int basePoke::getSpdIV(){return spdiv;};

int Movement::getType(){return type;}
int Movement::getTargets(){return targets;}
int Movement::getPwr(){return pwr;}
int Movement::getPrio(){return priority;}
int Movement::getPres(){return precision;}
int Movement::getPPog(){return PPog;}
int Movement::getPP(){return PP;}
char *Movement::getName(){return name;}
void Movement::setPP(int newValue){PP=newValue;}

char * Person::getName(){return name;};
void Person::setName(char * newName){namecpy(name,newName);}

//functions
int showHP(pokemon *pk);
float typeModifier(int dealer,int receiver);
float AtkTpeBonus(pokemon pk,int tpeAtk);
void usemovement(pokemon *attacker,pokemon *defender,int selectedMove);
float calc_Max_damage();
float calc_Min_damage();
float calc_damage(pokemon attacker,pokemon defender,int Power,int Targets,int tpeAtk,int category);
bool statusCheck(pokemon *pkm);
int accuracyCheck(int precision,int accuracy,int evasion,int modifier);
void swapPokePlaces(pokemon *poke1,pokemon *poke2);
void showAvailableMoves(Player *player);
bool hasPP(Player *player);
bool npcPokeFainted(Person *npc,Player *player);
int chooseMove(Player *player,Person *npc);
void battle(Player *player,Person *npc);
void wildBattle(Player *player);
void getToLVL(pokemon *pkm,int lvl);
void healTeamFully(Player *player);
void modifyAtkStage(pokemon *pkm,int incrementBy,int decrementBy);
void modifyDefStage(pokemon *pkm,int incrementBy,int decrementBy);
void modifySpAtkStage(pokemon *pkm,int incrementBy,int decrementBy);
void modifySpDefStage(pokemon *pkm,int incrementBy,int decrementBy);
void modifySpdStage(pokemon *pkm,int incrementBy,int decrementBy);
void modifyAccuracy(pokemon *pkm,int incrementBy,int decrementBy);
void modifyEvasion(pokemon *pkm,int incrementBy,int decrementBy);
