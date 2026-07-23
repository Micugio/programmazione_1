using namespace std;
#include <iostream>
 


int main (int argc, char * argv[]) 
{

  for (int i = 0; i<argc; i++) {  // NOTA: se faccio partire i da 1 non stampa ./a.out
    cout << argv[i] << endl;
  }
  
  return 0;
}

