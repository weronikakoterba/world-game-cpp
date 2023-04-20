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

		vector<Wspolrzedne> dostepne;
		Wspolrzedne kierunek;
		// lewo:
		if (x > 0)
		{
			kierunek.x = x - 1;
			kierunek.y = y;
			dostepne.push_back(kierunek);
		}
		if (x < szerokosc - 1)
		{
			kierunek.x = x + 1;
			kierunek.y = y;
			dostepne.push_back(kierunek);
		}
		if (y < wysokosc - 1)
		{
			kierunek.x = x;
			kierunek.y = y + 1;
			dostepne.push_back(kierunek);
		}
		if (y > 0)
		{
			kierunek.x = x;
			kierunek.y = y - 1;
			dostepne.push_back(kierunek);
		}

		kierunek = dostepne[rand() % dostepne.size()];
		// przejœcie na podany kierunek
		cout << "Przesuwam zwierze na pole " << kierunek.x << ' ' << kierunek.y << endl;
		swiat->przesunOrganizm(temp_x, temp_y, kierunek.x, kierunek.y,true);
	}
}
void Zolw::rysowanie() {
	cout << 'Z';
}

bool Zolw::czyOdbijeAtak(Organizm* organizm) {
	if (organizm->getSila() < 5) {
		cout << "odbija atak" << endl;
		return true;
	}
	else {
		cout << "nie odbija ataku\n";
		return false;
	}
}
void Zolw::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyZolw = new Zolw(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyZolw, n_x, n_y);
}