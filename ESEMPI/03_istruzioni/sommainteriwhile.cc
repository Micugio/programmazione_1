using namespace std;
#include <iostream>

int main ()
{
  int n,i,somma;
  cout << "Quanti interi vuoi sommare?: ";
  cin >> n;

  i = 1;
  somma = 0;

  while (i<=n) {
    cout << "i = "  << i << endl;

    somma += i;
    cout << "Somma = "  << somma << endl;
    i++;

    cout << "i = "  << i << endl;
    cout << endl;
  }

  cout << "Somma = "  << somma << "   i = "  << i << endl;

  return 0;
}
