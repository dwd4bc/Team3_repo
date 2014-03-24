#include <iostream>
using namespace std;

int main(){

  int n = 25;
  int *ptr = &n;
  *ptr = 45;
 cout<<*ptr<<endl;
 cout<<n<<endl;
}
