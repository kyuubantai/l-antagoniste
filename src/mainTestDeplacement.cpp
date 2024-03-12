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
        depla.interaction(action,monde);
        int mX=monde.getX();
        int mY=monde.getY();
        int carteX=monde.getCarte();
        for (int i=0;i<7;i++) {
            for (int j=0;j<12;j++) {
                if ((i==mX) && (j==mY)) 
                    cout<<"!";
                else if (monde.tabCarte[carteX].tabCase[i][j].libre) 
                    cout<<"*";
                else
                    cout<<"-";
            }
            cout<<endl;
        }
    }
}
