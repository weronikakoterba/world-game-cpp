#include<iostream>
#include <cstdlib>
#include <ctime>
#include"Zwierze.h"
#include "Swiat.h"
using namespace std;

/*class Zwierze :public Organizm {
public:
	Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek);
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
};*/

Zwierze::Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) :
	Organizm(n_sila, n_inicjatywa, n_x, n_y, n_gatunek, n_swiat) {}

Zwierze::~Zwierze(){}

void Zwierze::akcja() {
	/*//cout << "Wchodze do akcji\n";

	temp_x = x;
	temp_y = y;

	do{
		short kierunek = rand() % 4;
		cout << kierunek << endl;
		switch (kierunek){
		case 0:		// pójœcie w górê
			if (y == 0)
				break;
			y--;
			swiat->przesun_organizm(temp_x, temp_y, x, y);
			cout << "przesuwa sie na pole " << x << y<<endl;
			return;
		case 1: // pojsce w dol
			if (y == wysokosc - 1)
				break;
			y++;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			cout << "przesuwa sie na pole " << x << y<<endl;
			return;
		case 2:// pojscie w prawo
			if (x==szerokosc - 1)
				break;
			x++;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			cout << "przesuwa sie na pole " << x << y << endl;
			return;
		case 3:// pojscie w lewo
			if (x == 0)
				break;
			x--;

			swiat->przesun_organizm(temp_x, temp_y, x, y);
			cout << "przesuwa sie na pole " << x << y << endl;
			return;
		//case 4: // gorny lewy rog
		//	if (x == 0 || y == 0)
		//		break;
		//	x--;
		//	y--;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 5: // gorny prawy rog
		//	if (x == szerokosc-1 || y == 0)
		//		break;
		//	x++;
		//	y--;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 6: // dolny prawy rog
		//	if (x == szerokosc - 1 || y == wysokosc-1)
		//		break;
		//	x++;
		//	y++;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 7: // dolny lewy rog
		//	if (x == 0 || y == wysokosc-1)
		//		break;
		//	x--;
		//	y++;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;

		}
	
	} while (true);	*/

	temp_x = x;
	temp_y = y;
	//Organizm* temp = swiat->getTab();

	vector<Wspolrzedne> dostepne;
	dostepne.clear();
	Wspolrzedne kierunek;
	// lewo:
	if (x > 0)
	{
		kierunek.x = x - 1;
		kierunek.y = y;
		dostepne.push_back(kierunek);
	}
	if (x < szerokosc - 1)
	{
		kierunek.x = x + 1;
		kierunek.y = y;
		dostepne.push_back(kierunek);
	}
	if (y < wysokosc - 1)
	{
		kierunek.x = x;
		kierunek.y = y + 1;
		dostepne.push_back(kierunek);
	}
	if (y > 0)
	{
		kierunek.x = x;
		kierunek.y = y - 1;
		dostepne.push_back(kierunek);
	}

	kierunek = dostepne[rand() % dostepne.size()];
	// przejœcie na podany kierunek
	cout << "Przesuwam zwierze na pole " << kierunek.x << ' ' << kierunek.y << endl;
	swiat->przesun_organizm(temp_x, temp_y, kierunek.x, kierunek.y);
}

void Zwierze::rozmnazanie(Organizm* organizm) {
	x = temp_x;
	y = temp_y;

	if (temp_x<szerokosc-1 && swiat->tab[temp_x + 1][temp_y] == nullptr) {
		organizm->stworzOrganizm(temp_x + 1, temp_y);
	}
	else if (temp_x >0 && swiat->tab[temp_x -1][temp_y] == nullptr) {
		organizm->stworzOrganizm(temp_x - 1, temp_y);
	}
	else if (temp_y<wysokosc-1 && swiat->tab[temp_x][temp_y+1] == nullptr) {
		organizm->stworzOrganizm(temp_x, temp_y + 1);
	}
	else if (temp_y>0 && swiat->tab[temp_x][temp_y-1] == nullptr) {
		organizm->stworzOrganizm(temp_x, temp_y - 1);
	}
}





void Zwierze::kolizja(Organizm* organizm) {
	if (organizm->gatunek == this->gatunek)
	{
		// rozmna¿anie
		cout << "rozmnazanie\n";
		rozmnazanie(organizm);
		//rozmnazanie(organizm);
		// utworzyæ metodê, która na wolnym losowym polu obok tworzy dodatkowy obiekt tego samego typu
	}
	else
	{
		// walka
		if (this->sila >= organizm->sila)
		{
			if (organizm->czyOdbijeAtak(this) == false) {
				/*organizm->zyje = false;
				this->swiat->tab[x][y] = this;
				this->swiat->tab[temp_x][temp_y] = nullptr;*/
				// usuwamy organizm:
				cout << "Usuwam organizm\n";
				//this->swiat->tab[x][y] = this;
				organizm->swiat->usun_organizm(organizm);// funkcja usuwaj¹ca organizm z planszy i z wektora

				swiat->przesun_organizm(temp_x, temp_y, x, y);	// agresor zajmuje nowe pole
				//return;
			}
			// walka wygrana
			// zmiana na planszy
			// œmieræ organizmu, któy dotychczas zajmowa³ to pole (usuniêcie go z planszy i z wektora)
			// utworzyæ metodê, która usuwa z wektora element o danym adresie komórki
		}
		else{
			/*this->zyje = false;
			this->swiat->tab[temp_x][temp_y] = nullptr;*/
			swiat->usun_organizm(this);
		}
	}
}

bool Zwierze::czyOdbijeAtak(Organizm* organizm)
{
	return false;
}

bool Zwierze::czyZaatakuje(Organizm* organizm)
{
	return true;
}
bool Zwierze::czyUcieka() {
	return false;
}

