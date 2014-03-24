
#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int maxofthree (int , int, int);

// Purpose: This main program produces a vector of random
//          numbers between 0 and 99, then calls the
//          externally defined function 'vecsum' to add
//          up the elements of the vector.
// Author:  Adam Ferrari
int  main () {
  cout<<maxofthree(9,10,4)<<endl;
}
