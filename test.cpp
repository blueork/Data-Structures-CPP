#include <iostream>
#include ".\Queue\queue.h"
using namespace std;

int main() {

  Queue<int> alpha;

  alpha.enqueue(1);
  alpha.enqueue(2);
  alpha.enqueue(3);

  cout<<alpha.peek();
  cout<<alpha.isEmpty();
  
  return 0;
}


