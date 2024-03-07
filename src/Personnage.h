#ifndef __PERSONNAGE__H
#define __PERSONNAGE__H

using namespace std;

class Personnage {
	private:
		int vie;
		int vieMax;
		int atkBase;
		int energie;
	public:
		int getVie();

		void setVie(const int& nvVie);

		int getAtk();

		void setAtk(const int& nvAtk);

		int getNrj();
};

#endif
