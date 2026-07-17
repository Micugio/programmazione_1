using namespace std;
#include <iostream>

// Esempio di slide 21

int main () {
  int a, *pa, ** ppa;
  a = 2; pa = &a; ppa = &pa;

  cout << "Ind. di a = " << &a << endl;

  cout << "Ind. puntato da pa = " << pa << endl;
  cout << "Ind. di pa = " << &pa << endl;

  cout << "Ind. puntato da ppa = " << ppa << endl;
  cout << "Ind. di ppa = " << &ppa << endl;


  cout << endl;

  
  cout << "Valore di a = " << a << endl;

  cout << "Valore puntato da pa = " << *pa << endl;
  cout << "Valore pa = " << pa << endl;

  cout << "Valore puntato da ppa = " << *ppa << endl;
  cout << "Valore di ppa = " << ppa << endl;

  return 0;
}
