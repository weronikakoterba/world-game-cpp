#include<iostream>
#include"Swiat.h"
#include"Head.h"
#include <conio.h>
#include "Czlowiek.h"

using namespace std;

int main() 
{
	srand(time(nullptr));
	Swiat* nowySwiat = nullptr;
	char number;
	int szerokosc;
	int wysokosc;
	char* p;
	while (true) 
	{
		cout << "ABY ROZPOCZAC GRE, WYBIERZ OPCJE:"<<endl<<"1)WCZYTAJ GRE Z PLIKU"<<endl<<"2)ROZPOCZNIJ NOWA GRE"<<endl;
		cin >> number;
		if (number == '1') {
			nowySwiat = new Swiat();
			nowySwiat->uruchomZPliku();
			break;
		}
		else if (number == '2') 
		{
			while (true) 
			{
				cout << "WPISZ SZEROKOSC PLANSZY(MIN 10):" << endl;
				string szerokoscS;
				cin >> szerokoscS;
				szerokosc = strtol(szerokoscS.c_str(), &p, SYSTEM_LICZBOWY);
				if (*p==0 && szerokosc >= MIN_WYMIARY)
				{
					break;
				}
				else 
				{
					cout << "NIEPOPRAWANA SZEROKOSC PLANSZY" << endl;
				}
			}
			while (true) 
			{
				cout << "WPISZ WYSOKOSC PLANSZY(MIN 10):" << endl;
				string wysokoscS;
				cin >> wysokoscS;
				wysokosc = strtol(wysokoscS.c_str(), &p, SYSTEM_LICZBOWY);
				if (*p==0 && wysokosc>=MIN_WYMIARY) 
				{
					break;
				}
				else 
				{
					cout<<"NIEPOPRAWNA WYSOKOSC PLANSZY:"<<endl;
				}
			}
			nowySwiat = new Swiat(wysokosc, szerokosc);
			nowySwiat->rysujOrganizmy();
			break;
		}
		else 
		{
			cout << "NIE MA TAKIEJ OPCJI DO WYBORU"<<endl;
		}
	}
	system("cls");
	while (true)
	{
		nowySwiat->wazneInformacje();
		nowySwiat->rysujSwiat();
		nowySwiat->wykonajTure();
		nowySwiat->rysujWyniki();
		nowySwiat->nowaTura();
	}
	return 0;
}