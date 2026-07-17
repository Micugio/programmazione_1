// ESEMPIO DI PUNTATORE A COSTANTE

using namespace std;
#include <iostream>

int main() {
  const int c1 = 3;
  int c2 = 5;
  const int *pc1 = &c1;  // OK PUNTATORE A COSTANTE -> Se voglio puntare una costante devo usare un puntatore a costante.
  const int *pc2 = &c2;  // OK, posso usare un puntatore a costante per puntare una semplice variabile (basta che siano dello stesso tipo).

  pc2 = pc1; // OK
  pc1 = &c2; // OK
  c2 = 2;    // OK
  //*pc1 = 2; // ERRORE: non e'possibile modificare c2 tramite pc1.
      
  return 0;
}
