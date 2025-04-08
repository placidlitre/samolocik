#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;


char MapaSamolotow[60][10];

class Samolot
{

	int x;
	int poziomY;
	int zmianaLotu;
	char litera;
public:
	Samolot() : litera('X') {}
	Samolot(const char& literka, const int& poziomekY) : litera(literka), poziomY(poziomekY) {}

	void zmianaY()
	{
		if (zmianaLotu < 0)
		{
			poziomY++;
			zmianaLotu++;
		}
		else if (zmianaLotu > 0)
		{
			poziomY--;
			zmianaLotu--;
		}
	}

	void poziomDoGory(int zmianaLotku)
	{
		poziomY++;
	}

	void poziomDoDolu(int zmianaLotku)
	{
		poziomY--;
	}

	void wpisanieZmianyLotu(int zmianaLotku)
	{
		zmianaLotu = zmianaLotku;
	}

	void pokazSamolot()
	{
		cout << litera << endl;
		cout << zmianaLotu << endl << endl;
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

void tworzenieSamolotu(vector<Samolot>& samoloty, int& licznikSamolotow)
{
	int liniaY = rand() % 10;
	samoloty.emplace_back((char(66 + licznikSamolotow)), liniaY); //tworzy obiekt + odrazu działa konstruktor który wpisuje mu daną litere w liście inicjalizacyjnej
	samoloty[licznikSamolotow].pokazSamolot();
	licznikSamolotow++;
}

void kontrolaLotow(vector<Samolot>& samoloty)
{
	string komenda;
	char szukanaLiteraSamolotu;

	literaSamolotu = komenda[0];
	auto it = find_if(samoloty.begin(), samoloty.end(), [szukanaLiteraSamolotu](Samolot& samolot)
		{
			return samolot.get
		}

}

int main()
{
	srand(time(NULL));
	vector <Samolot> samoloty;
	int liczbaSamolotow = 0;


	kontrolaLotow();


	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);



}