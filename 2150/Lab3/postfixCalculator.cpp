/* Sravan Tumuluri
   skt3rt
   postfixCalculator.cpp
   9/16/13
*/
#include <stack>
#include <string>
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator(){

}

int postfixCalculator::getTopValue()
{
  return numbers.top();
}
void postfixCalculator::pushNum(int x)
{
  numbers.push(x);
}

void postfixCalculator::add()
{
  int x = numbers.top();
  numbers.pop();
  x+= numbers.top();
  numbers.pop();
  numbers.push(x);
  
}
void postfixCalculator::subtract()
{
  int x = numbers.top();
  numbers.pop();
  x = numbers.top()-x;
  numbers.pop();
  numbers.push(x);
  
}
void postfixCalculator::multiply()
{
  int x = numbers.top();
  numbers.pop();
  x = x*numbers.top();
  numbers.pop();
  numbers.push(x);
  
}

void postfixCalculator::divide()
{
  int x = numbers.top();
  numbers.pop();
  x = numbers.top()/x;
  numbers.pop();
  numbers.push(x);
  
}
void postfixCalculator::negate()
{
  int x = numbers.top();
  numbers.pop();
  x = x*(-1);
  numbers.push(x);
}
