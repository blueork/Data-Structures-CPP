#include <iostream>
#include ".\BST\bst.h"
using namespace std;

int main() {

  BST<int> alpha;
  alpha.insert(1);
  alpha.insert(2);
  alpha.insert(3);
  alpha.levelWise();
  cout<<alpha.countLeafNodes();

  alpha.preorderTraversal();
  alpha.inorderTraversal();
  alpha.postorderTraversal();
  
  return 0;
}


