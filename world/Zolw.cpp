#include "Zolw.h"
#include "Swiat.h"


Zolw::Zolw(int n_x, int n_y, Swiat* n_swiat) : Zwierze(2, 1, n_x, n_y, Gatunek::zolw, n_swiat)
{
	mozliwoscRuchu = 4;
}

Zolw::~Zolw() {}

void Zolw::rysowanie()
{
	cout << 'Z';
}

bool Zolw::czyOdbijeAtak(Organizm* organizm)
{
	if (organizm->getSila() < 5 && organizm->getGatunek() != getGatunek()) {
		return true;
	}
	else {
		return false;
	}
}

void Zolw::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyZolw = new Zolw(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyZolw, n_x, n_y);
	swiat->dodajWyniki("Nowy zolw na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}