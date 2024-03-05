#ifndef __IMAGE__H
#define __IMAGE__H

using namespace std;

class Personnage {
	private:
		int vie;
		int vieMax;
		int atkBase;
		int energy;
	public:
		int getVie();

		void setVie(const int& nvVie);

		int getAtk();

		void setAtk(const int& nvAtk);

		int getNrj();
};

#endif
