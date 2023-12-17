#include <iostream>
using namespace std;

// Implementation of Node for the Doubly Linked List ADT
template <typename T>
class DoublyLinkedListNode {
public:
  T data;
  DoublyLinkedListNode<T>* next;
  DoublyLinkedListNode<T>* prev;

  // constructor  
  DoublyLinkedListNode<T>(T data = 0, DoublyLinkedListNode<T>* next = NULL, 
    DoublyLinkedListNode<T>* prev = NULL) {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
  // destructor
  ~DoublyLinkedListNode<T>() {
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
  void setNext(DoublyLinkedListNode<T>* next) {
    this->next = next;
  }
  // setters
  DoublyLinkedListNode<T>* getNext() const {
    return this->next;
  }
  // getter
  void setPrev(DoublyLinkedListNode<T>* prev) {
    this->prev = prev;
  }
  // setter
  DoublyLinkedListNode<T>* getPrev() const {
    return this->prev;
  }  
};

// Implementation of the Doubly Linked List ADT
// Stores data in ascending order
// It is assumed that the relational operators are working 
// in accordance to the data that is to be inserted and stored
// It stores duplicates as well
template<typename T>
class DoublyLinkedList{
private:
  DoublyLinkedListNode<T>* head;
  DoublyLinkedListNode<T>* tail;
  int count;

public:
  // default constructor
  DoublyLinkedList<T>() {
    this->head = NULL;
    this->tail = NULL;
    int count = 0;
  }
  // parameterized constructor
  DoublyLinkedList<T>(DoublyLinkedListNode<T>* head, 
    DoublyLinkedListNode<T>* tail, int count) {
    this->head = head;
    this->tail = tail;
    this->count = count;
  }
  // parameterized constructor
  DoublyLinkedList<T>(T data) {
    this->head = new DoublyLinkedListNode<T>(data);
    this->tail = head;
    this->head->next = this->head;
    this->head->prev = this->head;
    this->count = 1;
  }
  // destructor
  ~DoublyLinkedList<T>() {
    this->clear();
  }
  // deletes the list
  void clear() {
    if(this->head) {
      DoublyLinkedListNode<T>* current = this->head;
      DoublyLinkedListNode<T>* temp = NULL;
      while(current) {
        temp = current;
        current = current->next;
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
  DoublyLinkedListNode<T>* getHead() {
		return this->head;
	}
  // returns the pointer to the last element in the list
  DoublyLinkedListNode<T>* getTail() {
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
	  DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>(data);
	  if (this->head == NULL) {
		  this->head = newNode;
		  this->tail = newNode;
	  }
	  else {
		  DoublyLinkedListNode<T>* current = this->head;
		  while (current != NULL && current->data < data) {
			  current = current->next;
		  }
      // if the data is to be inserted at the head
      if(current == this->head) {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
      }
      // uncomment if duplicates are not to be stored
      // this feature has NOT BEEN TESTED. TEST IT BEFORE USE !!
		  // if (newNode->data == current->data) {
		  // 	this->count -= 1;
		  // 	delete newNode;
      //  newNode == NULL;
		  // 	cout << "Duplicate data cannot be inserted\n";
		  // 	return;
		  // }
      // if the newNode has to be inserted at the end of the list
		  else if(current == NULL) {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
      }
      else {
        newNode->next = current;
        newNode->prev = current->prev;
        newNode->prev->next = newNode;
        current->prev = newNode;
      }
    }
  }
  // deletes data from the list
  // it is assumed that the relevant relational operators are
  // working in accordance to the data that is being deleted
  void deleteData(T data) {
	  if (this->head == NULL) {
		  cout << "List is empty\n";
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
			  DoublyLinkedListNode<T>* current = this->head;
			  this->head = this->head->next;
			  this->head->prev = NULL;
			  delete current;
			  current = NULL;
		  }
		  return;
	  }
	  DoublyLinkedListNode<T>* current = this->head;
	  while (current != NULL && current->data != data) {
		  current = current->next;
	  }
	  if (current != NULL) {
		  DoublyLinkedListNode<T>* temp = current->next;
      current->prev->next = temp;
      // if the data is being deleted from in-between the list
      if(temp)
        temp->prev = current->prev;
      // if the data is being deleted from the end of the list
      else
        this->tail = current->prev; 
      delete current;
      current = NULL;
		  --this->count;
	  }
    else 
      cout<<"Given Data is not present in the List. Nothing to delete\n";
  }
  // prints the list in ascending order
  void print() const {
    if(this->head) {
      DoublyLinkedListNode<T>* current = this->head;
        while(current != NULL) {
          cout<<current->data<<endl;
          current = current->next;
        } 
        cout<<endl;
      }
    else
      cout<<"The Doubly Linked List is Empty\n";
  }
  // prints the list in reverse i.e. in descending order
  void printInReverse() const {
    if(this->tail) {
      DoublyLinkedListNode<T>* current = this->tail;
      while(current != NULL) {
        cout<<current->data<<endl;
        current = current->prev;
      }
      cout<<endl;
    }
    else 
      cout<<"The Doubly Linked List is Empty\n";
  }
};
