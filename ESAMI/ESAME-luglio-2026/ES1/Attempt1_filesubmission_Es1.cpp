#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


double calcola(double* array, int size) {
    // Implement the function to calculate variance
    //GC non viene implementata la funzione richiesta dal testo
    double sumSQ = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sumSQ += (array[i] * array[i]);
        sum += array[i];
    }
    double mean = sum / size;
    return (sumSQ - size * (mean * mean)) / size;
}


int main(int argc, char* argv[]) {
    // Implement the main function to read input, call calcola, and write output
    fstream input, output;

    char buffer[256];
    int n_data = 0;
    double result = 0.0;

    if (argc!=3) {
        cerr << "Usa: ./a.out <fileinput> <fileoutput>\n";
        //GC il ritorno del codice 0 indica una esecuzione con successo
        exit(0);
    }

    input.open(argv[1],ios::in);
    if (input.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(0);
    }

    output.open(argv[2],ios::out);
    if (output.fail()) {
        cerr << "Il file " << argv[2] << " non esiste\n";
        input.close();
        exit(0);
    }

    input >> buffer;
    int size = atoi(buffer);
    //GC manca controllo size>0

    double * data = new double[size];
    //GC manca controllo allocazione dinamica array
    
    while (input >> buffer) {
        //GC manca controllo posizione data[n_data] sia valida
        data[n_data] = atof(buffer);
        cout << data[n_data] << " ";
        n_data++;
    }

    /*
    for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
    }
    cout << endl;
    */

    //GC la condizione nella quale i dati sono maggiori di quelli richiesti permette il calcolo della varianza
    if (n_data != size) {
        cerr << "ERRORE!!!!" << endl;
    }
    else {
        result = calcola(data, size);
        //result = 5.5;
        //GC il formato dell'output non è rispettato
        output << result << " ";
        for (int i = 0; i < size; i++) {
            output << data[i] << " ";
        }
    }

    delete[] data;

    input.close();
    output.close();

    return 0;
}