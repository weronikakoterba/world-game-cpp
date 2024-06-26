#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(int n_x, int n_y, Swiat* n_swiat) : Roslina(0, 0, n_x, n_y, Gatunek::guarana, n_swiat) {}

Guarana::~Guarana() {}

void Guarana::rysowanie()
{
	cout << "G";
}

bool Guarana::czyZwiekszaSile(Organizm* organizm)
{
	return true;
}

void Guarana::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowaGuarana = new Guarana(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowaGuarana, n_x, n_y);
	swiat->dodajWyniki("Nowa guarana na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}
