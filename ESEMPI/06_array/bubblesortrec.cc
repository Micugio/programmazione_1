using namespace std;
#include <iostream>
#include <iomanip>

const int MAXDIM = 100;

void swap (int & a, int & b) 
{
  int c = a;
  a = b;
  b = c;
}

void printarray(int v[],int n) 
{
  int i;
  for (i=0;i<n;i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

// Bubble Sort RICORSIVO:
void passataRic(int v[], int i, int k) {
    if (i >= k) return;
    if (v[i] > v[i+1]) swap(v[i], v[i+1]);
    passataRic(v, i + 1, k);
}

void bubblesortRic(int v[], int n, int k) {
    if (k <= 0) return;              // caso base: array ordinato
    passataRic(v, 0, k);
    bubblesortRic(v, n, k - 1);
}

// Funzione originale
void bubblesort(int v[], int n) {
    bubblesortRic(v, n, n - 1);
}


int main () 
{
  int myarray[MAXDIM] = {41,3,9,1,5,17,6,20,37,2,8,23,10,0,11,19};
  int dim = 16;
  bubblesort(myarray,dim);
  printarray(myarray,dim);
}
