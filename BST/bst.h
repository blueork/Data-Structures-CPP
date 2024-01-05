#include <iostream>
#include "..\Queue\queue.h"
using namespace std;

// Node implementation for Queue ADT
// template< typename T>
// class QueueNode {
// public:
// 	T data;
// 	QueueNode<T>* next;
// 	QueueNode<T>(T data = 0, QueueNode<T>* next = NULL) {
// 		this->data = data;
// 		this->next = next;
// 	}
// 	~QueueNode<T>() {
// 		this->next = NULL;
// 	}
// 	void setNext(QueueNode<T>* next) {
// 		this->next = next;
// 	}
// 	void setData(T data) {
// 		this->data = data;
// 	}
// 	QueueNode<T>* getNext() const {
// 		return this->next;
// 	}
// 	T getData() const {
// 		return this->data;
// 	}
// };
// // Queue Class
// template< typename T >
// class Queue {
// public:
// 	QueueNode<T>* front;
// 	QueueNode<T>* rear;
// 	Queue<T>() {
// 		this->front = this->rear = NULL;
// 	}
// 	Queue<T>(T data) {
// 		this->front = new QueueNode<T>(data);
// 		this->front = this->rear;
// 	}
// 	~Queue<T>() {
// 		this->clear();
// 	}
// 	bool is_empty() const {
// 		if (this->front && this->rear)
// 			return false;
// 		else
// 			return true;
// 	}
// 	void clear() {
// 		if (!this->is_empty()) {
// 			QueueNode<T>* curr = this->rear;
// 			while (curr) {
// 				this->rear = curr->next;
// 				delete curr;
// 				curr = this->rear;
// 			}
// 			this->rear = this->front = NULL;
// 		}
// 	}
// 	void enqueue(T data) {
// 		QueueNode<T>* newNode = new QueueNode<T>(data);
// 		if (!this->is_empty()) {
// 			newNode->next = this->rear;
// 			this->rear = newNode;
// 		}
// 		else {
// 			this->rear = this->front = newNode;
// 		}
// 	}
// 	T dequeue() {
// 		if (!this->is_empty()) {
// 			T data;
// 			if (this->rear == this->front) {
// 				data = this->rear->data;
// 				delete this->rear;
// 				this->rear = this->front = NULL;
// 				return data;
// 			}
// 			QueueNode<T>* prev = this->rear;
// 			while (prev->next != this->front) {
// 				prev = prev->next;
// 			}
// 			data = this->front->data;
// 			delete this->front;
// 			this->front = prev;
// 			this->front->next = NULL;
// 			return data;
// 		}
// 		else {
// 			cout << "Queue is Empty. Returning 0" << endl;
// 			T temp;
// 			return temp;
// 		}
// 	}
// 	T peek() const {
// 		if (!this->is_empty())
// 			return this->front->data;
// 		else {
// 			cout << "Queue is Empty. Returning 0" << endl;
// 			T temp;
// 			return temp;
// 		}
// 	}
// };
////

// Task 01
template< typename T >
class Node {
public:
	T key;
	Node<T>* left;
	Node<T>* right;
	Node<T>(T value = 0, Node<T>* left = NULL, Node<T>* right = NULL) {
		this->key = value;
		this->left = left;
		this->right = right;
	}
	~Node<T>() {
		this->left = NULL;
		this->right = NULL;
	}
	Node operator=(const Node& copy) {
	    this->key = copy.key;
	}
};

template< typename T >
class BST {
public:
	Node<T>* root;
	BST<T>(Node<T>* root = NULL) {
		this->root = root;
	}
	~BST<T>() {
		this->root = NULL;
	}
	Node<T>* getRoot() const {
		return this->root;
	}
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
	void preOrderTraversal() {
		if (this->root == NULL)
			cout << "BST is Empty" << endl;
		else {
			preorderTraversalRecursive(this->root);
			cout << endl;
		}
	}


private:
	void postOrderTraversalRecursive(Node<T>* curr) {
		if (curr == NULL)
			return;
		else {
			postOrderTraversalRecursive(curr->left);
			postOrderTraversalRecursive(curr->right);
			cout << curr->key << " ";
		}
	}
public:
	void postOrderTraversal() {
		if (this->root == NULL)
			cout << "BST is Empty" << endl;
		else {
			postOrderTraversalRecursive(this->root);
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
