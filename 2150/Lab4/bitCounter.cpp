//Sravan Tumuluri
//skt3rt
//bitCounter.cpp
//9/26/13
#include<iostream>
#include <stdlib.h> 
using namespace std;

int binarybitCounter(int x){
  if((x%2==0)&(x!=1)&(x!=0))
    return binarybitCounter(x/2);
  if((x%2!=0)&(x!=1)&(x!=0))
    return (binarybitCounter(x/2)+1);
  if(x==1)
    return 1;
  if(x==0)
    return 0;


}

int main (int argc, char **argv)
{
  if(argc<2){
    cout<<"Need to include 1 commandline argument" << endl;
    exit(0);
  }


  int x = atoi(argv[1]);
  cout << binarybitCounter(x) << endl;



}
