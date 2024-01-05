#include "./stack.h"

int main() {
  std::cout<<"Hello World"<<std::endl;

  Stack<int> alpha(1);
  alpha.PUSH(2);
  alpha.PUSH(3);

  alpha.print();
  std::cout<<alpha.EMPTY();
  alpha.MAKENULL();
  std::cout<<alpha.EMPTY();
  
  return 0;
}