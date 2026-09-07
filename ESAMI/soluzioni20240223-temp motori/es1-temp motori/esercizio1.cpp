#include <iostream>
#include <fstream>
using namespace std;

// Inserire qui sotto la soluzione all'esercizio
double Percentuale (double sup, double n) {
    double risultato = (sup / n) * 100.0;
    
    return risultato;
}

int main (int argc, char * argv[]) {
    fstream myin1,myin2;

    double temp1;
    double temp2;

    double sup = 0;
    double n = 0;
    double percent = 0.0;

    if (argc!=3) {
        cout << "Usage: ./a.out <sourcefile1> <sourcefile2>\n";
        exit(1);
    }

    myin1.open(argv[1],ios::in);
    if (myin1.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(1);
    }

    myin2.open(argv[2],ios::in);
    if (myin2.fail()) {
        myin1.close();
        cerr << "Il file " << argv[2] << " non esiste\n";
        exit(1);
    }

    /*
    myin1 >> temp1;
    myin2 >> temp2;
    while (!myin1.fail()) {
        if (temp1 > temp2) {
            sup = sup + 1.0;
        }
        n = n + 1.0;
        myin1 >> temp1;
        myin2 >> temp2;
    }
    */

    while (myin1 >> temp1 && myin2 >> temp2) {
        if (temp1 > temp2) {
            sup = sup + 1.0;
        }
        n = n + 1.0;
    }

    percent = Percentuale(sup, n);

    if (n<=0) {
        cout << "Il numero delle misurazioni è uguale a zero, per cui non posso calcolare la percentuale" << endl;
    }
    else {
        cout << "La percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 è del " << percent << "%." << endl;
    }

    myin1.close();
    myin2.close();

    return 0;
}