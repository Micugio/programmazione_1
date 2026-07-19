#include <iostream>
using namespace std;

void binario(int n) {
    if (n<=0) {
        cout << "0";
    }
    else if (n==1) {
        cout << "1";
    }
    else {
        //cout << n%2; //ERRORE, stampa il numero binario al contrario!
        binario(n/2);
        cout << n%2;
    }
}


int main() {
    int n;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    cout << "Numero binario: ";
    binario(n);
    cout << endl;

    return 0;
}