#include<iostream>
#include <stdexcept>

bool precedence( char* alpha, char* beta) {
  if( *alpha == '(' || *beta == '(' )
    return false;
  else if( *beta == ')' )
    return true;
  else if( *alpha == ')' )
    throw std::invalid_argument("Operator 1 cannot be )");
  return false;
}