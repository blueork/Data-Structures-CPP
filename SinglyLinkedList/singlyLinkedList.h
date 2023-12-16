#include <iostream>
using namespace std;

// Implementation of Node for the Singly Linked List ADT
template< typename T >
class Node {
public:
	T data;
	Node<T>* next;

  // defualt constructor
	Node<T>() {
		this->data = 0;
		this->next = NULL;
	}
  // parameterized constructor
	Node<T>(T data, Node<T>* next = NULL) {
		this->data = data;
		this->next = next;
	}
  // destrcutor
	~Node<T>() {
		this->next = NULL;
	}
  // getters
	T getData() const {
		return this->data;
	}
	Node<T>* getNextPointer() {
		return this->next;
	}
  // setters
	void setData(T data) {
		this->data = data;
	}
	void setNextPointer(Node<T>* next) {
		this->next = next;
	}
};

// Implementation of the Singly Linked List ADT
template< typename T > 
class SLinkedList {
private:
  Node<T>* head;
  int count;

public:
	// defualt constructor
  SLinkedList<T>() {
		this->head = NULL;
    this->count = 0;
  }
  // parameterized constructor
	SLinkedList<T>(T data) {
		this->head = new Node<T>(data);
    this->count = 1;
	}
  // destructor
  ~SLinkedList<T>() {
    this->clear();
  }
  // deletes the linked list
  void clear() {
    if(this->head) {
      Node<T>* current = this->head;
      Node<T>* temp = NULL;
      while(current) {
        temp = current;
        current = current->next;
        delete temp;
        temp = NULL;
      }
    }
    this->head = NULL;
    this->count = 0;
  }
  // returns true if the list is empty
  bool isEmpty() const {
		if (this->head)
			return false;
		else
			return true;
	}
  // returns the number of elements in the list
  int getCount() const {
    return this->count;
  }
  // inserts data at the end of the linked list
	void insert(T data) {
		Node<T>* newNode = new Node<T>(data);
    ++this->count;
		if (this->head) {
			Node<T>* current = this->head;
      while (current->next)
				current = current->next;
			current->next = newNode;
		}
		else 
			this->head = newNode;
	}
  // insertes data at the start of the linked list
	void insertAtHead(T data) {
		++this->count;
    Node<T>* newNode = new Node<T>(data);
		if (this->head) {
      newNode->next = this->head;
			this->head = newNode;
		}
		else 
			head = newNode;
	}
  // returns the index of the given data in the linked list
	// returns -1 if the list is empty or the given data is 
  // not present in the list
  // indexing start from zero
  int search(T data) {
		if (this->head) {
		Node<T>* current = head;
		int currentIndex = 0;
    	while (current && current->data != data) {
				current = current->next;
				++currentIndex;
			}
			if (current)
				return currentIndex;
			else
				return -1;
		}
		else
			return -1;
	}
  // inserts data at a particular index
  // indexing starts from zero
	void insertAtIndex(T data, int index) {
		if(index < 0) {
      cout<<"Incorrect index given. Insertion failed\n";
      return;
    }
    if (index == 0)
			this->insertAtHead(data);
		else {
			if (this->head) {
	  		Node<T>* current = this->head;
			  Node<T>* previous = NULL;
			  int currIndex = 0;
        while (current && currIndex < index) {
					++currIndex;
					previous = current;
					current = current->next;
				}
				if (current) {
					Node<T>* newNode = new Node<T>(data);
					newNode->next = current;
					previous->next = newNode;
          ++this->count;
        }
				else
					cout << "Given index doesn't exist in the Linked List\n";
			}
			else
				cout << "Given index doesn't exist in the Linked List\n";
		}
	}
  // updates the data of a element having given index in the list
  // indexing starts from zero
	void update(int index, T data) {
		if (this->head) {
			Node<T>* current = head;
      int currentIndex = 0;
			while (current && currentIndex < index) {
				++currentIndex;
				current = current->next;
			}
			if (current)
				current->data = data;
			else
				cout << "Given index doesn't exist in the Linked List\n";
		}
		else
			cout << "The Linked List in empty\n";
	}
  // prints the linked list
	void print() {
		if (this->head) {
      Node<T>* current = this->head;
			while (current) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
		else
			cout << "The Linked List is Empty\n";
	}
  // removes the given data from the linked list
	void remove(T data) {
		if (this->head) {
		  Node<T>* current = this->head;
			Node<T>* previous = NULL;
			while (current && current->data != data) {
				previous = current;
				current = current->next;
			}
			if (current) {
        --this->count;
				if (previous) 
					previous->next = current->next;
				else 
					this->head = current->next;
        delete current;
        current = NULL;
			}
			else
				cout << "The given data is not present in the given Linked List\n";
		}
		else
			cout << "Linked List is empty. Nothing to remove\n";
	}
};
