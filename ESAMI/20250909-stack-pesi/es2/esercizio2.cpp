#include <iostream>
#include "stack.h"

using namespace std;

// Dichiarazione della funzione calcola
void trasferisci(Stack *, Stack *);
double calcola_aux (Stack *, double, int);
double calcola (Stack *);
// Dichiarazione della funzione calcola

int main() {
    Stack *s = init();
    double value = 0.0;
    
    // Esempio di utilizzo della pila
    push(s, 10.0);
    push(s, 15.0);
    push(s, 20.0);

    printStack(s); // Stampa la pila prima del calcolo
    value = calcola(s); // Calcola l'energia usando la pila
    printStack(s); // Stampa la pila dopo il calcolo
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);
    cout << "------------fine-------MAIN------" << endl;

    s = init();
    // Esempio di utilizzo della pila
    push(s, 10.0);
    printStack(s); // Stampa la pila prima del calcolo
    value = calcola(s); // Calcola l'energia usando la pila
    printStack(s); // Stampa la pila dopo il calcolo
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);
    cout << "------------fine-------MAIN------" << endl;
    s = init();
    // Esempio di utilizzo della pila
    printStack(s); // Stampa la pila prima del calcolo
    value = calcola(s); // Calcola l'energia usando la pila
    printStack(s); // Stampa la pila dopo il calcolo
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);

    return 0;
}


// Definizione della funzione calcola
void trasferisci(Stack *s, Stack *t) {
    double temp = 0.0;

    if (isEmpty(s)) {
        return;
    }
    else {
    temp = pop(s);
    push(t, temp);
    
    trasferisci(s, t);
    }
    
}

double calcola_aux (Stack *s, Stack* t, double res, int n) {
    double peso = 0.0;

    if (isEmpty(t)) {
        return res;
    }
    else {
        peso = pop(t);
        cout << "NUMERO = " << n << endl;
        cout << "PESO = " << peso << endl;
        res += peso*9.81*n*1.5;
        push(s,peso);
        printStack(t);
        printStack(s);
        cout << endl;
        cout << "RISULTATO = " << res << endl;
        cout << "/////////////////////////////////////////////////" << endl;
        return calcola_aux(s, t, res, ++n);
    }
}

double calcola (Stack* s) {
    double res = 0.0;
    double risultato = 0.0;
    double temp = 0.0;
    Stack * t = init();
    trasferisci(s, t);
    /* CICLO WHILE VIETATO
    while (!isEmpty(s)){
        temp = pop(s);
        push(t,temp);
    }
    */
    risultato = calcola_aux(s, t, res, 0);
    cout << "----------------------------------------------------------------------------------" << endl;
    //cout << "Stack s = " << endl;
    //printStack(s);
    //cout << "Stack t = " << endl;
    //printStack(t);
    freeStack(t);
    cout << "-------------------------------inizio----------MAIN-----------------------------------------" << endl;
    return risultato;
}
