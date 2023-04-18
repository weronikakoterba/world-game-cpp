#include<iostream>
#include"Roslina.h"
#include "Swiat.h"
using namespace std;

Roslina::Roslina(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) :
	Organizm(n_sila, n_inicjatywa, n_x, n_y, n_gatunek, n_swiat) {}

Roslina::~Roslina() {}

void Roslina::rozsiewanie(int x, int y) {
	if (swiat->tab[x][y] == nullptr) {
		stworzOrganizm(x, y);
	}
	else {
		return;
	}
}
////void Roslina::kolizja(Organizm* organizm) {
//	if (this - )
//}
void Roslina::akcja() {
	for (int i = 0; i < iloscRozsian(); i++) {
		short szansaZasiania = rand() % 5;
		cout << szansaZasiania << endl;
		// pójœcie w górê
		if (szansaZasiania == 0) {
			do {
				short kierunek = rand() % 4;
				cout << kierunek << endl;
				switch (kierunek) {
				case 0:		// pójœcie w górê
					if (y == 0)
						break;
					y--;
					rozsiewanie(x, y);
					return;
				case 1: // pojsce w dol
					if (y == wysokosc - 1)
						break;
					y++;
					rozsiewanie(x, y);
					return;
				case 2:// pojscie w prawo
					if (x == szerokosc - 1)
						break;
					x++;
					rozsiewanie(x, y);
					return;
				case 3:// pojscie w lewo
					if (x == 0)
						break;
					x--;
					rozsiewanie(x, y);
					return;
				}
			} while (true);
		}
	}
}


bool Roslina::czyOdbijeAtak(Organizm* organizm)
{
	return false;
}

bool Roslina::czyZaatakuje(Organizm* organizm)
{
	return true;
}
bool Roslina::czyUcieka() {
	return false;
}
int Roslina::iloscRozsian() {
	return 1;
}
