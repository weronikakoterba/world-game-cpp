#include "Wilk.h"
#include "Swiat.h"

Wilk::Wilk(int n_x, int n_y, Swiat* n_swiat) : Zwierze(9, 5, n_x, n_y, Gatunek::wilk, n_swiat) {}

Wilk::~Wilk() {}

void Wilk::rysowanie()
{
	cout << "W";
}

void Wilk::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyWilk = new Wilk(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyWilk, n_x, n_y);
	swiat->dodajWyniki("Nowy wilk na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}
