
#include <iostream>
#include <cstdlib>
#include "timer.h"
using namespace std;

extern "C" int threexplusone (int);
int main(){
  int x;
  int n;
  int steps;
  //  timer t;
  cout<<"Type in parameter for program : " << endl;
  cin>>x;
  cout<<"Type in parameter for timer : " <<endl;
  cin>>n;
  // t.start();
  for(int a =0; a<=n; a++){
  steps = threexplusone(x)-x;
  }
  //  t.stop();
  cout<<"Steps = "<<steps<<endl;
  // cout<<"Time taken: "<<t.getTime()<<endl;
}
