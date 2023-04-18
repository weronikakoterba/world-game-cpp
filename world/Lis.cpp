#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int n_x, int n_y, Swiat* n_swiat) : Zwierze(3, 7, n_x, n_y, Gatunek::lis, n_swiat) {
}

Lis::~Lis()
{
	cout << "Lis umiera\n";
}
void Lis::akcja() {
	temp_x = x;
	temp_y = y;
	//Organizm* temp = swiat->getTab();

	vector<Wspolrzedne> dostepne;
	dostepne.clear();
	Wspolrzedne kierunek;
	// lewo:
	if(x > 0)
		if (czyZaatakuje(x - 1, y))
		{
			kierunek.x = x - 1;
			kierunek.y = y;
			dostepne.push_back(kierunek);
		}
	if (x < szerokosc - 1) {
		if (czyZaatakuje(x+1, y))
		{
			kierunek.x = x+ 1;
			kierunek.y = y;
			dostepne.push_back(kierunek);
		}
	}
	if (y < wysokosc - 1) {
		if (czyZaatakuje(x, y+1))
		{
			kierunek.x = x;
			kierunek.y = y+1;
			dostepne.push_back(kierunek);
		}
	}
	if (y>0) {
		if (czyZaatakuje(x, y -1))
		{
			kierunek.x = x;
			kierunek.y = y-1;
			dostepne.push_back(kierunek);
		}
	}

	short size = dostepne.size();
	if (size > 0)
	{
		kierunek = dostepne[rand() % size];
		// przejœcie na podany kierunek
		cout << "Przesuwam lisa na pole " << kierunek.x << ' ' << kierunek.y << endl;
		swiat->przesun_organizm(temp_x, temp_y, kierunek.x, kierunek.y);
	}
}

void Lis::rysowanie() {
	cout << 'L';
}

bool Lis::czyZaatakuje(Organizm* organizm) {
	if (organizm->getSila() > getSila()) {
		cout << "silnieszy przeciwnik obok, nie ruszam siê na to pole" << endl;
		return false;
	}
		return true;
}

bool Lis::czyZaatakuje(int x, int y)
{
	Organizm* organizm = swiat->tab[x][y];
	if (organizm == nullptr) return true;
	return czyZaatakuje(organizm);
}

void Lis::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowyLis = new Lis(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowyLis, n_x, n_y);
}