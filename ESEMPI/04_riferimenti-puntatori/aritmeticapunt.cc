using namespace std;
#include <iostream>

int main () {
  int x;
  int * px = &x;
  long double y;
  long double * py = &y, *pypiudue;

  cout << "Size(int) = " << sizeof(int) << endl;

  cout << "Address(x) = " << (long) &x << endl; // Stampa l'indirizzo di x in base 10 di tipo long, cioè in valore numerico.
  cout << "Address(x) = " << &x << endl; // Stampa l'indirizzo di x in base 16, cioè in valore alfanumerico.

  cout << "px = " << (long) px << endl;

  cout << endl;

  px += 2; // +2 int = +(2*4) = 8  ->  Perchè un int occupa 4 bit
  cout << "px = " << (long) px << endl;
  //cout << "*px = " << *px << endl; // ERRORE: non devo usare il (*)
  px -= 3; // -3 int = -(3*4) = -12
  cout << "px = " << (long) px << endl;
  px++; // +1 int = +(1*4) = +4
  cout << "px = " << (long) px << endl;

  cout << endl;

  cout << "Size(long double) = " << sizeof(long double) << endl;
  cout << "Address(y) = " << (long) &y << endl;
  cout << "py = " << (long) py << endl;
  py += 2;
  //cout << "*py = " << *py << endl;
  cout << "py = " << (long) py << endl;
  pypiudue = py;

  cout << endl;

  py -= 3;
  cout << "py = " << (long) py << endl;
  py +=1;
  cout << "py = " << (long) py << endl;
  cout << endl;

  cout << endl;

  cout << "pypiudue = " << (long) pypiudue << endl;
  cout << "py =       " << (long) py << endl;
  cout << "pypiudue-py = " << pypiudue-py << endl; // Stampa = 2 (long)
  cout << "py-pypiudue = " << py-pypiudue << endl; // Stampa = -2 (long)
  cout << endl;
  cout << "(pypiudue<py) = " << (pypiudue<py) << endl; // Stampa = 0 = FALSE
  cout << "(pypiudue>py) = " << (pypiudue>py) << endl; // Stampa = 1 = TRUE

  return 0;
}
