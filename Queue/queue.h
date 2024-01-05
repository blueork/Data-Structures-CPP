#include <iostream>

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
private:
	Node<T>* front, * rear;
	int num; 
public:
	// constrcutors
	Queue<T>() : front(NULL), rear(NULL), num(0) {}
	Queue<T>(T data) : front(new Node<T>(data)), rear(front), num(1) {}
	// destructor
	~Queue<T>() { this->clear(); }
	// returns true if the queue is empty
	bool isEmpty() const { return this->front == NULL && this->rear == NULL; }
	// deletes up all of the elements in the queue
	void clear() {
		if (this->front != NULL && this->rear != NULL) {
			Node<T>* curr = this->front;
			while(curr) {
				this->front = curr->next;
				delete curr;
				curr = NULL;
				curr = this->front;
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
			this->rear->next = newNode;
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
			}
			else {
				Node<T>* curr = this->front;
				this->front = this->front->next;
				data = curr->data;
				delete curr;
				curr = NULL; 
			}
			--this->num;
			return data;
		}
		else {
			std::cout << "Queue is Empty. Returning 0" << std::endl;
			T temp = 0;
			return temp;
		}
	}
	// returns the data at the start of queue
	T peek() const {
		if (this->front)
			return this->front->data;
		else {
			std::cout << "Queue is Empty. Returning 0" << std::endl;
			T temp = 0;
			return temp;
		}
	}
	// displays from first to last
	void display() const {
		if(this->front != NULL && this->rear != NULL) {
			Node<T>* curr = this->front;
			while(curr) {
				std::cout<<curr->data<<" ";
				curr = curr->next;
			}
		}
	}
};
