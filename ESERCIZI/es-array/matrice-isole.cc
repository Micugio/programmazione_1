#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int righe = 3;
const int colonne = 5;

// NOTA: non serve passare alle funzione la dim delle righe e delle colonne perchè sono definite come variabili globali.

void inizializza (int matrice[][colonne]) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            matrice[i][j] = rand() % 2;
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

bool controllo_isole (const int matrice[][colonne], int r_target, int c_target) {
    int somma = 0;

    for (int i = r_target - 1; i <= r_target + 1; i++) {
        for (int j = c_target - 1; j <= c_target + 1; j++) {
            if ((i >= 0) && (i < righe) && (j >= 0) && (j < colonne)) {
                somma += matrice[i][j];
            }
        }
    }
    
    return somma == 1 ? true : false;
}

int num_isole(const int matrice[][colonne]) {
    int isole = 0;

    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (matrice[i][j] == 1) {
                isole += controllo_isole(matrice, i, j) ? 1: 0;
            }
        }
    }

    return isole;
}


int main() {
    //int matrice[righe][colonne];
    int matrice[righe][colonne] = {{1,0,1,0,0},{0,0,0,0,1},{0,0,0,0,0}};

    int isole = 0;
    
    srand(time(NULL));

    //inizializza (matrice);
    stampa (matrice);

    isole = num_isole(matrice);
    cout << "Il numero di isole presenti nella matrice è: "<< isole << endl;

    
    return 0;
}