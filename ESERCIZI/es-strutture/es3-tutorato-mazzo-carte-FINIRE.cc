#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct Carta {
    int seme, valore;
};

struct Mazzo {
    int count = 0;
    Carta ** carte;
};


void aggiungiCarta (Mazzo &, int, int);
void stampaMazzo (Mazzo);


int main() {
    srand(time(NULL));

    Mazzo m;

    m.carte = new Carta*[52];  // NOTA: il tipo di (new Carta*[52]) è uguale a (Carta **)

    int n_carte = 0;

    cout << "Quante carte vuoi inserire? ";
    cin >> n_carte;
    
    for (int i=0; i<n_carte && m.count <= 52; i++) {
        int seme = (rand()%4)+1;
        int valore = (rand()%13)+1;
        aggiungiCarta(m, seme, valore);
        m.count++;
    }

    stampaMazzo(m);

    return 0;
}


void aggiungiCarta (Mazzo & m, int seme, int valore) {
    Carta * pc = new Carta;

    pc->seme = seme;
    pc->valore = valore;

    m.carte[m.count] = pc;
}

void stampaMazzo (Mazzo m) {
    Carta * pc = m.carte[0];
    for (int i=0; i<m.count; i++) {
        cout << "Seme: " << (pc+i)->seme << "   " << "Valore: " << (pc+i)->valore << endl;
    }
        
}