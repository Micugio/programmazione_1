using namespace std;
#include <iostream>

// Realizzare ricorsivamente la somma di due numeri avendo a disposizione incremento e decremento ++x e --x.
// VERSIONE RICORSIVA con return di res.

// VERSIONE PROF ()
int somma (int n, int m) {
  int res;
  if (m==0)  // CASO BASE -> NOTA: basta controllare m se è uguale a zero perchè è quello il numero che decremento ad ogni giro.
    res = n;
  else {
    ++n; --m;
    res = somma(n,m);
  }
  return res;
}

// LA MIA VERSIONE (codice più lungo MA meno calcoli computazionali)
int somma1 (int n, int m) {
  int res;
  if (m==0) 
    res = n;
  else if (n==0)
    res = m;
  else {
    ++n; --m;
    res = somma(n,m);
  }
  return res;
}

int main() {
  int n,m;

  cout << "n? m? (>=0):" ;
  cin >> n >> m ;

  cout << "somma(" << n << "," << m << ") = " << somma(n,m) << endl;

  return 0;
}
