#include <iostream>
#include "Monde.h"
#include "Deplacement.h"
using namespace std;

int main(){
    Monde monde;
    char action;
    bool fin=false;
    while(!fin){
        cin<<action;
        deplacement(action,monde);
    }
}