#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int righe = 3;
const int colonne = 9;

void inizializzaTabella (int tabella[][colonne]) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            tabella[i][j] = rand() % 100;
        }
    }
    return;
}

void stampaTabella (const int tabella[][colonne]) {
    for (int i=0; i<righe; i++){
        for (int j=0; j<colonne; j++){
            cout << tabella[i][j];
        }
        cout << endl;
    }
    return;
}


int main() {
    int tabella[righe][colonne];
    
    srand(time(NULL));

    inizializzaTabella (tabella); 
    stampaTabella (tabella);
    

    return 0;
}