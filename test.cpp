#include <iostream>
#include ".\BST\bst.h"
using namespace std;

int main() {

  BST<int> alpha;
  alpha.insert(1);
  alpha.insert(2);
  alpha.insert(3);
  alpha.levelWise();
  cout<<alpha.countLeafNodes()<<endl;

  alpha.preorderTraversal();
  alpha.inorderTraversal();
  alpha.postorderTraversal();

  alpha.clear();
  alpha.levelWise();
  cout<<alpha.countLeafNodes()<<endl;

  alpha.preorderTraversal();
  alpha.inorderTraversal();
  alpha.postorderTraversal();
  alpha.clear();
  
  return 0;
}


