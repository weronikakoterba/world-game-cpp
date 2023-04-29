#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(int n_x, int n_y, Swiat* n_swiat) : Zwierze(4, 4, n_x, n_y, Gatunek::antylopa, n_swiat) {}

Antylopa::~Antylopa() {}

void Antylopa::akcja()
{
	temp_x = x;
	temp_y = y;

	vector<Wspolrzedne> dostepne;
	Wspolrzedne kierunek;
	// lewo:
	if (x > 1)
	{
		kierunek.x = x - PREDKOSC_ANTYLOPY;
		kierunek.y = y;
		dostepne.push_back(kierunek);
	}
	//prawo:
	if (x < swiat->getSzerokosc() - PREDKOSC_ANTYLOPY)
	{
		kierunek.x = x + PREDKOSC_ANTYLOPY;
		kierunek.y = y;
		dostepne.push_back(kierunek);
	}
	//dol:
	if (y < swiat->getWysokosc() - PREDKOSC_ANTYLOPY)
	{
		kierunek.x = x;
		kierunek.y = y + PREDKOSC_ANTYLOPY;
		dostepne.push_back(kierunek);
	}
	//gora:
	if (y > 1)
	{
		kierunek.x = x;
		kierunek.y = y - PREDKOSC_ANTYLOPY;
		dostepne.push_back(kierunek);
	}

	kierunek = dostepne[rand() % dostepne.size()];
	if (swiat->getTab()[kierunek.y][kierunek.x] != nullptr)
	{
		if (swiat->getTab()[kierunek.y][kierunek.x]->getGatunek() != Gatunek::antylopa)//wylosowane pole nie jest puste, wiêc antylopa ma 50% szans, aby unikn¹æ przejœcia na to pole
		{
			if (rand() % 2 == 0)// przesuwam w zamian na pole wolne, gdzieœ obok
			{
				swiat->dodajWyniki("Antylopa rezygnuje z walki na polu (" + to_string(kierunek.x) + ", " + to_string(kierunek.y) + ")");
				wybieraniePolaObok(temp_x, temp_y);
				return;
			}
		}
	}
	swiat->przesunOrganizm(temp_x, temp_y, kierunek.x, kierunek.y, true);
}

void Antylopa::rysowanie()
{
	cout << 'A';
}

void Antylopa::wybieraniePolaObok(int x, int y)
{
	temp_x = x;
	temp_y = y;

	if (x < swiat->getSzerokosc() - 1)
	{
		swiat->przesunOrganizm(temp_x, temp_y, x + 1, y, true);
	}
	else if (x > 0)
	{
		swiat->przesunOrganizm(temp_x, temp_y, x - 1, y, true);
	}
	else if (y < swiat->getWysokosc() - 1)
	{
		swiat->przesunOrganizm(temp_x, temp_y, x, y + 1, true);
	}
	else if (y > 0)
	{
		swiat->przesunOrganizm(temp_x, temp_y, x, y - 1, true);
	}
}

void Antylopa::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowaAntylopa = new Antylopa(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowaAntylopa, n_x, n_y);
	swiat->dodajWyniki("Nowa antylopa na planszy(" + to_string(n_x) + "," + to_string(n_y) + ")");
}
