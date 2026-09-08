// Allowed include 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Add your code hereafter

struct Paziente {
    double peso;
    int eta;
    int glicemia[12][31];    // int matrice [righe][colonne];
};


int Monitora (Paziente, int, int, int, int&, double&, double&);


int main(int argc, char * argv []) {
    fstream input;

    if (argc!=5) {
        cerr << "Il numero di parametri è diverso da 4. Errore!\n";
        exit(1);
    }

    input.open(argv[1],ios::in);

    if (input.fail()) {
        cerr << "Il file non esiste. Errore!\n";
        exit(1);
    }

    int n = atoi(argv[2]);
    int ipo = atoi(argv[3]);
    int iper = atoi(argv[4]);

    if ((n<1 || n>12) || (ipo>iper) || (ipo<80 || ipo>95) || (iper<105 || iper>120)) {
        cerr << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!\n";
        exit(1);
    }

    Paziente p; 

    double peso;
    int eta;
    int glicemia;
    int supIper = 0;

    int supIpo = 0;
    double media = 0;
    double varianza = 0;
    
    input >> peso;
    input >> eta;

    p.peso = peso;
    p.eta = eta;

    /*
    cout << "Peso: " << p.peso << endl;
    cout << "Età: " << p.eta << endl;
    */

    for (int i=0; i<12; i++) {
        for (int j=0; j<31; j++) {
            input >> glicemia;
            p.glicemia[i][j] = glicemia;
        }
    }

    /*
    for (int i=0; i<12; i++){
        for (int j=0; j<31; j++){
            cout << p.glicemia[i][j] << " ";
        }
        cout << endl;
    }
    */

    supIper = Monitora (p, n, ipo, iper, supIpo, media, varianza);
    cout << "Il numero di giorni di iperglicemia è: " << supIper << endl;

    cout << "Il numero di giorni di ipoglicemia è: " << supIpo << endl;
    cout << "La media è: " << media << endl;
    cout << "La varianza è: " << varianza << endl;
    

    input.close();

    return 0;
}


int Monitora (Paziente p, int n, int ipo, int iper, int& supIpo, double& media, double& varianza) {
    int supIper = 0;
    double totMedia = 0.0;
    double sommatoria = 0.0;
    double varianza1 = 0.0;

    for (int j=0; j<31; j++) {
        if (p.glicemia[n-1][j] > iper) {
            supIper++;
        }
    }

    for (int j=0; j<31; j++) {
        if (p.glicemia[n-1][j] < ipo) {
            supIpo++;
        }
    }

    for (int j=0; j<31; j++) {
        totMedia += p.glicemia[n-1][j];
    }
    media = totMedia / 31.0;


    for (int j=0; j<31; j++) {
        sommatoria += p.glicemia[n-1][j] * p.glicemia[n-1][j];
    }
    varianza1 = sommatoria - (31.0 * (media * media));
    varianza = varianza1 / 31.0; 

    return supIper;
}
