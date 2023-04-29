#include "BarszczSosnowskiego.h"
#include "Swiat.h"

BarszczSosnowskiego::BarszczSosnowskiego(int n_x, int n_y, Swiat* n_swiat) : Roslina(10, 0, n_x, n_y, Gatunek::barszczSosnowskiego, n_swiat)
{
	czyZabijaSasiadow = true;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}

void BarszczSosnowskiego::rysowanie()
{
	cout << "B";
}

void BarszczSosnowskiego::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyBarszcz = new BarszczSosnowskiego(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyBarszcz, n_x, n_y);
	swiat->dodajWyniki("Nowy barszcz sosnowskiego na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}

bool BarszczSosnowskiego::smierc()
{
	return true;
}

