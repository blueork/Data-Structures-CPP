#include <iostream>
using namespace std;

// Implementation of Node for the Doubly Circular Linked List ADT
template <typename T>
class DoublyCircularLinkedListNode {
public:
  T data;
  DoublyCircularLinkedListNode<T>* next;
  DoublyCircularLinkedListNode<T>* prev;

  // constructor  
  DoublyCircularLinkedListNode<T>(T data = 0, DoublyCircularLinkedListNode<T>* next = NULL, 
    DoublyCircularLinkedListNode<T>* prev = NULL) {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
  // destructor
  ~DoublyCircularLinkedListNode<T>() {
      this->next = NULL;
      this->prev = NULL;
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
  void setNext(DoublyCircularLinkedListNode<T>* next) {
    this->next = next;
  }
  // setters
  DoublyCircularLinkedListNode<T>* getNext() const {
    return this->next;
  }
  // getter
  void setPrev(DoublyCircularLinkedListNode<T>* prev) {
    this->prev = prev;
  }
  // setter
  DoublyCircularLinkedListNode<T>* getPrev() const {
    return this->prev;
  }  
};

// Implementation of the Doubly Circular Linked List ADT
// Stores data in ascending order
// It is assumed that the relational operators are working 
// in accordance to the data that is to be inserted and store
// It stores duplicates as well
template<typename T>
class DoublyCircularLinkedList{
private:
  DoublyCircularLinkedListNode<T>* head;
  DoublyCircularLinkedListNode<T>* tail;
  int count;
public:
  // default constructor
  DoublyCircularLinkedList<T>() {
    this->head = NULL;
    this->tail = NULL;
    int count = 0;
  }
  // parameterized constructor
  DoublyCircularLinkedList<T>(DoublyCircularLinkedListNode<T>* head, 
    DoublyCircularLinkedListNode<T>* tail, int count) {
    this->head = head;
    this->tail = tail;
    this->count = count;
  }
  // parameterized constructor
  DoublyCircularLinkedList<T>(T data) {
    this->head = new DoublyCircularLinkedListNode<T>(data);
    this->tail = head;
    this->head->next = this->head;
    this->head->prev = this->head;
    this->count = 0;
  }
  // destructor
  ~DoublyCircularLinkedList<T>() {
    this->clear();
  }
  // deletes the list
  void clear() {
    if(this->head) {
      this->tail->next = NULL;
      DoublyCircularLinkedListNode<T>* curr = this->head;
      DoublyCircularLinkedListNode<T>* temp = NULL;
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
  DoublyCircularLinkedListNode<T>* getHead() {
		return this->head;
	}
  // returns the pointer to the last element in the list
  DoublyCircularLinkedListNode<T>* getTail() {
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
	  DoublyCircularLinkedListNode<T>* newNode = new DoublyCircularLinkedListNode<T>(data);
	  if (head == NULL) {
		  this->head = newNode;
		  this->tail = newNode;
		  newNode->next = head;
		  newNode->prev = head;
	  }
	  else {
		  DoublyCircularLinkedListNode<T>* current = this->head;
		  while (current->next != head && current->next->data < data) {
			  current = current->next;
		  }
      // uncomment if duplicates are not to be stored
      // this feature has NOT BEEN TESTED. TEST IT BEFORE USE !!
		  // if (newNode->data == current->data)
		  // {
		  // 	this->count -= 2;
		  // 	delete newNode;
      //  newNode == NULL;
		  // 	cout << "duplicates machine cannot be inserted " << endl;
		  // 	return;
		  // }
		  if (current->next == this->head && current->next->data > data) {
			  newNode->next = this->head;
			  newNode->prev = this->tail;
			  this->head->prev = newNode;
			  this->tail->next = newNode;
			  this->head = newNode;
		  }
		  else if (current == this->head && current->data > newNode->data) {
			  newNode->next = this->head;
			  newNode->prev = this->tail;
			  this->head->prev = newNode;
			  this->tail->next = newNode;
			  this->head = newNode;
		  }
		  else {
			  newNode->next = current->next;
			  newNode->prev = current;
			  current->next->prev = newNode;
			  current->next = newNode;
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
			  DoublyCircularLinkedListNode<T>* current = this->head;
			  this->head = this->head->next;
			  this->head->prev = this->tail;
			  delete current;
			  current = NULL;
		  }
		  return;
	  }
	  DoublyCircularLinkedListNode<T>* current = this->head;
	  while (current->next != this->head && current->next->data != data) {
		  current = current->next;
	  }
	  if (current->next != this->head) {
		  DoublyCircularLinkedListNode<T>* temp = current->next;
		  current->next = current->next->next;
		  if (temp == this->tail) {
			  this->tail = current;
		  }
		  current->next->prev = current;
		  delete temp;
      temp = NULL;
		  --this->count;
	  }
  }
  // prints the list in ascending order
  void print() const {
    if(this->head) {
      DoublyCircularLinkedListNode<T>* current = this->head;
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
  // prints the list in reverse i.e. in descending order
  void printInReverse() const {
    if(this->tail) {
      DoublyCircularLinkedListNode<T>* current = this->tail;
      cout<<current->data<<endl;
      current = current->prev;
      while(current != this->tail) {
        cout<<current->data<<endl;
        current = current->prev;
      }
    }
    else 
      cout<<"The Doubly Linked List is Empty\n";
  }
};
