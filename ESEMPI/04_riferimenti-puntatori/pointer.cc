using namespace std;
#include <iostream>

int main() {
  int x=1;  // x variabile tipo int
  int *px;   // px variabile puntatore

  px=&x;   // accede alla variabile puntatore

  *px=x+1;  // accede alla cella di memoria puntata dalla variabile puntatore
  x=x+1;

  // Quanto vale x?  ->  x = 1 (+1) (+1) = 3
  cout << "x = " << x << endl;
  cout << *px << endl;

  return 0;
}
