#include <iostream>
#include ".\Queue\queue.h"
using namespace std;

int main() {

  Queue<int> alpha;

  alpha.enqueue(1);
  alpha.enqueue(2);
  alpha.enqueue(3);

  cout<<alpha.peek()<<endl;
  cout<<alpha.isEmpty()<<endl;
  alpha.display();
  cout<<alpha.size()<<endl;
  
  alpha.dequeue();
  cout<<alpha.peek()<<endl;
  cout<<alpha.isEmpty()<<endl;
  alpha.display();
  cout<<alpha.size()<<endl;

  alpha.dequeue();
  cout<<alpha.peek()<<endl;
  cout<<alpha.isEmpty()<<endl;
  alpha.display();
  cout<<alpha.size()<<endl;  
  
  alpha.dequeue();
  cout<<alpha.peek()<<endl;
  cout<<alpha.isEmpty()<<endl;
  alpha.display();
  cout<<alpha.size()<<endl;
  
  alpha.clear();

  alpha.dequeue();
  cout<<alpha.peek()<<endl;
  cout<<alpha.isEmpty()<<endl;
  alpha.display();
  cout<<alpha.size()<<endl;
  
  return 0;
}


