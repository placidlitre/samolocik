#include <iostream>
#include <vector>
using namespace std;


char MapaSamolotow[60][10];

class Samolot
{
	int x;
	int y;
	int kierunek;
	char litera;

	void zmianaY()
	{
		if (kierunek < 0)
		{
			y++;
			kierunek++;
		}
		else if (kierunek > 0)
		{
			y--;
			kierunek--;
		}
	}

	void wpiszKierunek(int komendaKierunek)
	{
		kierunek = komendaKierunek;
	}

};

void wpiszKomende()
{
	
}


void Plansza()
{
	for (int i = 0; i < 62; i++)
		cout << "=";
	for (int i = 0; i < 10; i++)
	{
		cout << "|";
		for (int j = 0; j < 62; j++)
		{
			
		}
	}
}

int main()
{
	
}
