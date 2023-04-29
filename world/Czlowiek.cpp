#include "Czlowiek.h"
#include "Swiat.h"
#include <conio.h>
#include "Zwierze.h"
#include "Organizm.h"



Czlowiek::Czlowiek(int n_x, int n_y, Swiat* n_swiat) : Zwierze(5, 4, n_x, n_y, Gatunek::czlowiek, n_swiat), aktywowanaUmiejetnosc(false), ileDoKonca(0) {}

Czlowiek::Czlowiek(int n_x, int n_y, Swiat* n_swiat, bool aktywowanaUmiejetnosc, int ileDoKonca, int ileDoStartu) : 
	Zwierze(5, 4, n_x, n_y, Gatunek::czlowiek, n_swiat), aktywowanaUmiejetnosc(aktywowanaUmiejetnosc), ileDoKonca(ileDoKonca),ileDoStartu(ileDoStartu) {}

Czlowiek::~Czlowiek(){}

void Czlowiek::rysowanie() 
{
	cout << "\02";
}

bool Czlowiek::getAktywowanaUmijetnpsc() 
{
	return aktywowanaUmiejetnosc;
}

int Czlowiek::getIleDoKonca()  
{
	return ileDoKonca;
}

int Czlowiek::getIleDoStartu()
{
	return ileDoStartu;
}

void Czlowiek::czyMoznaAktywowacUmiejetnosc() 
{
	int czyWlaczona;
	if (ileDoStartu > 0) 
	{
		ileDoStartu--;
		aktywowanaUmiejetnosc = false;
	}
	else 
	{
		ileDoStartu = 0;
	}

	if (ileDoStartu == 0) 
	{
		if (ileDoKonca > 0)
		{
			--ileDoKonca;
			if (ileDoKonca < TURY_Z_PELNA_UMIEJTNOSCIA && ileDoKonca>0) {
				czyWlaczona = rand() % SZANSA;
				if (czyWlaczona == 0) {
					aktywowanaUmiejetnosc = false;
				}
			}
			if (ileDoKonca == 0)
			{
				cout << "SPECJALNA UMIEJETNOSC WYGASLA!"<<endl;
				ileDoStartu = ILOSC_TUR;
				aktywowanaUmiejetnosc = false;
			}

		}
	}
}

void Czlowiek::akcja() 
{
	temp_x = x;
	temp_y = y;

	czyMoznaAktywowacUmiejetnosc();
	char kierunek;

	while (true)
	{
		do
		{
			kierunek = _getch();
			if (kierunek == 's') {
				swiat->zapiszDoPliku(aktywowanaUmiejetnosc,ileDoKonca,ileDoStartu);
			}
		} while (kierunek != key_up_arrow && kierunek != key_down_arrow && kierunek != key_left_arrow && kierunek != key_right_arrow && kierunek != key_enter);

		if (kierunek == key_enter && ileDoStartu==0 && aktywowanaUmiejetnosc == false)
		{
			aktywowanaUmiejetnosc = true;
			cout << "SPECJALNA UMIEJETNOSC ZOSTALA AKTYWOWANA!"<<endl;
			_getch();
			ileDoKonca = ILOSC_TUR;
			continue;
		}
		int odleglosc;
		if (aktywowanaUmiejetnosc) 
		{
			odleglosc = PREDKOSC_ANTYLOPY;
		}
		else 
		{
			odleglosc = 1;
		}

		switch (kierunek)
		{
		case key_up_arrow:	// pójœcie w górê
			if (y > (odleglosc - 1))
			{
				swiat->przesunOrganizm(temp_x, temp_y, x, y - odleglosc, true);
				return;
			}
			break;
		case key_left_arrow: // pójœcie w lewo
			if (x > (odleglosc - 1))
			{
				swiat->przesunOrganizm(temp_x, temp_y, x - odleglosc, y, true);
				return;
			}
			break;
		case key_down_arrow: // pójœcie w dó³
			if (y < swiat->getWysokosc() - odleglosc)
			{
				swiat->przesunOrganizm(temp_x, temp_y, x, y + odleglosc, true);
				return;
			}
			break;
		case key_right_arrow: // pójœcie w prawo
			if (x < swiat->getSzerokosc() - odleglosc)
			{
				swiat->przesunOrganizm(temp_x, temp_y, x + odleglosc, y, true);
				return;
			}
		}
	}
}


void Czlowiek::stworzOrganizm(int n_x, int n_y) {}