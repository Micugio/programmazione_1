using namespace std;
#include <iostream>

int main () {
  int v0 = 10;
  int v1 = 20;
  int v2 = 30;
  int * pv = &v1;

  cout << "(pv+1) = " << *(pv+1) << endl; // Si muove di 1*4bit (4 bit perchè è un int) in su verso gli indirizzi più alti nello stack e quindi arriva a v0.
  cout << "(*pv)+1 = " << (*pv)+1 << endl; // Queste due righe sono uguali!
  cout << "*pv+1 = " << *pv+1 << endl;     // Queste due righe sono uguali!

  return 0;
}
