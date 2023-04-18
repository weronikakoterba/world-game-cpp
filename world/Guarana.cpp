#include "Guarana.h"
#include "Swiat.h"
Guarana::Guarana(int n_x, int n_y, Swiat* n_swiat) : Roslina(0, 0, n_x, n_y, Gatunek::guarana, n_swiat) {
}
Guarana::~Guarana()
{
	cout << "mlecz umiera\n";
}

void Guarana::rysowanie() {
	cout << "G";
}
//void Guarana::zwiêkszSile(Organizm* organizm) {
//}

void Guarana::stworzOrganizm(int n_x, int n_y) {
	Organizm* nowaGuarana = new Guarana(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowaGuarana, n_x, n_y);
}
