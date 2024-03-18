#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "Deplacement.h"
#include "JeuTxt.h"

void txtAff(WinTXT & win, const Deplacement & depla) {
	int x,y;
	win.clear();
	for (x=0;x<7;x++) {
        for (y=0;y<12;y++) {
            if ((x==depla.getMonde().getX()) && (y==depla.getMonde().getY())) 
                win.print(x,y,'!');
            else if (depla.getMonde().tabCarte[depla.getMonde().getCarte()].tabCase[x][y].libre) 
                win.print(x,y,'*');
            else
                win.print(x,y,'-');
        }
	}

	win.draw();
}

void txtBoucle(Deplacement & depla) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (depla.getMonde().getX(),depla.getMonde().getY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,depla);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		c = win.getCh();
		switch (c) {
			case 'z':
				depla.deplace('h');
				break;
			case 'q':
				depla.deplace('g');
				break;
			case 's':
				depla.deplace('b');
				break;
			case 'd':
				depla.deplace('d');
				break;
			case 'p':
				ok = false;
				break;
		}

	} while (ok);

}