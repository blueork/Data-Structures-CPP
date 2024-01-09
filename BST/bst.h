#include <iostream>
#include "..\Queue\queue.h"
using namespace std;

// template< typename T >
// class Node {
// public:
// 	T key;
// 	Node<T>* left, * right;
// 	Node<T>(T value = 0, Node<T>* left = NULL, Node<T>* right = NULL) : key(value), 
// 	left(left), right(right) {}
// 	~Node<T>() {
// 		this->left = NULL;
// 		this->right = NULL;
// 	}
// 	Node operator=(const Node& copy) {
// 	    this->key = copy.key;
// 	}
// };

template< typename T >
class BST {
private:
	template< typename U >
	class Node {
	public:
		U key;
		Node<U>* left, * right;
		Node<U>(U value = 0, Node<U>* left = NULL, Node<U>* right = NULL) : key(value), 
		left(left), right(right) {}
		~Node<U>() {
			this->left = NULL;
			this->right = NULL;
		}
		Node operator=(const Node& copy) {
	    	this->key = copy.key;
		}
	};
public:
	Node<T>* root;
	BST<T>(Node<T>* root = NULL) : root(root) {}
	~BST<T>() { this->root = NULL; }
	Node<T>* getRoot() const { return this->root; }

private:
	void insert(Node<T>*& curr, T insertItem) {
		if (curr == NULL) {
			Node<T>* newNode = new Node<T>(insertItem);
			curr = newNode;
		}
		else {
			if (insertItem < curr->key)
				insert(curr->left, insertItem);
			else
				insert(curr->right, insertItem);
		}
	}
public:
	void insert(T insertItem) {
		if (this->root == NULL) {
			Node<T>* newNode = new Node<T>(insertItem);
			this->root = newNode;
		}
		else {
			if (insertItem < this->root->key)
				insert(this->root->left, insertItem);
			else
				insert(this->root->right, insertItem);
		}
	}

private:
	bool search(Node<T>* curr, T searchItem) {
		if (curr == NULL)
			return false;
		else if (curr->key == searchItem)
			return true;
		else if (searchItem < curr->key)
			return search(curr->left, searchItem);
		else
			return search(curr->right, searchItem);
	}
public:
	bool search(T searchItem) {
		if (this->root == NULL)
			return false;
		if (this->root->key == searchItem)
			return true;
		else {
			if (searchItem < this->root->key)
				return search(this->root->left, searchItem);
			else
				return search(this->root->right, searchItem);
		}
		return false;
	}

private:
	void inorderTraversalRecursive(Node<T>* curr) {
		if (curr == NULL)
			return;
		else {
			inorderTraversalRecursive(curr->left);
			cout << curr->key << " ";
			inorderTraversalRecursive(curr->right);
		}
	}
public:
	void inorderTraversal() {
		if (this->root == NULL)
			cout << "BST is Empty" << endl;
		else {
			inorderTraversalRecursive(this->root);
			cout << endl;
		}
	}

private:
	void preorderTraversalRecursive(Node<T>* curr) {
		if (curr == NULL)
			return;
		else {
			cout << curr->key << " ";
			preorderTraversalRecursive(curr->left);
			preorderTraversalRecursive(curr->right);
		}
	}
public:
	void preorderTraversal() {
		if (this->root == NULL)
			cout << "BST is Empty" << endl;
		else {
			preorderTraversalRecursive(this->root);
			cout << endl;
		}
	}

private:
	void postorderTraversalRecursive(Node<T>* curr) {
		if (curr == NULL)
			return;
		else {
			postorderTraversalRecursive(curr->left);
			postorderTraversalRecursive(curr->right);
			cout << curr->key << " ";
		}
	}
public:
	void postorderTraversal() {
		if (this->root == NULL)
			cout << "BST is Empty" << endl;
		else {
			postorderTraversalRecursive(this->root);
			cout << endl;
		}
	}

private:
// 	void deleteNode(Node<T>*& curr) {
// 		if (curr->left == NULL) {
// 			Node<T>* temp = curr;
// 			curr = curr->right;
// 			delete temp;
// 			temp = NULL;
// 		}
// 		else if (curr->right == NULL) {
// 			Node<T>* temp = curr;
// 			curr = curr->left;
// 			delete temp;
// 			temp = NULL;
// 		}
// 		else {
// 			Node<T>* temp1 = curr->right;
// 			Node<T>* temp2 = curr->right;
// 			while (temp1->left) {
// 				temp1 = temp1->left;
// 			}
// 			temp1->left = curr->left;
// 			delete curr;
// 			curr = temp2;
// 		}
// 	}
  void deleteNode(Node<T>*& curr) {
		if (curr->left == NULL) {
		Node<T>* temp = curr;
			curr = curr->right;
			delete temp;
			temp = NULL;
		}
		else if (curr->right == NULL) {
			Node<T>* temp = curr;
			curr = curr->left;
			delete temp;
			temp = NULL;
		}
		else {
		    Node<T>* inOrderSuccessor = curr->right;
		    while(inOrderSuccessor->left) 
		        inOrderSuccessor = inOrderSuccessor->left;
		    *curr = *inOrderSuccessor;
		    this->remove(curr->right, curr->key);
		}
  }
	void remove(Node<T>*& curr, T key) {
		if (curr == NULL)
			return;
		else if (curr->key == key)
			deleteNode(curr);
		else if (key < curr->key)
			remove(curr->left, key);
		else
			remove(curr->right, key);
	}
public:
	void remove(T key) {
		if (this->root == NULL)
			return;
		else
			remove(this->root, key);
	}

private:
	void levelOrder(Node<T>* curr) {
		Queue<Node<T>*> traversalQueue;
		traversalQueue.enqueue(curr);
		Node<T>* temp = NULL;
		while (!traversalQueue.isEmpty() ) {
			temp = traversalQueue.dequeue();
			cout << temp->key << " ";
			if (temp->left)
				traversalQueue.enqueue(temp->left);
			if (temp->right)
				traversalQueue.enqueue(temp->right);
		}
		cout << endl;
	}
public:
	void levelWise() {
		if (this->root == NULL)
			cout << "BST is Empty" << endl;
		else
			levelOrder(this->root);
	}

private:
  int countLeafNodes(Node<T>* current) {
    if(current == NULL)
      return 0;
    else if(current->left == NULL && current->right == NULL)
      return 1;
    else 
      return this->countLeafNodes(current->left) + this->countLeafNodes(current->right);
  }
public:
  int countLeafNodes() {
    if(this->root)
      return this->countLeafNodes(this->root);
    else 
    	return -1;
  }
};
