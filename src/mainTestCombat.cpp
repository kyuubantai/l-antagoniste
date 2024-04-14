#include "Combat.h"
#include "Heros.h"
#include <iostream>

using namespace std;

/*enum Etat{MENUBASE,SELECT,COMP,OBJ};
enum EtatComp{MENUCOMP,MONO,MULTI,HEAL};*/

int main(){
    Combat c;
    Heros h;
    h.stats.atkBase = 20;
    h.stats.def = 100;
    h.stats.energie = 999;
    h.stats.vieMax=999;
    h.stats.vie = 999;
    int action;
    do{
        c.combat(h,action);
        cout<<"Choississez votre action : "<<endl;
        cin>>action;
    }while(h.stats.vie>0);
    //if(h.stats.vie<=0) cout<<"défaite";
    return 0;
}
