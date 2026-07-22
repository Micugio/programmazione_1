#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int righe = 3;
const int colonne = 3;

void inizializza (int matrice[][colonne]) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            matrice[i][j] = rand() % 10;
        }
    }
    return;
}

void stampa (const int matrice[][colonne]) {
    for (int i=0; i<righe; i++){
        for (int j=0; j<colonne; j++){
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void trasposta (const int matrice1[][colonne], int matrice2[][colonne]) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            matrice2[i][j] = matrice1[j][i];
        }
    }
    stampa (matrice2);
}


int main() {
    int matrice1[righe][colonne];
    int matrice2[righe][colonne];
    
    srand(time(NULL));

    inizializza (matrice1);
    stampa (matrice1);

    cout << endl;

    cout << "La matrice trasposta è la seguente: " << endl;
    trasposta (matrice1, matrice2);
    
    return 0;
}