#include "WilczeJagody.h"
#include "Swiat.h"
WilczeJagody::WilczeJagody(int n_x, int n_y, Swiat* n_swiat) : Roslina(99, 0, n_x, n_y, Gatunek::wilczeJagody, n_swiat) {}

WilczeJagody::~WilczeJagody() {}

void WilczeJagody::rysowanie()
{
	cout << "J";
}

void WilczeJagody::stworzOrganizm(int n_x, int n_y)
{
	Organizm* noweJagody = new WilczeJagody(n_x, n_y, swiat);
	swiat->dodajOrganizm(noweJagody, n_x, n_y);
	swiat->dodajWyniki("Nowe wilcze jagody na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}

bool WilczeJagody::smierc(Organizm* organizm)
{
	return true;
}