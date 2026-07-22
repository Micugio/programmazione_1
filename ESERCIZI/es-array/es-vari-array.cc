#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void inizializza (int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        array[i] = rand() % 10;
    }
    return;
}

void stampa (const int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

int num_uguali (const int array1[], const int array2[], int dim) {
    int uguali = 0;
    for (int i = 0; i < dim; i++) {
        if (array1[i] == array2[i]) {
            ++uguali;
        }
    }
    return uguali;
}

void media_max_min (const int array1[], double dim) {
    double media = 0;
    int max = array1[0];
    int min = array1[0];

    for (int i = 0; i < dim; i++) {
        media += array1[i];
        if (array1[i] > max) {
            max = array1[i];
        }
        if (array1[i] < min) {
            min = array1[i];
        }
    }

    cout << "Media = " << media/dim << "   Max = " << max << "   Min = " << min << endl;

    return;
}

void inverso (const int array1[], int array3[], int dim) {
    int size = dim;
    int j = 0;
    for (int i = dim-1; (i >= 0 && j < size); i--, j++) {
        array3[j] = array1[i];
    }
    stampa (array3, size);
    return;
}

int max_ric_aux (const int array1[], int max, int min, int massimo) {
    if (min > max) {
        return massimo;
    }
    else {
        if (array1[min] > massimo) {
            massimo = array1[min];
        }
        return max_ric_aux(array1, max, min+1, massimo);
    }
    return massimo;
}

int max_ric (const int array1[], int dim) {
    int massimo = array1[0];
    
    massimo = max_ric_aux(array1, dim-1, 0, massimo);

    return massimo;
}

int norma1(const int array1[], int dim) {
  int s = 0;
  for (int i = 0; i < dim; i++) {
    s += array1[i];
  }
  return s;
}

void somma_array(const int array1[], const int array2[], int array3[], int dim) {
  for (int i=0; i<dim; i++){
    array3[i] = array1[i] + array2[i];
  }
  stampa (array3, dim);
}

void concatena_array(const int array1[], const int array2[], int array3[], int dim) {
  for (int i=0; i<dim; i++) {
    array3[i] = array1[i];
  }
  for (int i=dim; i<dim*2; i++) {
    array3[i] = array2[i-dim];
  }
  stampa (array3, dim*2);
}


int main() {
    const int size = 100;
    int array1[size];
    int array2[size];
    int array3[size];
    
    int dim = 0;
    cout << "Inserisci dimensione degli array: ";
    cin >> dim;

    int uguali = 0;
    int norma = 0;

    srand(time(NULL));

    inizializza (array1, dim);
    cout << "array1 = ";
    stampa (array1, dim);

    inizializza (array2, dim);
    cout << "array2 = ";
    stampa (array2, dim);

        cout << endl;

    uguali = num_uguali(array1, array2, dim);
    cout << "I numeri uguali tra array1 e array2 sono: " << uguali << endl;

        cout << endl;

    cout << "Media, max e min dell'array1: " << endl;
    media_max_min(array1, dim);

        cout << endl;

    cout << "L'array1 invertito è il seguente: " << endl;
    inverso(array1, array3, dim);

        cout << endl;

    cout << "Il numero massimo dell'array1 (calcolato RICORSIVAMENTE) è: " << max_ric(array1, dim) << endl;

        cout << endl;
    
    norma = norma1(array1, dim);
    cout << "La norma di array1 è: " << norma << endl;

        cout << endl;
    
    cout << "L'array risultante dalla somma di array1 e array2 è: " << endl;
    somma_array(array1, array2, array3, dim);

        cout << endl;
    
    cout << "L'array risultante dalla concatenazione di array1 e array2 è: " << endl;
    concatena_array(array1, array2, array3, dim);

    return 0;
}