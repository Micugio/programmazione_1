using namespace std;
#include <iostream>

int main ()
{
  char x;
  float y;
  //double h;
  int z;

  cout << "dammi in sequenza: un carattere, un reale e un intero" << endl;
  cin >> x;
  cin >> y;
  cin >> z;
  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
  return 0;
}

//NB: cosa succede se digito "input> A3.5 3" ?
//    e con "input> Ab3.5 3" ?
//    e con "input> 3.5 4 3" ?