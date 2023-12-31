#include <iostream>
using namespace std;

// Implementation of BST using arrays
class BinaryTree {
private:
	int* treeArray;
	int capacity;
	int root;
	int current_index;

public:
  BinaryTree(int size) {
		treeArray = new int[size] {-1};
		for (int i = 0; i < size; ++i)
			this->treeArray[i] = -1;
		this->capacity = size;
		this->root = 1;
		this->current_index = 1;
	}
	~BinaryTree() {
		if (this->treeArray)
			delete[] this->treeArray;
		this->treeArray = NULL;
	}
	void insert( int value) {
		if (this->current_index < this->capacity)
			this->treeArray[this->current_index++] = value;
		else
			cout << "Tree is full\n";
	}
	bool search(int value) {
	    if(this->treeArray[this->root] == -1)
	        return false;
	    for(int i = this->root; i < current_index; ++i)
	        if(this->treeArray[i] == value)
	            return true;
	    return false;
	}
private:
	void inorderTraversal(int index) {
		if (index >= this->capacity)
			return;
		if (this->treeArray[index] == -1)
			return;
		this->inorderTraversal(2 * index);
		cout << this->treeArray[index] << " ";
		this->inorderTraversal(2 * index + 1);
  	}
  	void preOrderTraversal() {
      		if(this->treeArray[this->root] == -1)
        		return;
      		for(int i = this->root; i < this->current_index; ++i)
        		cout<<this->treeArray[i]<<" ";
      		cout<<endl;
  	}
public:
	void displayInorder() {
		this->inorderTraversal(this->root);
		cout<<endl;
	}
	void displayPreOrder() {
	    	this->preOrderTraversal();
	}
};
