#include "Antylopa.h"
#include "Swiat.h"
Antylopa::Antylopa(int n_x, int n_y, Swiat* n_swiat) : Zwierze(4, 4, n_x, n_y, Gatunek::antylopa, n_swiat) {
}

Antylopa::~Antylopa()
{
	cout << "Wilk umiera\n";
}
void Antylopa::akcja(){
	//temp_x = x;
	//temp_y = y;

	//do {
	//	short kierunek = rand() % 4;		// losujê liczbê z przedzia³u <0, 7>
	//	cout << kierunek << endl;
	//	switch (kierunek) {
	//	case 0:		// pójœcie w górê
	//		if (y == 0 || y==1)
	//			break;
	//		y=y-2;

	//		swiat->przesun_organizm(temp_x, temp_y, x, y);
	//		return;
	//	case 1: // pojsce w dol
	//		if (y == wysokosc - 1 || y==wysokosc-2)
	//			break;
	//		y=y+2;

	//		swiat->przesun_organizm(temp_x, temp_y, x, y);
	//		return;
	//	case 2:// pojscie w prawo
	//		if (x == szerokosc - 1 || x==szerokosc-2)
	//			break;
	//		x=x+2;
	//		swiat->przesun_organizm(temp_x, temp_y, x, y);
	//		return;
	//	case 3:// pojscie w lewo
	//		if (x == 0 || x==1)
	//			break;
	//		x=x-2;

	//		swiat->przesun_organizm(temp_x, temp_y, x, y);
	//		return;
		//case 4: // gorny lewy rog
		//	if (x == 0 || x==1 || y == 0 || y==1)
		//		break;
		//	x=x-2;
		//	y=y-2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 5: // gorny prawy rog
		//	if (x == szerokosc - 1 || x==szerokosc-2 || y == 0 || y==1)
		//		break;
		//	x=x+2;
		//	y=y-2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 6: // dolny prawy rog
		//	if (x == szerokosc - 1 || x==szerokosc-2 || y == wysokosc - 1 || y==wysokosc-2)
		//		break;
		//	x=x+2;
		//	y=y+2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;
		//case 7: // dolny lewy rog
		//	if (x == 0 || x==1 || y == wysokosc - 1 || y==wysokosc-2)
		//		break;
		//	x=x-2;
		//	y=y+2;

		//	swiat->przesun_organizm(temp_x, temp_y, x, y);
		//	return;


		//}

	//} while (true);
	temp_x = x;
	temp_y = y;
	//Organizm* temp = swiat->getTab();

	vector<Wspolrzedne> dostepne;
	//dostepne.clear();
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
	swiat->przesun_organizm(temp_x, temp_y, kierunek.x, kierunek.y);
}
void Antylopa::rysowanie() {
	cout << 'A';
}

//bool Antylopa::czyUcieka() {
//	short szansa = rand() % 2;
//	if (szansa == 0) {
//		return false;
//	}
//	else
//		cout << "rezygnuje z ataku" << endl;
//		return true;
//}
void Antylopa::stworzOrganizm(int n_x, int n_y)
{
	Organizm* nowaAntylopa = new Antylopa(n_x, n_y, swiat);
	swiat->dodajOrganizm(nowaAntylopa, n_x, n_y);
}
void Antylopa::wybieraniePolaObok(int x,int y) {

	temp_x = x;
	temp_y = y;

	if (x < szerokosc - 1) {
		swiat->przesun_organizm(temp_x, temp_y, x+1, y);
	}
	else if (x > 0) {
		swiat->przesun_organizm(temp_x, temp_y, x-1, y);
	}
	else if (y < wysokosc - 1) {
		swiat->przesun_organizm(temp_x, temp_y, x, y+1);
	}
	else if (y > 0) {
		swiat->przesun_organizm(temp_x, temp_y, x, y-1);
	}
}
