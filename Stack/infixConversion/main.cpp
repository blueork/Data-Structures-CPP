#include "./stack.h"
#include "./precedence.h"

int main() {

  char alpha = '+';
  char beta = ')';
  if( precedence( &alpha, &beta) )
    std::cout<<"Returned True";
  else
    std::cout<<"Returned False";
  return true;
}