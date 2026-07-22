//  Example 7.16, page 201
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>
#include <cstring>



//  Test-driver for the strncpy() function:
int main()
{
  //char s1[100] = {}; // Crea una stringa vuota
  char s1[] = "ABCDEFG";
  char s2[] = "XYZ";

  cout << "Before strncpy(s1,s2,2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;

  strncpy(s1,s2,2); // Copia 2 caratteri della stringa s2 NELLA stringa s1.
  //strncpy(s1,s2,4);  //MR: che succede in questo caso?: -> Copia anche il terminatore di stringa e quindi poi strlen(s1)=3 perchè si ferma 
                                                          // a contare appena incontra in terminatore ma in realtà la stringa s1 è più lunga.
  
  cout << "After strncpy(s1,s2,2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;

  for(int i = 0; i < 8; i++) {
    cout << i << " " << s1[i] << endl;
  }

  return 0;
}
