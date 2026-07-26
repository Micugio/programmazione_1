#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct Prodotto {
    char nome[50];
    float prezzo[7];
};


void print (Prodotto);
float prezzo_medio (Prodotto);
void sconto (Prodotto, int);
bool * compare (Prodotto, Prodotto, bool []);


int main() {
    srand(time(NULL));
    
    Prodotto c1;
    Prodotto c2;

    float media1 = 0.0;
    float media2 = 0.0;
    int n_sconto = 50;
    int day = 1;

    bool array[7];
    bool * a;

    cout << "Inserisci nome prodotto 1: ";
    cin >> c1.nome;
    cout << endl;

    cout << "Inserisci nome prodotto 2: ";
    cin >> c2.nome;
    cout << endl;

    for (int i = 0; i<7; i++) {
        c1.prezzo[i] = rand()%100;
    }

    for (int i = 0; i<7; i++) {
        c2.prezzo[i] = rand()%100;
    }
    
    print(c1);
    print(c2);

    media1 = prezzo_medio(c1);
    media2 = prezzo_medio(c2);

    cout << "Prezzo medio prodotto 1: " << media1 << endl;
    cout << "Prezzo medio prodotto 2: " << media2 << endl;

    sconto(c1, n_sconto);
    sconto(c2, n_sconto);

    print(c1);
    print(c2);

    a = compare(c1, c2, array);

    for (int i=0; i<7; i++) {
        cout << "Giorno " << day << ": " << a[i] << endl;
        day++;
    }

    return 0;
}


void print (Prodotto p) {
    cout << "Nome: ";
    cout << p.nome << endl;
    int day = 1;
    for (int i=0; i<7; i++) {
        cout << "Prezzo[" << day << "]: " << p.prezzo[i] << endl;
        day++;
    }
    cout << endl;
}

float prezzo_medio (Prodotto p) {
    float res = 0.0;
    float somma = 0.0;
    for (int i=0; i<7; i++) {
        somma += p.prezzo[i];
    }
    res = somma/7.0;
    return res;
}

void sconto (Prodotto p, int sconto) {
    for (int i=0; i<7; i++) {
        p.prezzo[i] = p.prezzo[i]*(sconto/100);
    }
}

bool * compare (Prodotto p1, Prodotto p2, bool array[]) {
    for (int i=0; i<7; i++) {
        if (p1.prezzo[i] < p2.prezzo[i]) {
            array[i] = true;
        }
        else {
            array[i] = false;
        }
    }
    return array;
}