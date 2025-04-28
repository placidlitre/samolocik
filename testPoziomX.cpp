#include<iostream>
#include<cassert> 
using namespace std; 
int zmianaX(int x, bool kierunekPoziomy, bool widocznosc)
{

	if (!(x > 56) && kierunekPoziomy) x++;
	else if (x > -2 && !kierunekPoziomy) x--;
	if (x == 57 || x == -2) {
		widocznosc = false;
	}
    return x; 

}
int main(){
assert(zmianaX(3,true,true) == 4);
assert(zmianaX(3,false, true) == 2); 
assert(zmianaX(-5, false,true) == -5); 


    cout<< "Wszystkie testy zostały wykonane pomyślnie"<<endl;
    return 0; 
}