#include<iostream>
#include"Swiat.h"
#include"Head.h"

#include <conio.h>

using namespace std;
int wysokosc = 5;
int szerokosc = 5;


int main() {

	srand(time(nullptr));
	Swiat s(wysokosc, szerokosc);
	s.rysujSwiat();
	s.rysujStanGry();

	while (true)
	{
	
	s.wykonajTure();
	_getch();
	system("cls");
	s.rysujSwiat();

	}


	return 0;
}