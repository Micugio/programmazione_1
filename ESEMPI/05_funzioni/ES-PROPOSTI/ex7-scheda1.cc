#include <iostream>
using namespace std;

void inizializza() {
  unsigned int seme = time(NULL);
  srand(seme);
}

int dado() {
  //inizializza();  // ERRORE, la generazione del seme va fatta una sola volta (ad esempio nel main) e non per ogni dado altrimenti i risultati dei dadi sono tutti uguali.

  int val_dado;
  val_dado = (rand()%6)+1;

  return val_dado;
}

int attacco() {
  int d1, d2, d3;
  int tot_attacco;

  d1 = dado();
  d2 = dado();
  d3 = dado();

  tot_attacco = d1 + d2 + d3;

  return tot_attacco;
}

int difesa() {
  int d1, d2, d3;
  int tot_difesa;

  d1 = dado();
  d2 = dado();
  d3 = dado();

  tot_difesa = d1 + d2 + d3;

  return tot_difesa;
}

int main() {
  inizializza();
  
  int dadi_attacco = attacco() ;
  int dadi_difesa = difesa();

  cout << "attacco = " << dadi_attacco << endl;
  cout << "difesa = " << dadi_difesa << endl;

  if (dadi_attacco > dadi_difesa) {
    cout << "L'attacco ha vinto!" << endl;
  }
  else {
    cout << "La difesa ha vinto!" << endl;
  }

  return 0;
}
