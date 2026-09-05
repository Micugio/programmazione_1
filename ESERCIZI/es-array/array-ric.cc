#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
void inizializza_ric(int array[], int dim, int i) {
  if (i<dim) {
    array[i] = rand() % 10;
    inizializza_ric(array, dim, ++i);
  }
  return;
}
*/

void inizializza(int array[], int dim) {
  for (int i = 0; i < dim; i++) {
    array[i] = rand() % 10;
  }
  return;
}

void stampa(const int array[], int dim) {
  for (int i = 0; i < dim; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return;
}

int max_ric(int array[], int dim, int max, int i) {
  if (i<dim) {
    if (array[i] > max) {
      max = array[i];
      return max_ric(array, dim, max, ++i);
    }
    else {
      return max_ric(array, dim, max, ++i);
    }
  }
  return max;
}

int main() {
  int dim = 5;
  int array[dim];
  
  
  int massimo = 0;

  srand(time(NULL));
  
  //inizializza_ric(array, dim, 0);
  inizializza(array, dim);
  stampa(array, dim);

  int max = array[0];

  massimo = max_ric(array, dim, max, 1);
  cout << massimo << endl;

  return 0;
}
