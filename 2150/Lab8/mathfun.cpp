
#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product (int , int);
extern "C" int power (int, int);
int  main () {
  int x, y;
  cout<<"Enter x: "<<endl;
  cin>>x;
  cout<<"Enter y: "<<endl;
  cin>>y;
  
  cout <<"The product of x and y is: "<<product(x,y)<<endl;
  cout<<"X raised to the Y power is: "<<power(x,y)<<endl;

}
