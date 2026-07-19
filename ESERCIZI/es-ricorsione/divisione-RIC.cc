#include <iostream>
using namespace std;

// Funzione ricorsiva che imita l'operatore "/" tra 2 numeri interi qualsiasi.
int div(int n1, int n2, int res) {
    if (n1<=0) {
        return res;
    }
    else if (n1<n2) {
        return res;
    }
    else {
        res = res + 1;
        return div(n1-n2, n2, res);
    }
    return res;
}


int main() {
    int n1 = 0;
    int n2 = 0;

    cout << "Inserire due numeri interi positivi: ";
    cin >> n1 >> n2;

    cout << "Risultato = "<< div(n1, n2, 0) << endl;

    return 0;
}