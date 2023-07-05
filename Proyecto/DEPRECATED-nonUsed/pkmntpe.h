//normal1 fighting2 flying3 poison4 ground5 rock6 bug7 ghost8 steel9 fire10
//water11 grass12 electric13 psychich14 ice15 dragon16 dark17 rairy18
class Normal: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=1;};
class Fighting: public pokemon{
    public:
    void setTYPE(int type){this->tpe=type;};
    int getTYPE(){int t;t=this->tpe;return t;};
    private:
    int tpe=2;};
class Flying: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=3;};
class Poison: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=4;};
class Ground: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=5;};

class Rock: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=6;};
class Bug: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=7;};
class Ghost: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=8;};
class Steel: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=9;};
class Fire: public pokemon{
    public:
    Fire();
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=10;};
class Water: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=11;};
class Grass: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=12;};
class Electric: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=13;};
class Psychic: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=14;};
class Ice: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=15;};
class Dragon: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=16;};
class Dark: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=17;};
class Fairy: public pokemon{
    public:
    void setTYPE(int type);
    int getTYPE();
    private:
    int tpe=18;};
Fire::Fire(){this->tpe=10;};

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
