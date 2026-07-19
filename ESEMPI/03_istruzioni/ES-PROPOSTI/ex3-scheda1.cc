#include <iostream>
using namespace std;

int main() {
  char lingua;

  cout << "Immettere la lingua (i,e,d,f): ";
  cin >> lingua;

  switch (lingua) {
    case 'i': cout << "Buon Giorno"; break;
    case 'e': cout << "Good Morning"; break;
    case 'd': cout << "Guten Morgen"; break;
    case 'f': cout << "Bonjour"; break;
    default : cout << "Errore!";
  }

  cout << endl;
  
  return 0;
}
