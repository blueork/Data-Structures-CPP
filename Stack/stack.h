#include <iostream>
//using namespace std;

template< typename T >
class NodeForStack {
private:
  T data;
  NodeForStack<T>* next;
public:
  NodeForStack<T>() {
    this->data = 0;
    this->next = NULL;
  }
  NodeForStack<T>( T data, NodeForStack<T>* next = NULL ) {
    this->data = data;
    this->next = next;
  }
  ~NodeForStack<T>() {
    this->next = NULL;
  }
  T getData() const {
    return this->data;
  }
  NodeForStack<T>* getNext() const {
    return this->next;
  }
  void setData( T data ) {
    this->data = data;
  }
  void setNext( NodeForStack<T>* next ) {
    this->next = next;
  }
};

template< typename T >
class Stack {
private:
  NodeForStack<T>* head;
public:
  Stack<T>() {
    this->head = NULL;
  }
  Stack<T>( T data ) {
    this->head = new NodeForStack<T>( data );
  }
  ~Stack<T>() {
    this->MAKENULL();
  }
  void MAKENULL() {
    if( this->head ) {
      NodeForStack<T>* curr = this->head;
      NodeForStack<T>* next = NULL;
      while( curr ) {
        next = curr->getNext();
        delete curr;
        curr = next;
      }
      this->head = NULL;
    }
  } 
  T TOP() const {
    if( this->head ) 
      return this->head->getData();
    else
      return 0;
  }
  T POP() {
    if( this->head ) {
      NodeForStack<T>* curr = this->head;
      this->head = this->head->getNext();
      T data = curr->getData();
      delete curr;
      return data;
    }
    else
      return 0;
  }
  int PUSH( T data ) {
    NodeForStack<T>* newNode = new NodeForStack<T>( data );
    if( this->head ) {
      newNode->setNext( this->head );
      this->head = newNode;
    }
    else {
      this->head = newNode;
      return 1;
    }
    return -1;
  }
  bool EMPTY() {
    if( this->head )
      return false;
    else
      return true;
  }
  void print() const {
    if( this->head ) {
      NodeForStack<T>* curr = this->head;
      while( curr ) {
        std::cout<<curr->getData()<<std::endl;
        curr = curr->getNext();
      }
    }
    else
      std::cout<<"Stack is Empty"<<std::endl;
  }
};