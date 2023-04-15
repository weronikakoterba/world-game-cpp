#include "Antylopa.h"
#include "Swiat.h"
Antylopa::Antylopa(int n_x, int n_y, Swiat* n_swiat) : Zwierze(4, 4, n_x, n_y, Gatunek::antylopa, n_swiat) {
}

Antylopa::~Antylopa()
{
	cout << "Wilk umiera\n";
}
void Antylopa::akcja(){
	temp_x = x;
	temp_y = y;

	do {
		short kierunek = rand() % 4;		// losujê liczbê z przedzia³u <0, 7>
		cout << kierunek << endl;
		switch (kierunek) {
		case 0:		// pójœcie w górê
			if (y == 0 || y==1)
				break;
			y=y-2;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		case 1: // pojsce w dol
			if (y == wysokosc - 1 || y==wysokosc-2)
				break;
			y=y+2;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		case 2:// pojscie w prawo
			if (x == szerokosc - 1 || x==szerokosc-2)
				break;
			x=x+2;
			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		case 3:// pojscie w lewo
			if (x == 0 || x==1)
				break;
			x=x-2;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		//case 4: // gorny lewy rog
		//	if (x == 0 || x==1 || y == 0 || y==1)
		//		break;
		//	x=x-2;
		//	y=y-2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 5: // gorny prawy rog
		//	if (x == szerokosc - 1 || x==szerokosc-2 || y == 0 || y==1)
		//		break;
		//	x=x+2;
		//	y=y-2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 6: // dolny prawy rog
		//	if (x == szerokosc - 1 || x==szerokosc-2 || y == wysokosc - 1 || y==wysokosc-2)
		//		break;
		//	x=x+2;
		//	y=y+2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 7: // dolny lewy rog
		//	if (x == 0 || x==1 || y == wysokosc - 1 || y==wysokosc-2)
		//		break;
		//	x=x-2;
		//	y=y+2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;

		}

	} while (true);
}
void Antylopa::rysowanie() {
	cout << 'A';
}
