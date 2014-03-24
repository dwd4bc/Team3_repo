//Sravan Tumuluri
//skt3rt
//postfixCalculator.h
//9/16/13
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <stack>
using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  int getTopValue();
  void pushNum(int x);
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  

 private:
  stack<int> numbers;

};

#endif


