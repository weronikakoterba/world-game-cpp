#include "Owca.h"

Owca::Owca(int n_x, int n_y, Swiat* n_swiat) : Zwierze(4, 4, n_x, n_y, Gatunek::owca, n_swiat) {}

Owca::~Owca() {}

void Owca::rysowanie()
{
	cout << 'O';
}

void Owca::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyWilk = new Owca(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyWilk, n_x, n_y);
	swiat->dodajWyniki("Nowa owca na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}