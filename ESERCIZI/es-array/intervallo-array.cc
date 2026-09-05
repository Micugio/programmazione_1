#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inizializza(double array[], int dim) {
  for (int i = 0; i < dim; i++) {
    array[i] = (rand() % 100)/10.0;
  }
  return;
}

void stampa(const double array[], int dim) {
  for (int i = 0; i < dim; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return;
}

int intervallo(double a[], int n, double x, double y) {
  int i = 0;
  int count = 0;
  if (x<y) {
    while (i<n) {
      if ((a[i] < x) || (a[i] > y)) {
        a[i] = 0.0;
        ++count;
      }
      ++i;
    }
    return count;
  }
  else {
    return -1;
  }
  
}

int main() {
  int n = 5;
  double a[n];
  double x = 0.0;
  double y = 5.0;
  
  srand(time(NULL));

  inizializza(a, n);
  stampa(a, n);

  cout << "Intervallo: " << intervallo(a, n, x, y) << endl;
  stampa(a, n);

  return 0;
}
