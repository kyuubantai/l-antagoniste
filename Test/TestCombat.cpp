#include <iostream>

using namespace std;

enum Tour {MOI,ENNEMI};

class Personnage {
	private:
		int vie;
		int vieMax;
		int atkBase;
		int energie;
		//Competence comp[3];
	public:
		int getVie() const;

		void setVie(int nvVie);

		int getAtk() const;

		void setAtk(int nvAtk);

		int getNrj() const;
};

int Personnage::getVie() const{
    return vie;
}

void Personnage::setVie(int nvVie){
    vie=nvVie;
}

int Personnage::getAtk() const{
    return atkBase;
}

void Personnage::setAtk(int nvAtk){
    atkBase=nvAtk;
}

int Personnage::getNrj() const{
    return energie;
}

class Heros {
    public:
	    Personnage stats;
        //Objet invetaire[10];
        Heros();
};

Heros::Heros(){
    stats.setVie(100);
    stats.setAtk(10);
}

class Ennemi {
	public:
		Personnage stats;	
		Ennemi();
};

Ennemi::Ennemi(){
    stats.setVie(100);
    stats.setAtk(30);
}

class Combat {
    public:
        Tour tour;
        void combat(Heros& heros);

};

void Combat::combat(Heros& heros){
    bool fin=false;
    Ennemi ennemi;
    int n;
    while(!fin){
        if(tour == MOI){
            cout <<"Ton tour"<<endl;
            cin >> n;
            ennemi.stats.setVie(ennemi.stats.getVie()-5);
        }
        else{
            cout <<"Ennemi"<<endl;
            heros.stats.setVie(heros.stats.getVie()-10);
        }

        if(heros.stats.getVie()==0 || ennemi.stats.getVie()==0){
            fin=true;
        }

        if (tour == MOI)
		    tour = ENNEMI;
	    else
		    tour = MOI;
    }
    if(heros.stats.getVie()<=0){cout<<"défaite"<<endl;}
    if(ennemi.stats.getVie()<=0){cout<<"victoire"<<endl;}
}

int main(){
    Heros heros;
    Combat comb;
    comb.combat(heros);
    return 0;
}