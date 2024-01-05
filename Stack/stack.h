#include <iostream>
//using namespace std;

template<typename T>
class Stack {
private:
  template<typename U>
  class Node {
  public:
    U data;
    Node<U>* next;
    Node<U>() : data(0), next(NULL) {}
    Node<U>(U data, Node<U>* next = NULL) : data(data), next(next) {}
    ~Node<U>() {
      this->next = NULL;
    }
  };
private:
  Node<T>* head;
public:
  Stack<T>() : head(NULL) {}
  Stack<T>(T data) : head(new Node<T>(data)) {}
  ~Stack<T>() {
    this->MAKENULL();
  }
  void MAKENULL() {
    if(this->head) {
      Node<T>* curr = this->head;
      Node<T>* next = NULL;
      while(curr) {
        next = curr->next;
        delete curr;
        curr = next;
      }
      this->head = NULL;
    }
  } 
  T TOP() const {
    if(this->head) 
      return this->head->data;
    else
      return 0;
  }
  T POP() {
    if(this->head) {
      Node<T>* curr = this->head;
      this->head = this->head->next;
      T data = curr->data;
      delete curr;
      return data;
    }
    else
      return 0;
  }
  void PUSH(T data) {
    Node<T>* newNode = new Node<T>(data);
    if(this->head) {
      newNode->next = this->head;
      this->head = newNode;
    }
    else 
      this->head = newNode;
  }
  bool EMPTY() {
    if(this->head)
      return false;
    else
      return true;
  }
  void print() const {
    if(this->head) {
      Node<T>* curr = this->head;
      while(curr) {
        std::cout<<curr->data<<std::endl;
        curr = curr->next;
      }
    }
    else
      std::cout<<"Stack is Empty"<<std::endl;
  }
};