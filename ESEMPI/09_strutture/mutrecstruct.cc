using namespace std;
#include <iostream>

struct S1;  // NOTA: non è necessario dichiarare prima anche S1 ma lo faccio per essere più ordinato.
struct S2;  // dichiarazione di S2

struct S1 {
  int value;
  S2 *next; // GIUSTO, S2 non è ancora definita ma è stata DICHIARATA sopra.
}; // Ok!

struct S2  { // definizione di S2
  int value;
  S1 *next;
};

int main ()
{

  S1 x = {4 , NULL};
  S2 y = {7 , NULL};

  return 0;
}
