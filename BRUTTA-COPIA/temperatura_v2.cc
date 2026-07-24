#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// ESEGUIRE CON:   ./a.out temperatura.txt M N  ->  (con M=5 e N un numero intero positivo minore di M)

void swap (int & a, int & b) 
{
  int c = a;
  a = b;
  b = c;
}

// Algoritmo BubbleSort in ordine decrescente
void bubblesort (double v[], int n) 
{
  int i,k;
  for (k=n-1;k>0;k--)
    for (i=0;i<k;i++) 
      if (v[i] < v[i+1]) 
        swap(v[i],v[i+1]);
}

int main (int argc, char * argv[]) {
    fstream myin;

    int M, N;
    char buffer[256];
    double* array;
    double max = 0.0;
    int n_array = 0;
    int remove = 0;


    // RICORDA: argc = numero di elementi (parole) da input.
    if (argc!=4) {
        cerr << "Usa: ./a.out <fileinput> M N\n";
        exit(0);
    }

    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(0); // NOTA: Non serve chiudere lo stream myin, non è mai stato aperto perché è andato in errore
    }

    M = atoi(argv[2]);
    N = atoi(argv[3]);

    array = new double[M];

    while (myin.getline(buffer,256) && n_array < M) {
        array[n_array] = atof(buffer);
        n_array++;
    }

    for (int i=0; i<M; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << endl;

    bubblesort(array, n_array);

    cout << "Le " << N << " temperature massime sono: " << endl;

    for (int i=0; i<N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete [] array;
    myin.close();

    return 0;
}
