#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const unsigned int WYS_PLANSZA = 10;
const unsigned int SZER_PLANSZA = 60;

class Samolot
{
public:
	int x;
	int poziomY;
	int zmianaLotu;
	char litera;
	bool widocznosc;
	bool kierunekPoziomy; // prawo to true, lewo to false 



	Samolot() : litera('X'), poziomY(0), zmianaLotu(0), x(0), widocznosc(true), kierunekPoziomy(true) {}
	Samolot(const char& literka, const int& poziomekY, const int& zmianaLotku, const int& xek, const bool widocznosciek, const bool kieruneczekPoziomeczek) : litera(literka), poziomY(poziomekY), zmianaLotu(zmianaLotku), x(xek), widocznosc(widocznosciek), kierunekPoziomy(kieruneczekPoziomeczek) {}

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

	void zmianaX()
	{

		if (!(x > 56) && kierunekPoziomy) x++;
		else if (x > -2 && !kierunekPoziomy) x--;
		if (x == 57 || x == -2) {
			widocznosc = false;
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
		cout << poziomY << endl;
		cout << x << endl;
		cout << endl;
	}

};


void tworzenieSamolotu(vector<Samolot>& samoloty, int& licznikSamolotow)
{
	int liniaY = rand() % 10;
	int kierunek = rand() % 2;
	if (kierunek == 0)
		samoloty.emplace_back((char(65 + licznikSamolotow)), liniaY, 0, -2, true, true); // samoloty w prawo    tworzy obiekt + odrazu działa konstruktor który wpisuje mu daną litere w liście inicjalizacyjnej
	else if (kierunek == 1)
		samoloty.emplace_back((char(65 + licznikSamolotow)), liniaY, 0, 57, true, false); // samoloty w lewo

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

		if (int(komenda[0]) - 65 >= liczbaSamolotow || int(komenda[0]) - 65 < 0 || komenda.size() != 3)
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



void tworzenieSamolotuNaMapie(vector<Samolot>& samoloty, int liczbaSamolotow, int indeks)
{
	if (samoloty[indeks].zmianaLotu == 0)
	{
		if (samoloty[indeks].kierunekPoziomy)
			cout << "=";
		cout << "(" << samoloty[indeks].litera << "0)";
		if (!samoloty[indeks].kierunekPoziomy)
			cout << "=";
	}
	else
	{
		if (!samoloty[indeks].kierunekPoziomy && samoloty[indeks].zmianaLotu > 0)
			cout << "\\";
		else if (!samoloty[indeks].kierunekPoziomy && samoloty[indeks].zmianaLotu < 0)
			cout << "/";

		cout << "(" << samoloty[indeks].litera << abs(samoloty[indeks].zmianaLotu) << ")";

		if (samoloty[indeks].kierunekPoziomy && samoloty[indeks].zmianaLotu > 0)
			cout << "/";
		else if (samoloty[indeks].kierunekPoziomy && samoloty[indeks].zmianaLotu < 0)
			cout << "\\";
	}
}

void warunek(vector<Samolot>& samoloty)
{
	for (int i = 0; i < samoloty.size(); i++) {
		for (int j = i + 1; j < samoloty.size(); j++) {
			if (abs(samoloty[i].x - samoloty[j].x) <= 2 && abs(samoloty[i].poziomY - samoloty[j].poziomY) <= 2)exit(0);
		}
	}
}

void tworzenieMapy(vector<Samolot>& samoloty, int liczbaSamolotow)
{
	for (Samolot samolot : samoloty) {
		cout << samolot.litera << ", poziom Y: " << samolot.poziomY << " , poziom X: " << samolot.x << endl;
	}
	vector <vector<Samolot>> tablicaSamolotowWLinii;
	tablicaSamolotowWLinii.resize(WYS_PLANSZA); // deklaruje ze vector bedzie mial 10 wierszy, potrzebne
	for (int y = 0; y < WYS_PLANSZA; y++) {

		for (Samolot samolot : samoloty) {
			if (samolot.poziomY == y && samolot.x <57 && samolot.x>-2) {
				tablicaSamolotowWLinii[y].push_back(samolot); // wpisuje do vectora[y] samoloty ktore sa na tej linii 
			}
		}
		sort(tablicaSamolotowWLinii[y].begin(), tablicaSamolotowWLinii[y].end(), [](Samolot sam1, Samolot sam2) {
			return (sam1.x) < (sam2.x);
			}); // sortuje rosnaco na podstawie  koordynatow x 

		/*for (Samolot samolot : tablicaSamolotowWLinii[y]) {
			cout << samolot.x << " ";
		} //wypisz vector
		cout << endl;*/
		if (!tablicaSamolotowWLinii[y].empty() && tablicaSamolotowWLinii[y][0].x == -1) {
			cout << tablicaSamolotowWLinii[y][0].litera;
			tablicaSamolotowWLinii[y].erase(tablicaSamolotowWLinii[y].begin());
		}
		else cout << " ";
		cout << "|";
		if (!tablicaSamolotowWLinii[y].empty() && tablicaSamolotowWLinii[y].front().x == -2) {
			tablicaSamolotowWLinii[y].erase(tablicaSamolotowWLinii[y].begin());
		}
		if (tablicaSamolotowWLinii[y].size() == 0) {
			for (int x = 0; x < SZER_PLANSZA; x++) cout << " ";
			cout << "|" << endl;
		}
		else {
			int xPoprzedniegoSamolotu =0;
			int ileWypisanoPol = 0;
			int licznikSamolotowWPlanszy = 0;
			for (int i = 0; i < tablicaSamolotowWLinii[y].size(); i++) {
				if (tablicaSamolotowWLinii[y][i].widocznosc && tablicaSamolotowWLinii[y][i].x < 56) {
				
					for (int x = 0; x < abs(tablicaSamolotowWLinii[y][i].x) - xPoprzedniegoSamolotu ; x++)
						cout << " ";
					tworzenieSamolotuNaMapie(samoloty, liczbaSamolotow, tablicaSamolotowWLinii[y][i].litera - 'A');
					ileWypisanoPol = abs(tablicaSamolotowWLinii[y][i].x) + 5 * (tablicaSamolotowWLinii[y].size()-licznikSamolotowWPlanszy); //koordynat ostatniego + długość samolotów razy ich ilość
					if(tablicaSamolotowWLinii[y][i].x>-1)xPoprzedniegoSamolotu = (tablicaSamolotowWLinii[y][i].x) + 5;
					licznikSamolotowWPlanszy++;
				}
				/*else if(tablicaSamolotowWLinii[y][i].widocznosc && tablicaSamolotowWLinii[y][i].x == 56 && tablicaSamolotowWLinii[y].size() >1) {
					for (int j = 0; j < tablicaSamolotowWLinii[y][i].x - tablicaSamolotowWLinii[y][i - 1].x - tablicaSamolotowWLinii[y].size() +1; j++) cout << " ";
				}*/

			}
			if (SZER_PLANSZA - ileWypisanoPol < 0) {
				int ileNalezyWypisac = SZER_PLANSZA- tablicaSamolotowWLinii[y].back().x +5; 
				for (int i = 0; i < ileNalezyWypisac ; i++) cout << " ";
			}
			else {

			for (int i = 0; i < SZER_PLANSZA - ileWypisanoPol; i++) cout << " ";
			}
			if (tablicaSamolotowWLinii[y].back().x == 56 && tablicaSamolotowWLinii[y].size()>1) {
				for (int j = 0; j < 5; j++)
					cout << " ";
			}
			cout << "|";
			if (tablicaSamolotowWLinii[y].back().x == 56) cout << tablicaSamolotowWLinii[y].back().litera;
			cout << endl;
		}
	}






}

void tura(vector<Samolot>& samoloty, int liczbaSamolotow)
{
	for (int i = 0; i < samoloty.size(); i++)
	{
		samoloty[i].zmianaX();
		samoloty[i].zmianaY();
	}
	kontrolaLotow(samoloty, liczbaSamolotow);
	system("CLS");
	tworzenieMapy(samoloty, liczbaSamolotow);
}




//w oddzielnym watku thread tworzymy sprawdzamy krakse 

int main()
{
	srand(time(NULL));
	vector <Samolot> samoloty;
	int liczbaSamolotow = 0;
	int licznik = 0;
	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);
	tworzenieSamolotu(samoloty, liczbaSamolotow);

	//banda lewa to x=-2 i true ||| banda prawa to x =57 i false 
	samoloty[0].x = -2;
	samoloty[0].kierunekPoziomy = true;
	samoloty[1].x = 55;
	samoloty[1].kierunekPoziomy = true;
	samoloty[0].poziomY = 2;
	samoloty[1].poziomY = 3;
	samoloty[2].poziomY = 3; 
	samoloty[2].kierunekPoziomy = true;
	samoloty[2].x = 48;
	samoloty[3].x = 35; 
	samoloty[3].kierunekPoziomy = true;
	samoloty[3].poziomY = 3;

	//dodać warunek, że samoloty nie mogą się zrespawnować w tym samym miejscu i czasie na bandzie (w sumie to będzie wynikać z warunku na krakse) 


	while (true)
	{

		tura(samoloty, liczbaSamolotow);

	}


}
