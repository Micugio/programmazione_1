//  Example 7.17, page 202
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>
#include <cstring>

//  Test-driver for the strcat() function:
int main()
{
  char s1[] = "ABCDEFG"; // DIM s1 = 7 
  char s2[] = "XYZ";     // DIM s2 = 3
                         // TOT 7+3+1 = 11 -> Ma s1 non è abbastanza grande quindi ERRORE!!!

  //char s1[10] = "ABCDEFG"; // Compilatore non da errore ma SBAGLIATO, manca uno spazio!!!
  //char s2[] = "XYZ"; 
  
  cout << "Before strcat(s1,s2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;

  strcat(s1,s2); // Concatena la stringa s2 ALLA stringa s1.

  cout << "After strcat(s1,s2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;
  
  return 0;
}

// NOTA: in questo esercizio c'e' un errore: trovarlo.
