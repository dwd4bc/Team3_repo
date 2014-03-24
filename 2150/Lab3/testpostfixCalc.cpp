/* Sravan Tumuluri
   skt3rt
   testpostfixCalc.cpp
   9/16/13
*/
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <cstdlib>
#include "postfixCalculator.h"
#include <locale>         
#include <sstream> 
using namespace std;

int main ()
{
  postfixCalculator p;
  cout <<"Input String: " << endl;
  //String x;
  
  while(cin.good()) {
	string s;
       	cin >> s;
	//	std::getline(std::cin,s);
	if(s == "-")
	  p.subtract();

	
	if(s == "+")
	  p.add();
	if(s == "*")
	  p.multiply();
	    if(s == "/")
	      p.divide();
	  if(s == "~")
	    p.negate();
	  if(s == "")
	    break;
	  int i = atoi(s.c_str());
	  if((i!=0))
	    p.pushNum(i);
	  if(s=="0")
	    p.pushNum(0);
	  }
	  
	    
	  
  int z = p.getTopValue();
  cout << "Answer is: " << z << endl;

  /* p.pushNum(8);
   p.pushNum(2);
   p.add();
   //  double z = p.divide();
   int z = p.getTopValue();
   p.pushNum(2);
   p.negate();
   p.divide();
  cout << "Answer is: " << z << endl;
  z = p.getTopValue();
  cout << "Answer after division and negation is: " << z << endl;
  p.pushNum(4);
  p.multiply();
  z = p.getTopValue();
  cout << "Answer after multiplication is: " << z << endl;
  p.pushNum(-20);
  p.subtract();
  z = p.getTopValue();
  cout << "Answer after subtraction is: " << z << endl;*/

}
