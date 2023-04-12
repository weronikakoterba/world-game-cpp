#include<iostream>
#include <cstdlib>
#include <ctime>
#include"Zwierze.h"
#include "Swiat.h"
using namespace std;

/*class Zwierze :public Organizm {
public:
	Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek);
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
};*/

Zwierze::Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) :
	Organizm(n_sila, n_inicjatywa, n_x, n_y, n_gatunek, n_swiat) {}

Zwierze::~Zwierze(){}

void Zwierze::akcja() {
	//cout << "Wchodze do akcji\n";

	temp_x = x;
	temp_y = y;

	do{
		short kierunek = rand() % 8;		// losuj� liczb� z przedzia�u <0, 7>
		cout << kierunek << endl;
		switch (kierunek){
		case 0:		// p�j�cie w g�r�
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
			if (x==szerokosc - 1)
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
		case 4: // gorny lewy rog
			if (x == 0 || y == 0)
				break;
			x--;
			y--;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		case 5: // gorny prawy rog
			if (x == szerokosc-1 || y == 0)
				break;
			x++;
			y--;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		case 6: // dolny prawy rog
			if (x == szerokosc - 1 || y == wysokosc-1)
				break;
			x++;
			y++;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;
		case 7: // dolny lewy rog
			if (x == 0 || y == wysokosc-1)
				break;
			x--;
			y++;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			return;

		}
	
	} while (true);	
}

void Zwierze::kolizja(Organizm* organizm) {
	if (organizm->gatunek == this->gatunek)
	{
		// rozmna�anie
		cout << "rozmnazanie\n";
		// utworzy� metod�, kt�ra na wolnym losowym polu obok tworzy dodatkowy obiekt tego samego typu
	}
	else
	{
		// walka
		if (this->sila > organizm->sila)
		{
			// walka wygrana
			// zmiana na planszy
			// �mier� organizmu, kt�y dotychczas zajmowa� to pole (usuni�cie go z planszy i z wektora)
			// utworzy� metod�, kt�ra usuwa z wektora element o danym adresie kom�rki
		}
	}
}