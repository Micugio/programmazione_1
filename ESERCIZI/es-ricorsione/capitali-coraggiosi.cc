#include <iostream>
using namespace std;


double capitale_maturato(double a, int n, double percent, double spese) {
    if (n==0) {
        return a;
    }
    else {
        return capitale_maturato((((1+percent)*a)-spese), n-1, percent, spese);
    }
}

int main() {
    double a = 25000.00;
    int k = 0;
    double percent = 0.0015;
    double spese = 1.0;

    double risultato = 0.0;
    
    cout << "Inserire numero di mesi (almeno 6 mesi): ";
    cin >> k;
    
    if (k<6) {
        cerr << "ERRORE!!!" << endl;
    }
    else {
        risultato = capitale_maturato(a, k, percent, spese);
        cout << "Capitale maturato = " << risultato << endl;
    }
    
    return 0;
}
