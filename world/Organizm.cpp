#include <iostream>
#include "Organizm.h"
using namespace std;

/*class Organizm {
	//friend ostream& operator<<(ostream& out, const Organizm& obiekt);
	friend class Swiat;
protected:
	Swiat* swiat;
	Gatunek gatunek;
	int sila;
	int inicjatywa;
	int x;
	int y;
public:
	Organizm(int n_sila, int n_inicjatywa, int n_x, int n_y,Gatunek n_gatunek, Swiat* n_swiat);
	~Organizm();
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
};*/

int Organizm::getWiek() {
	return wiek;
}
int Organizm::getInicjatywa() {
	return inicjatywa;
}
int Organizm::getSila() {
	return sila;
}
bool Organizm::getZyje() {
	return zyje;
}

Organizm::Organizm(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) 
	:sila(n_sila), inicjatywa(n_inicjatywa),x(n_x),y(n_y),gatunek(n_gatunek), swiat(n_swiat) {
}

Organizm::~Organizm() { cout << "del\n"; }
void Organizm::zwiekszWiek()
{
	wiek++;
}
/*ostream& operator<<(ostream& out, const Organizm& obiekt) {
	switch (obiekt.gatunek) {
	case kot:
		out << "K";
		return out;
	case pies:
		out << "p";
		return out;
	default:
		return out;
	}
}*/
