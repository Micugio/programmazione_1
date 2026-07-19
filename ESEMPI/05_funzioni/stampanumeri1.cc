using namespace std;
#include <iostream>

void stampa1 (int n) { //
  if (n>=0) {
    // VERSIONE tail-recursive:
    //cout  << n << " ";
    //stampa1(n+1);

    // VERSIONE NO tail-recursive:
    //cout  << n << " ";  // Se faccio il print prima della chiamata ricorsiva, stampo i numeri in ordine decrescente E IN QUESTO CASO la funzione NON è più tail-recursive.
    stampa1(n-1);
    cout  << n << " ";  // Se faccio il print dopo la chiamata ricorsiva, stampo i numeri in ordine crescente.
  }
}

//Nota: necessita` del wrapper per l'"\endl"
void stampa (int n) {
  stampa1 (n);
  cout << endl;
}


int main() {
  int n;

  cout << "n? ";
  cin >> n;

  cout << "stampanumeri(" << n << ") = \n";
  stampa(n);

  return 0;
}
