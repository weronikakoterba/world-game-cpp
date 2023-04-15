#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int n_x, int n_y, Swiat* n_swiat) : Zwierze(3, 7, n_x, n_y, Gatunek::lis, n_swiat) {
}

Lis::~Lis()
{
	cout << "Lis umiera\n";
}
void Lis::akcja(Organizm* organizm, Swiat* swiat) {
	temp_x = x;
	temp_y = y;
	//Organizm* temp = swiat->getTab();

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
		}

	} while (true);
}

void Lis::rysowanie() {
	cout << 'L';
}

bool Lis::czyZaatakuje(Organizm* organizm) {
	if (organizm->getSila() > this->getSila()) {
		return false;
		cout << "silnieszy przeciwnik obok, nie ruszam siê na to pole" << endl;
	}
	else {
		return true;
	}
}
void Lis::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyLis = new Lis(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyLis, n_x, n_y);
}