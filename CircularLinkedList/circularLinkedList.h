#include <iostream>
using namespace std;

// Implementation of Node for Circular Linked List ADT
template <typename T>
class CircularLinkedListNode {
public:
  T data;
  CircularLinkedListNode<T>* next;

  // constructor  
  CircularLinkedListNode<T>(T data = 0, CircularLinkedListNode<T>* next = NULL) {
    this->data = data;
    this->next = next;
  }
  // destructor
  ~CircularLinkedListNode<T>() {
      this->next = NULL;
  }
  // getter
  void setData(T data) {
    this->data = data;
  }
  // setter
  T getData() const {
    return this->data;
  }
  // getter
  void setNext(CircularLinkedListNode<T>* next) {
    this->next = next;
  }
  // setters
  CircularLinkedListNode<T>* getNext() const {
    return this->next;
  }  
};

// Implementation of the Circular Linked List ADT
// Stores data in ascending order
// It is assumed that the relational operators are working 
// in accordance to the data that is to be inserted and store
// It stores duplicates as well
template<typename T>
class CircularLinkedList{
private:
  CircularLinkedListNode<T>* head;
  CircularLinkedListNode<T>* tail;
  int count;

public:
  // default constructor
  CircularLinkedList<T>() {
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
  }
  // parameterized constructor
  CircularLinkedList<T>(CircularLinkedListNode<T>* head, 
    CircularLinkedListNode<T>* tail, int count) {
    this->head = head;
    this->tail = tail;
    this->count = count;
  }
  // parameterized constructor
  CircularLinkedList<T>(T data) {
    this->head = new CircularLinkedListNode<T>(data);
    this->tail = head;
    this->head->next = this->head;
    this->count = 1;
  }
  // destructor
  ~CircularLinkedList<T>() {
    this->clear();
  }
  // deletes the list
  void clear() {
    if(this->head) {
      this->tail->next = NULL;
      CircularLinkedListNode<T>* curr = this->head;
      CircularLinkedListNode<T>* temp = NULL;
      while(curr) {
        temp = curr;
        curr = curr->next;
        delete temp;
        temp = NULL;
      }
      this->head = this->tail = NULL;
    }
    this->count = 0;
  }
  // returns true if the list is empty
  bool isEmpty() const {
		if (this->head)
			return false;
		else
			return true;
  }
  // returns the pointer to the first element in the list
  CircularLinkedListNode<T>* getHead() {
		return this->head;
	}
  // returns the pointer to the last element in the list
  CircularLinkedListNode<T>* getTail() {
		return this->tail;
	}
  // returns the number of elements in the list
  int getCount() const {
    return this->count;
  }
  // inserts data into the list in ascending order
  // ensure that the relational operators are working 
  // in accordance to the data being inserted
  void addData(T data) {
    ++this->count;
	  CircularLinkedListNode<T>* newNode = new CircularLinkedListNode<T>(data);
	  if (head == NULL) {
		  this->head = newNode;
		  this->tail = newNode;
		  newNode->next = head;
	  }
	  else {
		  CircularLinkedListNode<T>* current = this->head;
		  while (current->next != head && current->next->data < data) {
			  current = current->next;
		  }
      	// uncomment if duplicates are not to be stored
		  // if (newNode->data == current->next->data) {
		  // 	this->count -= 1;
		  // 	delete newNode;
      		  //  	newNode = NULL;
		  // 	cout << "Duplicate data cannot be inserted\n";
		  // 	return;
		  // }
		  // if data is to be inserted at head
		  if (current->next == this->head && current->next->data > data) {
			  newNode->next = this->head;
			  this->tail->next = newNode;
			  this->head = newNode;
		  }
		  // if the list has only one element and data is to be inserted at the head
		  else if (current == this->head && current->data > newNode->data) {
			  newNode->next = this->head;
			  this->tail->next = newNode;
			  this->head = newNode;
		  }
		  // if the data is to be inserted in-between current and current->next
		  else {
			  newNode->next = current->next;
			  current->next = newNode;
			  // if the data is inserted at the tail
			  if (newNode->next == this->head) {
			  	this->tail = newNode;
		    }
	    }
    }
  }
  // deletes data from the list
  // it is assumed that the relevant relational operators are
  // working in accordance to the data that is being deleted
  void deleteData(T data) {
	  if (head == NULL) {
		  cout << "List is empty" << endl;
      this->count = 0;
      return;
  	}
	  if (this->head->data == data) {
  		--this->count;
      if (this->head == this->tail) {
			  delete this->head;
			  this->head = NULL;
			  this->tail = NULL;
		  }
		  else {
			  this->tail->next = this->head->next;
			  CircularLinkedListNode<T>* current = this->head;
			  this->head = this->head->next;
			  delete current;
			  current = NULL;
		  }
		  return;
	  }
	  CircularLinkedListNode<T>* current = this->head;
	  while (current->next != this->head && current->next->data != data) {
		  current = current->next;
	  }
	  if (current->next != this->head) {
		  CircularLinkedListNode<T>* temp = current->next;
		  current->next = current->next->next;
		  if (temp == this->tail) {
			  this->tail = current;
		  }
		  delete temp;
      temp = NULL;
		  --this->count;
	  }
  }
  // prints the list in ascending order
  void print() const {
    if(this->head) {
      CircularLinkedListNode<T>* current = this->head;
        cout<<current->data<<endl;
        current = current->next;
        while(current != this->head) {
          cout<<current->data<<endl;
          current = current->next;
        } 
      }
    else
      cout<<"The Doubly Linked List is Empty\n";
  }
};
