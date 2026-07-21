void swap(int & n,int & m) {
  int t;
  t=n;
  n=m;
  m=t;
  return;
}


// Insertion Sort RICORSIVO
void primoCicloRic(int A[], int i) {
  if (i <= 0) return;
  if (A[i] < A[i-1]) swap(A[i], A[i-1]);
  primoCicloRic(A, i - 1);
}

void shiftRic(int A[], int j, int v) {
  if (j <= 0 || !(v < A[j-1])) {
    A[j] = v;
    return;
  }
  A[j] = A[j-1];
  shiftRic(A, j - 1, v);
}

void secondoCicloRic(int A[], int N, int i) {
  if (i > N - 1) return;
  int v = A[i];
  shiftRic(A, i, v);
  secondoCicloRic(A, N, i + 1);
}

// Funzione principale
void insertionsortRic(int A[], int N) {
  primoCicloRic(A, N - 1);
  secondoCicloRic(A, N, 2);
}