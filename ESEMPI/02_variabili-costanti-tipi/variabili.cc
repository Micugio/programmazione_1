using namespace std;
#include <iostream>

// VARIABILI GLOBALI prendono valore 0 o vuoto se non definite
int n0;
float pi0;
float duepi0;
char c0;

int main ()
{
  // VARIABILI NORMALI (cioè definite dentro il main) prendono valore casuale
  int n;
  float pi;
  float duepi;
  char c;

  cout << "n = " << n << endl;
  cout << "pi = " << pi << endl;
  cout << "duepi = " << duepi << endl;
  cout << "c = " << c << endl;

  cout << endl;

  cout << "n0 = " << n0 << endl;
  cout << "pi0 = " << pi0 << endl;
  cout << "duepi0 = " << duepi0 << endl;
  cout << "c0 = " << c0 << endl;

  return 0;
}
