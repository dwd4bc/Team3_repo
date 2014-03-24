#include <iostream>
#include<string>
using namespace std;

int findMax(int x [] )  // y is a reference variable
{
  int max = x[0];
  //int s = x.size();
  for(int a = 0; a<=sizeof(x);a++){
    if(x[a]>max)
      max = x[a];
  }
  return max;
}

int main() {
  int x []  = {1,4,3,8,10};
  cout<<findMax(x)<<endl;
 
}
