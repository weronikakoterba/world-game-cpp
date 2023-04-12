#include<iostream>
#include"Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include <vector>
using namespace std;

int Swiat::getSzerokosc() {
	return szerokosc;
}
int Swiat::getWysokosc() {
	return wysokosc;
}
Swiat::Swiat(int n_wysokosc, int n_szerokosc) :wysokosc(n_wysokosc),szerokosc(n_szerokosc){
	tab = new Organizm ** [n_wysokosc];
	for (int i = 0; i < n_wysokosc; i++) {
		tab[i] = new Organizm* [n_szerokosc];
		for (int j = 0; j < n_szerokosc; j++) {
			tab[i][j] = nullptr;
		}
	}

	// dodawanie wilków
	Organizm* nowy = new Wilk(10, 10, this);
	tab[10][10] = nowy;
	wektor.push_back(nowy);
	nowy = new Owca(12, 12, this);
	tab[12][12] = nowy;
	wektor.push_back(nowy);
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
				switch (tab[i][j]->gatunek) {
				case wilk:
					cout << 'W';
					break;
				case owca:
					cout << 'O';
					break;
				default:
					cout << '_';
				}
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

void Swiat::przesun_organizm(int temp_x, int temp_y, int x, int y)
{
	Organizm* temp = tab[temp_x][temp_y];

	// czy dochodzi do kolizji?
	if (tab[x][y] != nullptr)
	{
		// mamy kolizjê!
		temp->kolizja(tab[x][y]);
	}
	else
	{
		tab[temp_x][temp_y] = nullptr;
		tab[x][y] = temp;
	}

	//cout << "Wykonano ruch\n";
}

void Swiat::wykonajTure()
{
	unsigned ile = wektor.size();
	for (unsigned i = 0; i < ile; ++i)
	{
		cout << "chce wykonac akcje " << i << endl;
		wektor[i]->akcja();
	}
}