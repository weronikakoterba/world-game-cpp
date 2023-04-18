#include "Mlecz.h"
#include "Swiat.h"
Mlecz::Mlecz(int n_x, int n_y, Swiat* n_swiat) : Roslina(0, 0, n_x, n_y, Gatunek::mlecz, n_swiat) {
}

Mlecz::~Mlecz()
{
	cout << "mlecz umiera\n";
}

void Mlecz::rysowanie() {
	cout << "M";
}

int Mlecz::iloscRozsian() {
	return 3;
}

void Mlecz::stworzOrganizm(int n_x, int n_y){
	Organizm* nowyMlecz = new Mlecz(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyMlecz, n_x, n_y);
}
