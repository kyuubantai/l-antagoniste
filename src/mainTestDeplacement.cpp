#include <iostream>
#include "Monde.h"
#include "Deplacement.h"
using namespace std;

int main(){
    Monde monde;
    Deplacement depla;
    char action;
    bool fin=false;
    while(!fin){
        cin>>action;
        depla.deplacement(action,monde);
    }
}
