#include <iostream>
using namespace std;

// QueueNode class for Queue Implementation
template< typename T>
class QueueNode {
public:
	T data;
	QueueNode<T>* next;
	QueueNode<T>(T data = 0, QueueNode<T>* next = NULL) {
		this->data = data;
		this->next = next;
	}
	~QueueNode<T>() {
		this->next = NULL;
	}
	void setNext(QueueNode<T>* next) {
		this->next = next;
	}
	void setData(T data) {
		this->data = data;
	}
	QueueNode<T>* getNext() const {
		return this->next;
	}
	T getData() const {
		return this->data;
	}
};
// Queue Class
template< typename T >
class Queue {
public:
	QueueNode<T>* front;
	QueueNode<T>* rear;
	Queue<T>() {
		this->front = this->rear = NULL;
	}
	Queue<T>(T data) {
		this->front = new QueueNode<T>(data);
		this->front = this->rear;
	}
	~Queue<T>() {
		this->clear();
	}
	bool is_empty() const {
		if (this->front && this->rear)
			return false;
		else
			return true;
	}
	void clear() {
		if (!this->is_empty()) {
			QueueNode<T>* curr = this->rear;
			while (curr) {
				this->rear = curr->next;
				delete curr;
				curr = this->rear;
			}
			this->rear = this->front = NULL;
		}
	}
	void enqueue(T data) {
		QueueNode<T>* newNode = new QueueNode<T>(data);
		if (!this->is_empty()) {
			newNode->next = this->rear;
			this->rear = newNode;
		}
		else {
			this->rear = this->front = newNode;
		}
	}
	T dequeue() {
		if (!this->is_empty()) {
			T data;
			if (this->rear == this->front) {
				data = this->rear->data;
				delete this->rear;
				this->rear = this->front = NULL;
				return data;
			}
			QueueNode<T>* prev = this->rear;
			while (prev->next != this->front) {
				prev = prev->next;
			}
			data = this->front->data;
			delete this->front;
			this->front = prev;
			this->front->next = NULL;
			return data;
		}
		else {
			cout << "Queue is Empty. Returning 0" << endl;
			T temp;
			return temp;
		}
	}
	T peek() const {
		if (!this->is_empty())
			return this->front->data;
		else {
			cout << "Queue is Empty. Returning 0" << endl;
			T temp;
			return temp;
		}
	}
};
// Node Class for Pointer Implementation of Complete Binary Tree
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(Node* left = NULL, Node* right = NULL, int data = 0) {
		this->left = left;
		this->right = right;
		this->data = data;
	}
	Node(int data) {
		this->left = this->right = NULL;
		this->data = data;
	}
	~Node() {
		this->left = NULL;
		this->right = NULL;
	}
};
// Node based impelementation of Complete Binary Tree
class BinaryTreeNode {
public:
	Node* root;
	BinaryTreeNode(Node* root = NULL) {
		this->root = root;
	}
	void insertNode(int data) {
		Node* newNode = new Node(data);
		Node* currNode = this->root;
		if (currNode == NULL) {								// if root is empty
			this->root = newNode;
			return;
		}
		else {																// if root is not empty
			Queue<Node*> binaryNodeQueue;					// building queue with 
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
	void inOrderTraversal(Node* node) {		// recursive func for inorder display
		if (node == NULL)
			return;
		else {
			this->inOrderTraversal(node->left);
			cout << node->data << " ";
			this->inOrderTraversal(node->right);
		}
	}
	void inorderTraversal() {
		this->inOrderTraversal(this->root);
	}
	void display() {
		this->inOrderTraversal(this->root);
	}
};
