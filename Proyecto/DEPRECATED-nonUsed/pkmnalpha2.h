#include<iostream>
using namespace std;

class pokemon{
    public:
    pokemon();pokemon(string name);pokemon(string name,int hp);pokemon(string name,int hp,int atk);pokemon(string name,int hp,int atk,int def);
    pokemon(string name,int hp, int atk, int def,int spd);pokemon(string name,int hp, int atk, int def, int spd, int crit);
    pokemon(string name,int hp,int atk,int def,int spd,int crit,int tpe);
    void setHP(int hp);
    void setATK(int atk);
    void setDEF(int def);
    void setSPD(int spd);
    void setCRIT(int crit);
    void setohp(int ohp);
    void setodf(int odf);
    void setoatk(int oatk);
    void setTYPE(int type);
    void hurt(float dmg);
    int getHP();
    int getATK();
    int getDEF();
    int getSPD();
    int getCRIT();
    int getohp();
    int getodf();
    int getoatk();
    int getTYPE();
    void heal(float dmg);
    void heal2(float dmg);
    float atk1(),atk2(),atk3(),atk4();
    float deal;

    void setNAME(char name);
    string getNAME();

    private:
    int hp,atk,def,spd,crit,tpe,ohp,odf,oatk,pos,globalpos=0;
    char[10] name;};

void pokemon::setNAME(char *name){getline(this->name,name);};
string pokemon::getNAME(){string nm=this->name;return nm;};

pokemon::pokemon():name("missing"),hp(0),atk(0),def(0),spd(0),crit(0),tpe(0),ohp(hp),odf(def),oatk(atk){this->globalpos++;}
pokemon::pokemon(string name):hp(0),atk(0),def(0),spd(0),crit(0),tpe(0),ohp(hp),odf(def),oatk(atk){}
pokemon::pokemon(string name,int hp):atk(0),def(0),spd(0),crit(0),tpe(0),ohp(hp),odf(def),oatk(atk){this->hp=hp;this->globalpos++;}
pokemon::pokemon(string name,int hp,int atk):def(0),spd(0),crit(0),tpe(0),ohp(hp),odf(def),oatk(atk)
{this->hp=hp;this->atk=atk;this->globalpos++;}
pokemon::pokemon(string name,int hp,int atk,int def):spd(0),crit(0),tpe(0),ohp(hp),odf(def),oatk(atk)
{this->hp=hp;this->atk=atk;this->def=def;this->globalpos++;}
pokemon::pokemon(string name,int hp,int atk,int def,int spd):crit(0),tpe(0),ohp(hp),odf(def),oatk(atk)
{this->hp=hp;this->atk=atk;this->def=def;this->spd=spd;this->globalpos++;}
pokemon::pokemon(string name,int hp,int atk,int def,int spd,int crit):tpe(0),ohp(hp),odf(def),oatk(atk)
{this->hp=hp;this->atk=atk;this->def=def;this->spd=spd;this->crit=crit;this->globalpos++;}
pokemon::pokemon(string name,int hp,int atk,int def,int spd,int crit,int tpe):ohp(hp),odf(def),oatk(atk)
{this->hp=hp;this->atk=atk;this->def=def;this->spd=spd;this->crit=crit;this->tpe=tpe;this->globalpos++;}

void pokemon::setHP(int hp){this->hp=hp;};
void pokemon::setATK(int atk){this->atk=atk;};
void pokemon::setDEF(int def){this->def=def;};
void pokemon::setSPD(int spd){this->spd=spd;};
void pokemon::setCRIT(int crit){this->crit=crit;};
void pokemon::setohp(int oghp){this->ohp=oghp;};
void pokemon::setodf(int odf){this->odf=odf;};
void pokemon::setoatk(int oatk){this->oatk=oatk;};
void pokemon::setTYPE(int type){this->tpe=type;};

int pokemon::getHP(){int hp=this->hp;return hp;};
int pokemon::getATK(){int atk=this->atk;return atk;};
int pokemon::getDEF(){int def=this->def;return def;};
int pokemon::getSPD(){int spd=this->spd;return spd;};
int pokemon::getCRIT(){int crit=this->crit;return crit;};
int pokemon::getohp(){int ohp=this->ohp;return ohp;};
int pokemon::getodf(){int odf=this->odf;return odf;};
int pokemon::getoatk(){int oatk=this->oatk;return oatk;};
int pokemon::getTYPE(){int type=this->tpe;return type;};

void pokemon::heal(float dmg){hp+=(dmg);};
//void pokemon::heal2(float dmg){setHP(this->hp+=dmg);};

void pokemon::hurt(float dmg){hp-=(dmg)*(float(10-def)/10);};

float pokemon::atk1(){return atk*1.2;}
float pokemon::atk2(){return atk;}
float pokemon::atk3(){return 0;}
float pokemon::atk4(){return 0;}

void iscrit(pokemon *pk,int crit){if(crit<pk->getCRIT()){pk->setATK(pk->getATK()*3/2);}}
void wascrit(pokemon *pk,int crit){if(crit<pk->getCRIT()){pk->setATK(pk->getoatk());}}
int showHP(pokemon *pk){int health=pk->getHP();return health;};

float multiplier(int receiver,int dealer){float factor;
    if(receiver==1){(dealer==2)?factor=2:(dealer==8)?factor=0:factor=1;}
    if(receiver==2){(dealer==3||dealer==14||dealer==18)?factor=2:
        (dealer==6||dealer==7||dealer==17)?factor=0.5:factor=1;}
    if(receiver==3){(dealer==6||dealer==13||dealer==15)?factor=2:
        (dealer==2||dealer==7||dealer==12)?factor=0.5:(dealer==5)?factor=0:factor=1;}
    if(receiver==4){(dealer==5||dealer==14)?factor=2:
        (dealer==2||dealer==4||dealer==7||dealer==12||dealer==18)?factor=0.5:factor=1;}
    if(receiver==5){(dealer==11||dealer==12||dealer==15)?factor=2:
        (dealer==4||dealer==6)?factor=0.5:(dealer==13)?factor=0:factor=1;}
    if(receiver==6){(dealer==2||dealer==5||dealer==9||dealer==11||dealer==12)?factor=2:
        (dealer==1||dealer==3||dealer==4||dealer==10)?factor=0.5:factor=1;}
    if(receiver==7){(dealer==3||dealer==6||dealer==10)?factor=2:
        (dealer==2||dealer==5||dealer==12)?factor=0.5:factor=1;}
    if(receiver==8){(dealer==8||dealer==17)?factor=2:
        (dealer==4||dealer==7)?factor=0.5:(dealer==1||dealer==2)?factor=0:factor=1;}
    if(receiver==9){(dealer==2||dealer==5||dealer==10)?factor=2:
        (dealer==1||dealer==3||dealer==6||dealer==7||dealer==9||dealer==12||dealer==14||dealer==15||dealer==16||dealer==18)?factor=0.5:factor=1;}
    if(receiver==10){(dealer==5||dealer==6||dealer==11)?factor=2:
        (dealer==7||dealer==9||dealer==10||dealer==12||dealer==15||dealer==18)?factor=0.5:factor=1;}
    if(receiver==11){(dealer==12||dealer==13)?factor=2:
        (dealer==9||dealer==10||dealer==11||dealer==15)?factor=0.5:factor=1;}
    if(receiver==12){(dealer==3||dealer==4||dealer==7||dealer==10||dealer==15)?factor=2:
        (dealer==11||dealer==12||dealer==13)?factor=0.5:factor=1;}
    if(receiver==13){(dealer==5)?factor=2:
        (dealer==3||dealer==9||dealer==13)?factor=0.5:factor=1;}
    if(receiver==14){(dealer==7||dealer==8||dealer==17)?factor=2:
        (dealer==2||dealer==14)?factor=0.5:factor=1;}
    if(receiver==15){(dealer==2||dealer==6||dealer==9||dealer==10)?factor=2:
        (dealer==15)?factor=0.5:factor=1;}
    if(receiver==16){(dealer==15||dealer==16||dealer==18)?factor=2:
        (dealer==10||dealer==11||dealer==12||dealer==13)?factor=0.5:factor=1;}
    if(receiver==17){(dealer==2||dealer==18)?factor=2:
        (dealer==7||dealer==8||dealer==17)?factor=0.5:(dealer==14)?factor=0:factor=1;}
    if(receiver==18){(dealer==4||dealer==9)?factor=2:
        (dealer==2||dealer==17)?factor=0.5:(dealer==16)?factor==0:factor=1;}
    return factor;}