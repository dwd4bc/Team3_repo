#include<iostream>
using namespace std;

int collatz (int x){
  if(x==1)
    return 0;
  if(x%2==0){
   return 1+collatz(x/2);
   
  }
  else{
   return 1+collatz(3*x+1);
      
  }
  
}
int main(){
  int x;
  cin>>x;
  cout <<collatz(x)<<endl;
}
