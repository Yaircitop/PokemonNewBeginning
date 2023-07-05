/*struct Movement
{
    Movement();
    Movement(char* name,int type,int power,int precision,int PP,int category,int priority);
    int type,power,precision,PP,category;
    int priority;
    char name[15];
};*/
Movement::Movement():type(0),power(0),precision(0),category(2),priority(0){char nam[8]="missing";namecpy(name,nam);};
Movement::Movement(char* nam,int tipe,int pow,int prec,int pp,int ctgry,int prio){
    namecpy(name,nam);type=tipe;power=pow;precision=prec;PP=pp;category=ctgry;priority=prio;
};
Movement::Movement(char* nam,int tipe,int pow,int prec,int pp,int ctgry,int prio,int flag){
    namecpy(name,nam);type=tipe;power=pow;precision=prec;PP=pp;category=ctgry;priority=prio;FLAG=flag;
};
///DEPRECATED
//FLAG : 0-SELF-STATUS 1-SELF-HELATH 2-ENEMY-STATUS 3-ENEMY-HEALTH 5-PARTY-POSITIONS
Movement Movement_List[5]={
    Movement(((char*)"Bubble"),11,20 ,100,30,1,0,0),
    Movement(((char*)"Bubble"),11,300,100,30,1,0,1),
    Movement(((char*)"Bubble"),11,20 ,100,30,1,0,2),
    Movement(((char*)"Bubble"),11,20 ,100,30,1,0,3),
    Movement(((char*)"Bubble"),11,20 ,100,30,1,0,4),
};
 
