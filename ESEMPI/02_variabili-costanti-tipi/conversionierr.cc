using namespace std;
#include <iostream>

int main ()
{
  float x,y;

  cout << "Dammi un numero reale x: ";
  cin >> x;

  cout << "1/2*(x*x) + 2/3*x = " << 1/2*(x*x) + 2/3*x << endl;  

  /*
  CHE NUMERO STAMPA? 
  -> Stampa sempre ZERO. Lo fa perchè 1/2 e 2/3 sono numeri con la vigola ma vengono trattati come int perchè manca la parte decimale, 
                         quindi trattandoli come int vengono approsimati a zero, moltiplicando così qualsiasi valore di x per zero e 
                         quindi il risultato sarà sempre ZERO.
  */

  return 0;
}
