#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int n_x, int n_y, Swiat* n_swiat) : Zwierze(3, 7, n_x, n_y, Gatunek::lis, n_swiat) {}

Lis::~Lis() {}

void Lis::rysowanie()
{
	cout << 'L';
}

bool Lis::czyZaatakuje(Organizm* organizm)
{
	if (organizm->getSila() > getSila() && organizm->getGatunek() != getGatunek()) {
		return false;
	}
	return true;
}

bool Lis::czyZaatakuje(int x, int y)
{
	Organizm* organizm = swiat->getTab()[y][x];
	if (organizm == nullptr) return true;
	return czyZaatakuje(organizm);
}

void Lis::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyLis = new Lis(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyLis, n_x, n_y);
	swiat->dodajWyniki("Nowy lis na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}