using namespace std;
#include <iostream>

void stampa1 (int n, int m) { // m=0,m+1,m+2,...,m=n
  if (m>n)
    cout << endl;
  else {
    cout << m << " ";  // Se faccio il print prima della chiamata ricorsiva, stampo i numeri in ordine crescente.
    stampa1(n, m+1);
    // cout << m << " ";  // Se faccio il print dopo la chiamata ricorsiva, stampo i numeri in ordine decrescente.
  }
}

void stampa (int n) {
  stampa1 (n,0);
}

int main() {
  int n;

  cout << "n? ";
  cin >> n;
  
  cout << "stampanumeri(" << n << ") = \n";
  stampa(n);
  cout << endl;

  return 0;
}
