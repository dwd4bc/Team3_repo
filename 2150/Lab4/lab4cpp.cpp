//Sravan Tumuluri
//skt3rt
//inlab4.cpp
//9/25/13
#include <iostream>
#include <limits>
using namespace std;
int main()
{
  int a1 = 1;
  int a0 = 0;
  int maxint = 0x7fffffff;
  unsigned int b1 =1;
  unsigned int b0 = 0;
  float c1 = 1.0;
  float c0 = 0.0;
  float maxfloat = std::numeric_limits<float>::max();
  double d1 = 1.0;
  double d0 = 0.0;
  double maxdouble =std::numeric_limits<double>::max();
  char e1 = '1';
  char e0 = '0';
  char maxchar = 0xff;
  bool f1 = true;
  bool f0 = false;
  int* g;
  //*g = a1;
  char* h;
  *h = NULL;

  double* i;
  i = NULL;

  cout << "Int a1 is: " << a1<<endl;
  cout << "Double d1 is: " <<d1<<endl;
  cout << "Char e1 is: " <<e1 <<endl;
  cout << "Int* g is: " << *g <<endl;

  //   ARRAY SECTION OF LAB BEGINS HERE
  int IntArray[10];
char CharArray[10];
//int IntArray2D[6][5];
//char CharArray2D[6][5];

 for(int x =0;x<10;x++)
   IntArray[x]=x;
 for (int x = 0; x<10;x++)
   CharArray[x]=x;
 int IntArray2D[6][5]=
   {
     {1,2,3,4,5},
     {6,7,8,9,10},
     {11,12,13,14,15},
     {16,17,18,19,20},
     {21,22,23,24,25},
     {26,27,28,29,30}
   };
  char CharArray2D[6][5] =
     {
       {'a','b','c','d','e'},
       {'f','g','h','i','j'},
       {'k','l','m','n','o'},
       {'p','q','r','s','t'},
       {'u','v','w','x','y'},
       {'z', 'A','B','C','D'}
     };
 cout <<"End of program." <<endl;
}
