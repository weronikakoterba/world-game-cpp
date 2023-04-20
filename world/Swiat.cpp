#include<iostream>
#include"Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include <vector>
#include <algorithm>
using namespace std;


Swiat::Swiat(int wysokosc, int szerokosc){
	tab = new Organizm ** [wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		tab[i] = new Organizm* [szerokosc];
		for (int j = 0; j < szerokosc; j++) {
			tab[i][j] = nullptr;
		}
	}

	// dodawanie wilków
	/*Organizm* nowy = new Wilk(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);*/
	//Organizm* nowy = new Owca(2, 2, this);
	//tab[2][2] = nowy;
	//wektor.push_back(nowy);
	//nowy = new Owca(4, 4, this);
	//tab[4][4] = nowy;
	//wektor.push_back(nowy);
	/*nowy = new Zolw(3, 3, this);
    tab[3][3] = nowy;
	wektor.push_back(nowy);*/
	/*Organizm* nowy = new Owca(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);
	nowy = new Lis(2, 2, this);
	tab[2][2] = nowy;
	wektor.push_back(nowy);*/
	/*Organizm* nowy = new Guarana(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);*/
	/*nowy = new Guarana(2, 2, this);
	tab[2][2] = nowy;*/
	//wektor.push_back(nowy);
	Organizm* nowy = new Owca(3, 3, this);
	tab[3][3] = nowy;
	wektor.push_back(nowy);
	nowy = new Zolw(4, 4, this);
	tab[4][4] = nowy;
	wektor.push_back(nowy);
	/*nowy = new Mlecz(3, 3, this);
	tab[3][3] = nowy;
	wektor.push_back(nowy);*/
	/*Organizm* nowy = new Antylopa(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);*/

	//wektor.push_back(nowy);

	/*nowy = new Wilk(5, 5, this);
	tab[5][5] = nowy;
	wektor.push_back(nowy);
	nowy = new Wilk(10, 10, this);
	tab[10][10] = nowy;
	wektor.push_back(nowy);*/
}

void Swiat::rysujSwiat() {
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			if (tab[i][j] == nullptr) cout << '_';
			else
			{
				tab[i][j]->rysowanie();//???
			}
		}
		cout << endl;
	}
}
void Swiat::rysujStanGry() {
	cout << "wyniki";
}
Swiat::~Swiat() {
	for (int i = 0; i < wysokosc; ++i) {
		for (int j = 0; j < szerokosc; ++j) {
			if (tab[i][j] != nullptr) {
				cout << "Wywoluje destruktor dla pozycji " << i << ',';
				delete tab[i][j];
			}
		}
	}
	for (int i = 0; i <wysokosc; ++i)
		delete[] tab[i];
	delete[] tab;
	cout << "Zniszczono swiat\n";
}

void Swiat::przesunOrganizm(int temp_x, int temp_y, int x, int y, bool sprawdzaj)
{
	Organizm* temp = tab[temp_x][temp_y];
		// czy dochodzi do kolizji?
	if (sprawdzaj && tab[x][y] != nullptr)
		{
				cout << "Dochodzi do kolizji!\n";
				temp->kolizja(tab[x][y]);
		}
		else
		{
				tab[temp_x][temp_y] = nullptr;
				tab[x][y] = temp;
				temp->x = x;
				temp->y = y;

			
		}

	//cout << "Wykonano ruch\n";
}

void Swiat::wykonajTure()
{
	sortowanie();
	unsigned ile = wektor.size();
	for (unsigned i = 0; i < wektor.size(); i++)// usuwanie w tej samej turze;
	{
		if (wektor[i]->getZyje() == true) {
			cout << "chce wykonac akcje " << i << endl;
			wektor[i]->akcja();
		}
	}
	for (int i = 0; i < wektor.size(); i++) {
		wektor[i]->zwiekszWiek();
	}	
}

bool porownanieOrganizmu(Organizm*& lewy, Organizm*& prawy) {
	if (lewy->getInicjatywa() > prawy->getInicjatywa()) {
		return true;
	}
	else if (lewy->getInicjatywa() == prawy->getInicjatywa()) {
		if (lewy->getWiek()>prawy->getWiek()) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void Swiat::sortowanie() {
	sort(wektor.begin(), wektor.end(), porownanieOrganizmu);
}

//bool czyUsunac(Organizm*& organizm) {
//	if (organizm->getZyje() == false) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}


void Swiat::usunOrganizm(Organizm* organizm)
{
	cout << "AAA\n";
	// usuniêcie z wektora
	unsigned size = wektor.size();
	for (unsigned i = 0; i < size; i++) {
		if (wektor[i] == organizm) {
			wektor.erase(wektor.begin() + i);
			break;
		}
	}
	cout << "AAA\n";
	// usuniêcie z planszy
	for (int i = 0; i < szerokosc; i++) {
		for (int j = 0; j < wysokosc; j++) {
			if (tab[i][j] == organizm)
			{
				delete tab[i][j];
				tab[i][j] = nullptr;
			}
		}
	}
	cout << "Organizm zostal usuniety.\n";
}

//void Swiat::usuwanieZabitych() {
//	auto zabijanie = remove_if(wektor.begin(), wektor.end(), czyUsunac);
//	for (auto i = zabijanie; i != wektor.end(); i++) {
//		delete *i;
//	}
//	wektor.erase(zabijanie,wektor.end());
//}

void Swiat::dodajOrganizm(Organizm* organizm, int x, int y)
{
	tab[x][y] = organizm;
	wektor.push_back(organizm);
}
