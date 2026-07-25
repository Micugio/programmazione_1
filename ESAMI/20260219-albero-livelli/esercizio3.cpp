#include <iostream>
#include "treequeue.h"

using namespace std;

// Inserire qui sotto la dichiarazione della funzione calcola
void calcola (Node*, int&, int&);
// Inserire qui sopra la dichiarazione della funzione calcola


int main() {
    // Creazione di un albero binario di esempio
    Node* root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(0));
    cout << "Stampa dell'albero:" << endl;
    int sommarichiesta, livello;
    printTreeDepth(root);
    cout << "DIOOOO" << endl;
    cout << sizeOfTree(root) << endl;
    cout << "DIOOOO" << endl;
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = nullptr;
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(-6));
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(-8));
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    return 0;
}

// Inserire qui sotto la definizione della funzione calcola
void calcola (Node* root, int & massimo, int & livello) {
    if (sizeOfTree(root)==0) {
        massimo = 0;
        livello = -1;
    }
    else {
        massimo = 0;
        livello = 0;
        int max_corrente = 0;
        int livello_corrente = 0;
        Queue* q = createQueue(sizeOfTree(root));
        enqueue(q, root);
        while (isEmpty(q)) {
            int max_temp = 0;
            
            
            Node* t = dequeue(q);
            massimo += getValue(t);
        }
        

        printQueue(q);

        deleteQueue(q);
    }
}
// Inserire qui sopra la definizione della funzione calcola
