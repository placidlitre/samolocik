#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;


char MapaSamolotow[60][10];

class Samolot
{

	int x;
	int poziomY;
	int zmianaLotu;
	char litera;
public:
	Samolot() : litera('X'), poziomY(0), zmianaLotu(0), x(0) {}
	Samolot(const char& literka, const int& poziomekY, const int& zmianaLotku, const int& xek) : litera(literka), poziomY(poziomekY), zmianaLotu(zmianaLotku), x(xek) {}

	void zmianaY()
	{
		if (zmianaLotu < 0)
		{
			poziomY--;
			zmianaLotu++;
		}
		else if (zmianaLotu > 0)
		{
			poziomY++;
			zmianaLotu--;
		}
	}

	void wpisanieZmianyLotu(int zmianaLotku)
	{
		zmianaLotu = zmianaLotku;
	}

	void pokazSamolot()
	{
		cout << litera << endl;
		cout << poziomY << endl;
		cout << zmianaLotu << endl;
		cout << endl;
	}

};


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

void tworzenieSamolotu(vector<Samolot>& samoloty, int& licznikSamolotow)
{
	int liniaY = rand() % 10;
	samoloty.emplace_back((char(65 + licznikSamolotow)), liniaY, 0, 0); //tworzy obiekt + odrazu działa konstruktor który wpisuje mu daną litere w liście inicjalizacyjnej

	samoloty[licznikSamolotow].pokazSamolot();

	if (licznikSamolotow < 31)
		licznikSamolotow++;
	else
		licznikSamolotow = 0;
}

void kontrolaLotow(vector<Samolot>& samoloty, int liczbaSamolotow)
{
	string komenda;
	char szukanaLiteraSamolotu;
	while (true)
	{
		cout << "Komenda: ";
		getline(cin, komenda);

		szukanaLiteraSamolotu = char(komenda[0]);
		int indeks = int(szukanaLiteraSamolotu) - 65;

		if (komenda[0] == ' ')
			return;

		if (int(komenda[0]) - 65 >= liczbaSamolotow || int(komenda[0]) - 65<0)
		{
			cout << "Bledna komenda" << endl;
			continue;
		}

		if (komenda.size() != 3)
		{
			cout << "Bledna komenda" << endl;
			continue;
		}
		
		if (komenda[1] == '/')
		{
			samoloty[indeks].wpisanieZmianyLotu(int(komenda[2]) - 48);
			samoloty[indeks].pokazSamolot();

		}
		else if (komenda[1] == '\\')
		{
			samoloty[indeks].wpisanieZmianyLotu(-(int(komenda[2]) - 48));
			samoloty[indeks].pokazSamolot();
		}
		else if (komenda[1] == ' ')
		{
			if (komenda[2] == 'c')
			{
				samoloty[indeks].wpisanieZmianyLotu(0);
				samoloty[indeks].pokazSamolot();
			}

			else
				cout << "Bledna komenda";
		}
		else
			cout << "Bledna komenda";

		cout << endl;
	}

}

void tura(vector<Samolot>& samoloty, int liczbaSamolotow)
{
	kontrolaLotow(samoloty, liczbaSamolotow);

}
 
//w oddzielnym watku thread tworzymy samoloty

int main()
{
	srand(time(NULL));
	vector <Samolot> samoloty;
	int liczbaSamolotow = 0;




	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);
	kontrolaLotow(samoloty, liczbaSamolotow);




}