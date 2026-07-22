//  Example 7.18, page 203
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>
#include <cstring>

//  Test-driver for the strncat() function:
int main()
{
  char s1[10] = "ABCDEFG";
  char s2[4] = "XYZ";

  // NOTA: s1 deve contenere spazio sufficiente a ricevere gli n caratteri della stringa s2.

  cout << "Before strncat(s1,s2,2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;

  strncat(s1,s2,2); // Concatena 2 caratteri della stringa s2 NELLA stringa s1.

  cout << "After strncat(s1,s2,2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;

  for(int i = 0; i < 10; i++) {
    cout << i << " " << s1[i] << endl;
  }

  return 0;
}
