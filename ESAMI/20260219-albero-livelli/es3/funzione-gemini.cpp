#include <stdlib.h>
#include "treequeue.h" // Presuppone l'inclusione della libreria fornita

void calcola(Node* root, int* max_somma, int* livello_max) {
    // Gestione albero vuoto
    if (root == NULL) {
        *max_somma = 0;
        *livello_max = -1;
        return;
    }

    Queue* q = createQueue();
    enqueue(q, root);
    
    *max_somma = -2147483648; // Inizializzato al valore minimo possibile per un intero a 32-bit
    *livello_max = -1;
    
    int livello_corrente = 0;

    while (!isEmpty(q)) {
        int dimensione_livello = size(q);
        int somma_livello = 0;

        // Calcola la somma dei nodi per il livello attuale
        for (int i = 0; i < dimensione_livello; i++) {
            Node* current = dequeue(q);
            somma_livello += current->value; // Si assume che il campo del valore si chiami 'value'

            // Accoda i figli per il livello successivo
            if (current->left != NULL) enqueue(q, current->left);
            if (current->right != NULL) enqueue(q, current->right);
        }

        // Condizione di aggiornamento: se la somma è maggiore o se è uguale 
        // ma ci troviamo ad un livello più vicino alla radice
        if (somma_livello > *max_somma || (somma_livello == *max_somma && livello_corrente < *livello_max)) {
            *max_somma = somma_livello;
            *livello_max = livello_corrente;
        }

        livello_corrente++;
    }

    // Libera la memoria allocata per la coda
    free(q); 
}
