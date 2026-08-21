#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Lista {
    double data;
    struct Lista *next;
};

double varianza(double *data, int size) {
    double sumSQ = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sumSQ += (data[i] * data[i]);
        sum += data[i];
    }
    double mean = sum / size;
    return (sumSQ - size * (mean * mean)) / size;
}

double deviazioneStandard(double *data, int size) {
    return sqrt(varianza(data, size));
}

// Inserire qui sotto la dichiarazione della funzione calcola
int lenght(const Lista*);
double fsomma(const Lista*);
double somma_quadrati(const Lista*);
void popola_array(const Lista*, double*, int);
int calcola(const Lista*, double&, double*&, int&);
// Inserire qui sopra la dichiarazione della funzione calcola

int main (int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    struct Lista *head = nullptr;

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        return -1;
    }

    double result;
    double *data;
    int size = 0;
    
    {
        double value;
        while (inputFile >> value) {
            struct Lista *newNode = new struct Lista;
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
    }

    inputFile.close();

    calcola(head, result, data, size);

    cout << "Result: " << result << endl;
    if (size > 0) {
        cout << "Variance: " << varianza(data, size) << endl;
        delete[] data;
    } else {
        cout << "No data to calculate variance." << endl;
    }

    while (head) {
        struct Lista *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

// Inserire qui sotto la definizione della funzione calcola

int lenght(const Lista* testa) {
    if (testa == nullptr) return 0;
    return 1 + lenght(testa->next);
}

double fsomma(const Lista* testa) {
    if (testa == nullptr) return 0.0;
    return testa->data + fsomma(testa->next);
}

double somma_quadrati(const Lista* testa) {
    if (testa == nullptr) return 0.0;
    return (testa->data * testa->data) + somma_quadrati(testa->next);
}

void popola_array(const Lista* testa, double* arr, int indice) {
    if (testa == nullptr) return;
    arr[indice] = testa->data;
    popola_array(testa->next, arr, indice + 1);
}

int calcola(const Lista* testa, double& varianza_out, double*& arr_out, int& dim_out) {
    // MR: calcola deve essere procedura non una funzione!
    
    if (testa == nullptr) {
        varianza_out = -1.0;
        arr_out = nullptr;
        dim_out = 0;
        return -1;
    }

    int n = lenght(testa);
    cout << "Size: " << n << endl;
    dim_out = n;

    arr_out = new double[n];

    popola_array(testa, arr_out, 0);

    double somma = fsomma(testa);
    double somma_q = somma_quadrati(testa);

    double media = somma / n;

    varianza_out = (somma_q - (n * media * media)) / n;

    return 0;
}

// Inserire qui sopra la definizione della funzione calcola