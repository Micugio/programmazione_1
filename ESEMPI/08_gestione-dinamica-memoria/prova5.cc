using namespace std;
#include <iostream>
 
int main () 
{
  int * a;
  int n;
  cout << "quanti? " ;
  cin >> n;
  
  a = new int[n] = {1,2,3}; // ERRORE, non posso inizializzare manualmente array dinamico!!!
                            //    NOTA: non piu' ammesso, una volta nei vecchi compilatori era ammesso.
  //  a = new int[n];     
  
  for (int i=0; i<n; i++) {
    cout << endl << i+1 << ": ";
    cout << a[i];
  }

  delete [] a;

  cout << endl << a[1] << endl;

  return 0;
}

