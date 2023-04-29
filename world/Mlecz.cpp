#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(int n_x, int n_y, Swiat* n_swiat) : Roslina(0, 0, n_x, n_y, Gatunek::mlecz, n_swiat) {
	iloscRozsian = ILOSC_ROZSIAN_MLECZA;
}

Mlecz::~Mlecz() {}

void Mlecz::rysowanie()
{
	cout << "M";
}

void Mlecz::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyMlecz = new Mlecz(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyMlecz, n_x, n_y);
	swiat->dodajWyniki("Nowy mlecz na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}
