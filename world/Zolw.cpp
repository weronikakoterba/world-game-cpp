#include "Zolw.h"
#include "Swiat.h"
Zolw::Zolw(int n_x, int n_y, Swiat* n_swiat) : Zwierze(2, 1, n_x, n_y, Gatunek::zolw, n_swiat) {
}

Zolw::~Zolw()
{
	cout << "Zolw umiera\n";
}
void Zolw::akcja() {//todo funckja dla zolwia
	temp_x = x;
	temp_y = y;

	short szansa = rand() % 4; // 25% szansy na ruch
	cout << "szansa" << szansa<<endl;

	if (szansa == 0) {
		do {
			short kierunek = rand() % 4;		// losujê liczbê z przedzia³u <0, 7>
			cout << kierunek << endl;
			switch (kierunek) {
			case 0:		// pójœcie w górê
				if (y == 0)
					break;
				y--;

				swiat->przesun_organizm(temp_x, temp_y, x, y);
				return;
			case 1: // pojsce w dol
				if (y == wysokosc - 1)
					break;
				y++;

				swiat->przesun_organizm(temp_x, temp_y, x, y);
				return;
			case 2:// pojscie w prawo
				if (x == szerokosc - 1)
					break;
				x++;

				swiat->przesun_organizm(temp_x, temp_y, x, y);
				return;
			case 3:// pojscie w lewo
				if (x == 0)
					break;
				x--;

				swiat->przesun_organizm(temp_x, temp_y, x, y);
				return;
			//case 4: // gorny lewy rog
			//	if (x == 0 || y == 0)
			//		break;
			//	x--;
			//	y--;

			//	swiat->przesun_organizm(temp_x, temp_y, x, y);
			//	return;
			//case 5: // gorny prawy rog
			//	if (x == szerokosc - 1 || y == 0)
			//		break;
			//	x++;
			//	y--;

			//	swiat->przesun_organizm(temp_x, temp_y, x, y);
			//	return;
			//case 6: // dolny prawy rog
			//	if (x == szerokosc - 1 || y == wysokosc - 1)
			//		break;
			//	x++;
			//	y++;

			//	swiat->przesun_organizm(temp_x, temp_y, x, y);
			//	return;
			//case 7: // dolny lewy rog
			//	if (x == 0 || y == wysokosc - 1)
			//		break;
			//	x--;
			//	y++;

			//	swiat->przesun_organizm(temp_x, temp_y, x, y);
			//	return;

			}

		} while (true);
	}
}
void Zolw::rysowanie() {
	cout << 'Z';
}
bool Zolw::czyOdbijeAtak(Organizm* organizm) {
	if (organizm->getInicjatywa() < 5)
		return true;
	else
		return false;
}
void Zolw::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyZolw = new Zolw(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyZolw, n_x, n_y);
}