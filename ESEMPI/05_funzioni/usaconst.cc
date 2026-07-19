using namespace std;
#include <iostream>

void prova (int x, int & y, const int & z)
{
  cout << "  x = " << x
       << " y = " << y
       << " z = " << z << endl;
  x = 10;
  y = 20;
  // z = 30;  // ERRORE, non posso modificare valore di una costante!
  cout << "  x = " << x
       << " y = " << y
       << " z = " << z << endl;
}

int main()
{
  int a=20,b=40,c=60;
  cout << " a = " << a
       << " b = " << b
       << " c = " << c << endl;
  prova (a,b,c*3);  // Se al posto di b passo (b*3) è sbagliato!!!
  cout << " a = " << a
       << " b = " << b
       << " c = " << c << endl;
return 0;
}
