#include <iostream>
using namespace std;

/*
3) Scrivere un programma che prenda in ingresso un valore reale x e un intero n e calcoli x^n come prodotto di n volte X.
*/

int main() {
  double x;
  int n;
  double risultato = 1;

  cout << "x = ";
  cin >> x;

  cout << "n = ";
  cin >> n;

  for (int i=0; i<n; i++) {
    risultato *= x;
  }
  
  cout << "Risultato = " << risultato << endl;

  return 0;
}
