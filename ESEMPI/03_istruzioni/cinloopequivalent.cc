using namespace std;
#include <iostream>

int main ()
{
  int sum = 0;
  int x;

  cin >> x;

  // É solo condizione di uscità dal ciclo!
  while (!cin.fail()) { // NOTA: lettura fallisce e quindi esce da ciclo SE inserisco un tipo di dato non valido (in questo caso un dato diverso da int) OPPURE da in input comando di END of FILE (cioè "Ctrl" + "D").
    sum = sum + x;
    cin >> x;
  }

  /*
  In questa versione devo stare attento a quando leggo da input.
  Se il ciclo fosse implementato nel seguente modo mi darebbe ERRORE perchè sommerei la x anche se non è un valore valido.
  while (!cin.fail()) {
    cin >> x;    // ERRORE, la lettura va fatta come ultima azione altrimenti rischio di sommare un valore non valido
    sum = sum + x;
  }
  */

  cout << "Somma = " << sum << endl;

  return 0;
}

/*
--- VERSIONE CON DO-WHILE (FUNZIONANTE) ---
int main ()
{
  int sum = 0;
  int x;

  do {
    cin >> x;
    sum = sum + x;
  }
  while (!cin.fail());

  cout << "Somma = " << sum << endl;

  return 0;
}
*/