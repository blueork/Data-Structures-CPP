#include <iostream>
using namespace std;

// Implementation of Node for the Queue ADT
template< typename T>
class QueueNode {
public:
	T data;
	QueueNode<T>* next;
	// constructors
	QueueNode<T>() {
		this->data = 0;
		this->next = NULL;
	}
	QueueNode<T>(T data, QueueNode<T>* next = NULL) {
		this->data = data;
		this->next = next;
	}
	// desctructor
	~QueueNode<T>() {
		this->next = NULL;
	}
};

// Implementation of the Queue ADT
template< typename T >
class Queue {
public:
	QueueNode<T>* front;
	QueueNode<T>* rear;
	int num;

	// constrcutors
	Queue<T>() {
		this->front = this->rear = NULL;
		this->num = 0;
	}
	Queue<T>(T data) {
		this->front = new QueueNode<T>(data);
		this->front = this->rear;
		this->num = 1;
	}
	// destructor
	~Queue<T>() {
		this->clear();
	}
	// returns true if the queue is empty
	bool is_empty() const {
		if (this->front && this->rear)
			return false;
		else
			return true;
	}
	// deletes up any entry in the queue
	void clear() {
		if (!this->is_empty()) {
			QueueNode<T>* curr = this->rear;
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
	int size() const {
		return this->num;
	}
	// enqueue functionality
	void enqueue(T data) {
		QueueNode<T>* newNode = new QueueNode<T>(data);
		++this->num;
		if (this->front) {
			newNode->next = this->rear;
			this->rear = newNode;
		}
		else {
			this->rear = this->front = newNode;
		}
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
			QueueNode<T>* prev = this->rear;
			while (prev->next != this->front) {
				prev = prev->next;
			}
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