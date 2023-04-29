#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include"Zwierze.h"
#include "Swiat.h"
using namespace std;

Zwierze::Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) : Organizm(n_sila, n_inicjatywa, n_x, n_y, n_gatunek, n_swiat) {}

Zwierze::~Zwierze() {}

void Zwierze::akcja() {

	temp_x = x;
	temp_y = y;

	short szansa = rand() % mozliwoscRuchu;

	if (szansa == 0)
	{
		vector<Wspolrzedne> dostepne;
		Wspolrzedne kierunek;

		if (x > 0)
			if (czyZaatakuje(x - 1, y))
			{
				kierunek.x = x - 1;
				kierunek.y = y;
				dostepne.push_back(kierunek);
			}
		if (x < swiat->getSzerokosc() - 1) {
			if (czyZaatakuje(x + 1, y))
			{
				kierunek.x = x + 1;
				kierunek.y = y;
				dostepne.push_back(kierunek);
			}
		}
		if (y < swiat->getWysokosc() - 1) {
			if (czyZaatakuje(x, y + 1))
			{
				kierunek.x = x;
				kierunek.y = y + 1;
				dostepne.push_back(kierunek);
			}
		}
		if (y > 0) {
			if (czyZaatakuje(x, y - 1))
			{
				kierunek.x = x;
				kierunek.y = y - 1;
				dostepne.push_back(kierunek);
			}
		}
		short size = dostepne.size();
		if (size > 0)
		{
			kierunek = dostepne[rand() % size];
			swiat->przesunOrganizm(temp_x, temp_y, kierunek.x, kierunek.y, true);
		}
	}
}

void Zwierze::rozmnazanie(Organizm* organizm)
{
	x = temp_x;
	y = temp_y;

	if (temp_x < swiat->getSzerokosc() - 1 && swiat->getTab()[temp_y][temp_x + 1] == nullptr) {
		organizm->stworzOrganizm(temp_x + 1, temp_y);
	}
	else if (temp_x > 0 && swiat->getTab()[temp_y][temp_x - 1] == nullptr) {
		organizm->stworzOrganizm(temp_x - 1, temp_y);
	}
	else if (temp_y < swiat->getWysokosc() - 1 && swiat->getTab()[temp_y + 1][temp_x] == nullptr) {
		organizm->stworzOrganizm(temp_x, temp_y + 1);
	}
	else if (temp_y > 0 && swiat->getTab()[temp_y - 1][temp_x] == nullptr) {
		organizm->stworzOrganizm(temp_x, temp_y - 1);
	}
}

void Zwierze::kolizja(Organizm* organizm)
{
	swiat->dodajWyniki("Kolizja organizmu " + swiat->wypiszOrganizmy(this) + "z organizmem " + swiat->wypiszOrganizmy(organizm) +
		"na polu (" + to_string(organizm->getX()) + "," + to_string(organizm->getY()) + ")");
	if (organizm->smierc()) {
		swiat->usunOrganizm(this);
		return;
	}
	if (organizm->getGatunek() == this->getGatunek() && organizm->czyOdbijeAtak(this) == false)
	{
		if (organizm->getWiek() != 0)
		{
			rozmnazanie(organizm);
		}
		else
			return;
	}
	else
	{
		// walka
		if (this->getSila() >= organizm->getSila())
		{
			if (organizm->czyOdbijeAtak(this) == false) {
				if (organizm->czyZwiekszaSile(organizm)) {
					sila += DODATKOWA_SILA;
					swiat->dodajWyniki("Sila organizmu " + swiat->wypiszOrganizmy(this) + "(" + to_string(x) + "," + to_string(y) + ") wzrosla do " + to_string(sila));
				}
				// wspó³rzêdne zwierzêcia zabijanego
				int temp_x = organizm->getX();
				int temp_y = organizm->getY();
				swiat->dodajWyniki("Zabito organizm " + swiat->wypiszOrganizmy(organizm));
				organizm->getSwiat()->usunOrganizm(organizm);
				swiat->przesunOrganizm(x, y, temp_x, temp_y, false);
			}
			else
			{
				swiat->dodajWyniki("Organizm " + swiat->wypiszOrganizmy(organizm) + "odbil atak organizmu " + swiat->wypiszOrganizmy(this) +
					"na polu (" + to_string(organizm->getX()) + ", " + to_string(organizm->getY()) + ")");
			}
		}
		else {
			swiat->dodajWyniki("Zabito organizm " + swiat->wypiszOrganizmy(this));
			swiat->usunOrganizm(this);
		}
	}
}

bool Zwierze::czyOdbijeAtak(Organizm* organizm)
{
	return false;
}

bool Zwierze::czyZaatakuje(int x, int y)
{
	return true;
}

bool Zwierze::czyZwiekszaSile(Organizm* organizm)
{
	return false;
}

bool Zwierze::smierc()
{
	return false;
}

