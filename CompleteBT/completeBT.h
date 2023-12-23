#include <iostream>
#include "../Queue/queue.h"
using namespace std;

// Node Class for Pointer Implementation of Complete Binary Tree
class CBTNode {
public:
	int data;
	CBTNode* left;
	CBTNode* right;
	CBTNode(CBTNode* left = NULL, CBTNode* right = NULL, int data = 0) {
		this->left = left;
		this->right = right;
		this->data = data;
	}
	CBTNode(int data) {
		this->left = this->right = NULL;
		this->data = data;
	}
	~CBTNode() {
		this->left = NULL;
		this->right = NULL;
	}
};
// Node based impelementation of Complete Binary Tree
class CBT {
private:
  CBTNode* root;
public:
	CBT(CBTNode* root = NULL) {
		this->root = root;
	}
	~CBT() {
    if(this->root)
      this->clear();
  }
  void clear() {
    if(this->root) {
      CBTNode* current = this->root;
      Queue<CBTNode*> binaryNodeQueue;					// building queue with 
			binaryNodeQueue.enqueue(current);		// nodes of the binary tree
      while(!binaryNodeQueue.is_empty()) {
        current = binaryNodeQueue.dequeue();
        if(current) {
          if(current->left)
            binaryNodeQueue.enqueue(current->left);
          if(current->right)
            binaryNodeQueue.enqueue(current->right);
          delete current;
          current = NULL;  
        }
      }
    }
    this->root = NULL;
  }
  void insertNode(int data) {
		CBTNode* newNode = new CBTNode(data);
		CBTNode* currNode = this->root;
		if (currNode == NULL) {								// if root is empty
			this->root = newNode;
			return;
		}
		else {																// if root is not empty
			Queue<CBTNode*> binaryNodeQueue;					// building queue with 
			binaryNodeQueue.enqueue(currNode);		// nodes of the binary tree;
			while (!binaryNodeQueue.is_empty()) {		// until no node is left 
				currNode = binaryNodeQueue.dequeue();
				if (currNode->left == NULL) {				// if left child is empty
					currNode->left = newNode;
					return;
				}
				else if (currNode->right == NULL) {	// if right child is empty
					currNode->right = newNode;
					return;
				}
				else {															// if neither child is empty
					binaryNodeQueue.enqueue(currNode->left);	// enqueue the left child
					binaryNodeQueue.enqueue(currNode->right);	// enqueue the right child
				}
			}
		}
	}
	void inOrderTraversal(CBTNode* node) {		// recursive func for inorder display
		if (node == NULL)
			return;
		else {
			this->inOrderTraversal(node->left);
			cout << node->data << " ";
			this->inOrderTraversal(node->right);
		}
	}
	void inorderTraversal() {
		if(this->root)
      this->inOrderTraversal(this->root);
    else
      cout<<"This Tree is Empty\n";
  }
	void display() {
    if(this->root)
		  this->inOrderTraversal(this->root);
    else
    cout<<"The Tree is Empty\n";
  }
};
