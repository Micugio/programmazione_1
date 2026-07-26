#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

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
void calcola(istream &, double &, double * &, int &);

void copia_ric(double *, double *, int, int);
void stop(double * &, double &, double &, int, int);
double varianza_ric(double *, int);
// Inserire qui sopra la dichiarazione della funzione calcola

int main (int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        return -1;
    }

    double result;
    double *data;
    int size = 0;
    
    calcola(inputFile, result, data, size);

    cout << "Result: " << result << endl;
    if (size > 0) {
        cout << "Variance: " << varianza(data, size) << endl;
        delete[] data;
    } else {
        cout << "No data to calculate variance." << endl;
    }
    
    inputFile.close();
    return 0;
}

// Inserire qui sotto la definizione della funzione calcola
void copia_ric(double *src, double *dst, int size, int i) {
    if (i < size) {
        dst[i] = src[i];
        copia_ric(src, dst, size, i + 1);
    }
}

void calcola(istream & inputFile, double & result, double * & data, int & size) {
    char buffer[256];
    if (inputFile >> buffer) {
        double val = atof(buffer);
        
        // Creiamo un nuovo array di dimensione (size + 1)
        double *newData = new double[size + 1];
        
        // Copiamo i dati precedenti nel nuovo array usando la ricorsione
        copia_ric(data, newData, size, 0);
        
        // Inseriamo l'ultimo valore letto
        newData[size] = val;
        
        // Liberiamo la vecchia memoria e aggiorniamo il puntatore
        if (size > 0) {
            delete[] data;
        }
        data = newData;
        
        // Chiamata ricorsiva per il prossimo elemento
        calcola(inputFile, result, data, ++size);
    }
    else {
        if (size == 0) {
            result = -1;
        } else {
            // Calcoliamo la varianza e la salviamo in result
            result = varianza_ric(data, size);
        }
    }
}

void stop(double * & data, double & sumSQ, double & sum, int size, int i) {
    if (i < size) {
        sumSQ += (data[i] * data[i]);
        sum += data[i];
        stop(data, sumSQ, sum, size, i+1);
    }
}

double varianza_ric(double *data, int size) {
    double sumSQ = 0;
    double sum = 0;
    int i = 0;
    stop(data, sumSQ, sum, size, i);
    double mean = sum / size;
    return (sumSQ - size * (mean * mean)) / size;
}
// Inserire qui sopra la definizione della funzione calcola