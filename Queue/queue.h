#include <iostream>
using namespace std;

// Implementation of the Queue ADT
template< typename T >
class Queue {
private:
	template<typename U>
	class Node {
	public:
		U data;
		Node<U>* next;
		// constructors
		Node<U>() : data(data), next(NULL) {}
		Node<U>(T data, Node<U>* next = NULL) : data(data), next(next){}
		// desctructor
		~Node<U>() { this->next = NULL; }
	};
public:
	Node<T>* front;
	Node<T>* rear;
	int num;

	// constrcutors
	Queue<T>() : front(NULL), rear(NULL), num(0) {}
	Queue<T>(T data) : front(new Node<T>(data)), rear(front), num(1) {}
	// destructor
	~Queue<T>() { this->clear(); }
	// returns true if the queue is empty
	bool isEmpty() const { return this->front == NULL && this->rear == NULL; }
	// deletes up any entry in the queue
	void clear() {
		if (!this->isEmpty()) {
			Node<T>* curr = this->rear;
			while (curr) {
				this->rear = curr->next;
				delete curr;
				curr = this->rear;
			}
			this->rear = this->front = NULL;
			this->num = 0;
		}
	}
	// returns the number of elements in the queue
	int size() const { return this->num; }
	// enqueue functionality
	void enqueue(T data) {
		Node<T>* newNode = new Node<T>(data);
		++this->num;
		if (this->front) {
			newNode->next = this->rear;
			this->rear = newNode;
		}
		else 
			this->rear = this->front = newNode;
	}
	// dequeue functionality
	T dequeue() {
		if (this->front) {
			T data;
			if (this->rear == this->front) {
				data = this->rear->data;
				delete this->rear;
				this->rear = this->front = NULL;
				this->num = 0;
				return data;
			}
			Node<T>* prev = this->rear;
			while (prev->next != this->front) 
				prev = prev->next;
			data = this->front->data;
			delete this->front;
			this->front = prev;
			this->front->next = NULL;
			--this->num;
			return data;
		}
		else {
			cout << "Queue is Empty. Returning 0" << endl;
			T temp = 0;
			return temp;
		}
	}
	// returns the data at the start of queue
	T peek() const {
		if (this->front)
			return this->front->data;
		else {
			cout << "Queue is Empty. Returning 0" << endl;
			T temp = 0;
			return temp;
		}
	}
};
