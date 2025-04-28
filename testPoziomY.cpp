#include <iostream>
#include<cassert>
using namespace std;
int zmianaY(int zmianaLotu, int poziomY)
{
	if (zmianaLotu < 0)
	{
		poziomY++;
		zmianaLotu++;
		return poziomY;
	}
	else if (zmianaLotu > 0)
	{
		poziomY--;
		zmianaLotu--;
		return poziomY;
	}
}
int main() {

	assert(zmianaY(1, 0) == -1);
	assert(zmianaY(-1, 0) == 1);
	cout<<"Wszystkie testy wykonane pomyślnie"<<endl;

	return 0;
}