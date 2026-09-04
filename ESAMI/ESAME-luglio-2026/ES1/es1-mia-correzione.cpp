#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


double calcola(double* array, int size) {
    // Implement the function to calculate variance

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    double mean = sum / size;

    double varianceSum = 0.0;
    for (int i = 0; i < size; ++i) {
        varianceSum += (array[i] - mean) * (array[i] - mean);
    }
    
    return varianceSum / size;
}


int main(int argc, char* argv[]) {
    // Implement the main function to read input, call calcola, and write output

    fstream input, output;

    char buffer[256];
    int n_data = 0;
    double result = 0.0;

    if (argc!=3) {
        cerr << "Usa: ./a.out <fileinput> <fileoutput>\n";
        exit(1);
    }

    input.open(argv[1],ios::in);
    if (input.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(1);
    }

    output.open(argv[2],ios::out);
    if (output.fail()) {
        cerr << "Il file " << argv[2] << " non esiste\n";
        input.close();
        exit(1);
    }

    input >> buffer;
    int size = atoi(buffer);

    if (input.fail() || input.eof() || size <= 0) {
        input.close();
        output.close();
        cerr << "Size ERRATA da file di input." <<endl;
        exit(1);
    }

    double * data = new (nothrow) double[size];

    if (data==NULL) {
        input.close();
        output.close();
        cerr << "Errore allocazione memoria array." << endl;
        exit(1);
    }
    
    for (int i = 0; i < size; i++) {
        input >> data[i];
        if (input.fail() || input.eof()) {
            delete[] data;
            input.close();
            output.close();
            cerr << "Errore lettura elementi dell'array da file di input." << endl;
            exit(1);
        }
    }

    result = calcola(data, size);
    output << "La varianza dei valori: ";
    for (int i = 0; i < size; i++) {
        output << data[i];
        if (i < size-1) {
            output << ", ";
        }
    }
    output << " è: " << result;


    delete[] data;

    input.close();
    output.close();

    return 0;
}