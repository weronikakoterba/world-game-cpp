#include "Antylopa.h"
#include "Swiat.h"
Antylopa::Antylopa(int n_x, int n_y, Swiat* n_swiat) : Zwierze(4, 4, n_x, n_y, Gatunek::antylopa, n_swiat) {
}

Antylopa::~Antylopa()
{
	cout << "Wilk umiera\n";
}
void Antylopa::akcja(){
	
	temp_x = x;
	temp_y = y;

	vector<Wspolrzedne> dostepne;
	Wspolrzedne kierunek;
	// lewo:
	if (x > 1)
	{
		kierunek.x = x - 2;
		kierunek.y = y;
		dostepne.push_back(kierunek);
	}
	if (x < szerokosc - 2)
	{
		kierunek.x = x + 2;
		kierunek.y = y;
		dostepne.push_back(kierunek);
	}
	if (y < wysokosc - 2)
	{
		kierunek.x = x;
		kierunek.y = y + 2;
		dostepne.push_back(kierunek);
	}
	if (y > 1)
	{
		kierunek.x = x;
		kierunek.y = y - 2;
		dostepne.push_back(kierunek);
	}

	kierunek = dostepne[rand() % dostepne.size()];
	// przejœcie na podany kierunek

	if (swiat->tab[kierunek.x][kierunek.y] != nullptr)
	{
		if (swiat->tab[kierunek.x][kierunek.y]->gatunek != Gatunek::antylopa)
		{
			//wylosowane pole nie jest puste, wiêc antylopa ma 50% szans, aby unikn¹æ przejœcia na to pole
			if (rand() % 2 == 0)
			{
				cout << "Odstepuje od przejscia na pole\n";
				// przesuwam w zamian na pole wolne, gdzieœ obok
				wybieraniePolaObok(temp_x, temp_y);
				return;
			}
		}
	}

	cout << "Przesuwam antylope na pole " << kierunek.x << ' ' << kierunek.y << endl;
	swiat->przesunOrganizm(temp_x, temp_y, kierunek.x, kierunek.y,true);
}
void Antylopa::rysowanie() {
	cout << 'A';
}

void Antylopa::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowaAntylopa = new Antylopa(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowaAntylopa, n_x, n_y);
}

void Antylopa::wybieraniePolaObok(int x,int y) {

	temp_x = x;
	temp_y = y;

	if (x < szerokosc - 1) {
		swiat->przesunOrganizm(temp_x, temp_y, x+1, y,true);
	}
	else if (x > 0) {
		swiat->przesunOrganizm(temp_x, temp_y, x-1, y, true);
	}
	else if (y < wysokosc - 1) {
		swiat->przesunOrganizm(temp_x, temp_y, x, y+1, true);
	}
	else if (y > 0) {
		swiat->przesunOrganizm(temp_x, temp_y, x, y-1, true);
	}
}
