#include "Trawa.h"
#include "Swiat.h"
Trawa::Trawa(int n_x, int n_y, Swiat* n_swiat) : Roslina(0, 0, n_x, n_y, Gatunek::trawa, n_swiat) {
}

Trawa::~Trawa()
{
	cout << "trawa umiera\n";
}

void Trawa::rysowanie() {
	cout << "T";
}

void Trawa::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowaTrawa = new Trawa(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowaTrawa, n_x, n_y);
}
