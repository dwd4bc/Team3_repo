//Sravan Tumuluri
//skt3rt
//prelab4.cpp
//9/23/13

using namespace std;
#include <iostream>
#include <string>
#include <limits.h>
void sizeOfTest(){
  cout <<"The size of an int is: " << sizeof(int)<< endl;
  cout <<"The size of an unsigned int is: " << sizeof(unsigned int)<< endl;
  cout <<"The size of a float is: " << sizeof(float)<< endl;
  cout <<"The size of a double is: " << sizeof(double)<< endl;
  cout <<"The size of a char is: " << sizeof(char)<< endl;
  cout <<"The size of a boolean is: " << sizeof(bool)<< endl;
  cout <<"The size of an int* is: " << sizeof(int*)<< endl;
  cout <<"The size of a char* is: " << sizeof(char*)<< endl;
  cout <<"The size of a double* is: " << sizeof(double*)<< endl; 
  
}
void outputBinary (unsigned int x)
{
  string binary;
  unsigned int i = x;
  int y = 0;
  int d = 0;
  for(int z = 31; z >= 0; z--)
    {
      y = (1<<z);
      d = x/y;
      if(d > 0)
	{
	  binary+= '1';
	}
      else
	binary += '0';
      x = x % y;
      if((z%4)==0)
	binary +=' ';
    }
  cout << "The binary form of " << i << " is: " << binary <<endl;
}
void overflow (){

  unsigned int maxvalue = UINT_MAX;
  cout << "This is what happens when you add 1 to the max value of an unsigned int: " << endl;
  cout << "maxvalue + 1 = " << (maxvalue + 1) << endl;
  cout << "This happens because the size limit of an int is 32 bits and adding 1 to the max value pushes the value over the 32 bit threshold resulting in a reset of all the bits in order to accommodate the new value." <<endl;


}
int main ()
{
  unsigned int x;  
 
  sizeOfTest();
  cout << "Input the value of x: " <<endl;
  cin >> x;
  outputBinary(x);
  overflow();


}
