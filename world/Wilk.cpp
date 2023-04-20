#include "Wilk.h"
#include "Swiat.h"

/*class Wilk :public Zwierze
{
public:
	Wilk(int n_x, int n_y);
	~Wilk();
	 void akcja();
	 void kolizja();
	 void rysowanie();
};*/

Wilk::Wilk(int n_x, int n_y, Swiat* n_swiat) : Zwierze(9, 5, n_x, n_y, Gatunek::wilk, n_swiat) {
}

Wilk::~Wilk()
{
	cout << "Wilk umiera\n";
}

void Wilk::rysowanie() {
	cout << "W";
}

void Wilk::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyWilk = new Wilk(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyWilk,n_x, n_y);
}
