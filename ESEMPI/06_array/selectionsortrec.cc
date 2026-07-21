void swap(int & n,int & m) {
  int t;
  t=n;
  n=m;
  m=t;
  return;
}

// Selection Sort RICORSIVO
void selectionsortRic(int A[], int N, int i = 0) {
    if (i >= N - 1) return;

    int min = i;
    for (int j = i + 1; j < N; j++)
      if (A[j] < A[min]) min = j;

    swap(A[i], A[min]);

    selectionsortRic(A, N, i + 1);
}
