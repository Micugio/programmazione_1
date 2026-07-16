#include <iostream>
using namespace std;

int main() {
    char input;
    cout << "Pensa a un numero tra 0 e 7. Rispondi alle domande con 's' (si) o 'n' (no).\n\n";

    // --- DOMANDA 1 ---
    // Dividiamo l'intervallo [0, 7] a metà -> [0, 3] e [4, 7]
    cout << "Il numero e' minore di 4? (s/n): ";
    cin >> input;

    if (input == 's' || input == 'S') {
        // --- DOMANDA 2 (Ramo Sinistro: [0, 3]) ---
        cout << "Il numero e' minore di 2? (s/n): ";
        cin >> input;

        if (input == 's' || input == 'S') {
            // --- DOMANDA 3 (Sotto-ramo: [0, 1]) ---
            cout << "Il numero e' 0? (s/n): ";
            cin >> input;

            if (input == 's' || input == 'S') {
                cout << "\nIl numero pensato e': 0" << endl;
            } else {
                cout << "\nIl numero pensato e': 1" << endl;
            }
        } else {
            // --- DOMANDA 3 (Sotto-ramo: [2, 3]) ---
            cout << "Il numero e' 2? (s/n): ";
            cin >> input;

            if (input == 's' || input == 'S') {
                cout << "\nIl numero pensato e': 2" << endl;
            } else {
                cout << "\nIl numero pensato e': 3" << endl;
            }
        }
    } else {
        // --- DOMANDA 2 (Ramo Destro: [4, 7]) ---
        cout << "Il numero e' minore di 6? (s/n): ";
        cin >> input;

        if (input == 's' || input == 'S') {
            // --- DOMANDA 3 (Sotto-ramo: [4, 5]) ---
            cout << "Il numero e' 4? (s/n): ";
            cin >> input;

            if (input == 's' || input == 'S') {
                cout << "\nIl numero pensato e': 4" << endl;
            } else {
                cout << "\nIl numero pensato e': 5" << endl;
            }
        } else {
            // --- DOMANDA 3 (Sotto-ramo: [6, 7]) ---
            cout << "Il numero e' 6? (s/n): ";
            cin >> input;

            if (input == 's' || input == 'S') {
                cout << "\nIl numero pensato e': 6" << endl;
            } else {
                cout << "\nIl numero pensato e': 7" << endl;
            }
        }
    }

    return 0;
}