using namespace std;
#include <iostream>

int main ()
{
  bool a = true;
  bool b = false;
  int c = -2;  //non un booleano in senso stretto (-2 convertito in true)
  /*
    La regola d'oro in C++ per questa conversione:
      - 0 (zero) equivale a false.
      - Qualsiasi valore diverso da zero (quindi sia i numeri positivi che quelli negativi, come il tuo -2) equivale a true.
  */

  cout << " a = " << a << " b = " << b << " c = " << c << endl;

  a = b || c;
  cout << " a = " << a << " b = " << b << " c = " << c << endl;

  a = b && c;
  cout << " a = " << a << " b = " << b << " c = " << c << endl;

  a = !(b || c);
  cout << " a = " << a << " b = " << b << " c = " << c << endl;

  a = (!b && !c);
  cout << " a = " << a << " b = " << b << " c = " << c << endl;

  a = !b || c;
  cout << " a = " << a << " b = " << b << " c = " << c << endl;

  return 0;
}
