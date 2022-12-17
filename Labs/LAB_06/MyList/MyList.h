//
// Created by Alexandr on 10/23/2022.
//

#ifndef LABS_LAB_04_V2_MYLIST_MYLIST_H_
#define LABS_LAB_04_V2_MYLIST_MYLIST_H_

#include <cstddef>
#include <iostream>
template<typename T>
struct Node {
  T data;
  Node *next;
};
template<typename T>
class MyList {
 public:
  class iterator;
  class const_iterator;
  MyList();
  ~MyList();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;


  void push_back(T val);
  void push_front(T val);

  void pop_back();
  void pop_front();

  bool empty();
  void list_serializer();
  const T& operator[](std::size_t) const;
  T& operator[](std::size_t index);

  std::size_t size();

  T &back();
  T &front();
  const T& front() const;
  const T& back() const;
 private:
  Node<T> *m_head;
  std::size_t m_size;
};

//push element to back
template<typename T>
void MyList<T>::push_back(T val) {
  auto *new_node = new Node<T>;
  new_node->data = val;
  new_node->next = m_head;
  m_head = new_node;
  m_size++;
}

// push element to front
template<typename T>
void MyList<T>::push_front(T val) {
  auto *new_node = new Node<T>;
  new_node->data = val;
  new_node->next = nullptr;

  if (!m_head) {
    m_head = new_node;
    return;
  }

  auto *temp_ptr = m_head;
  while (temp_ptr && temp_ptr->next != nullptr) {
    temp_ptr = temp_ptr->next;
  }
  temp_ptr->next = new_node;
  m_size++;
}

// pop back element
template<typename T>
void MyList<T>::pop_back() {
  auto *temp_ptr = m_head;
  m_head = m_head->next;
  delete temp_ptr;
  m_size--;
}

// pop front element
template<typename T>
void MyList<T>::pop_front() {
  auto *temp_ptr = m_head;
  while (temp_ptr && temp_ptr->next->next != nullptr) {
    temp_ptr = temp_ptr->next;
  }
  delete temp_ptr->next;
  temp_ptr->next = nullptr;
  m_size--;
}

// empty checker
template<typename T>
bool MyList<T>::empty() {
  return m_head == nullptr;
}

// get size
template<typename T>
std::size_t MyList<T>::size() {
  return m_size;
}

// get back value
template<typename T>
T &MyList<T>::back() {
  return m_head->data;
}

// get front value
template<typename T>
T &MyList<T>::front() {
  auto *temp_ptr = m_head;
  while (temp_ptr && temp_ptr->next != nullptr) {
    temp_ptr = temp_ptr->next;
  }
  return temp_ptr->data;
}

// constructor
template<typename T>
MyList<T>::MyList() { // constructor
  m_head = nullptr;
  m_size = 0;
}

// destructor
template<typename T>
MyList<T>::~MyList() {
  auto *temp_ptr = m_head;
  auto *node_to_delete = m_head;
  while (temp_ptr) {
    temp_ptr = temp_ptr->next;
    delete node_to_delete;
    node_to_delete = temp_ptr;
  }
}

///////////////// ITERATOR Section /////////////////
template<typename T>
class MyList<T>::iterator {
 public:
  iterator(Node<T> *pointer);
  T &operator*() const;

  iterator& operator++();
  iterator operator++(int);

  bool operator==(const iterator &other) const;
  bool operator!=(const iterator &other) const;
 private:
  Node<T> *m_pointer;
};
template<typename T>
MyList<T>::iterator::iterator(Node<T> *pointer) {
  m_pointer = pointer;
}
template<typename T>
T &MyList<T>::iterator::operator*() const {
  return m_pointer->data;
}
template<typename T>
typename MyList<T>::iterator &MyList<T>::iterator::operator++() {
  m_pointer = m_pointer->next;
  return *this;
}
template<typename T>
typename MyList<T>::iterator MyList<T>::iterator::operator++(int) {
  iterator tmp = *this;
  m_pointer = m_pointer->next;
  return tmp;
}
template<typename T>
bool MyList<T>::iterator::operator==(const MyList<T>::iterator &other) const {
  return m_pointer == other.m_pointer;
}
template<typename T>
bool MyList<T>::iterator::operator!=(const MyList<T>::iterator &other) const {
  return m_pointer != other.m_pointer;
}
// iterator begin
template<typename T>
typename MyList<T>::iterator MyList<T>::begin() {
  return MyList::iterator(m_head);
}
// iterator end
template<typename T>
typename MyList<T>::iterator MyList<T>::end() {
  return MyList::iterator(nullptr);
}


///////////////// CONST ITERATOR Section /////////////////

template<typename T>
class MyList<T>::const_iterator {
 public:
//  const_iterator(Node<T> *pointer);
  const T &operator*() const;

  const_iterator& operator++();
  const_iterator operator++(int);

  bool operator==(const const_iterator &other) const;
  bool operator!=(const const_iterator &other) const;
 private:
  Node<T> *m_pointer;
};
template<typename T>
const T &MyList<T>::const_iterator::operator*() const
{
  return m_pointer->element;
}

template<typename T>
typename MyList<T>::const_iterator &MyList<T>::const_iterator::operator++()
{
  m_pointer = m_pointer->next;
  return *this;
}

template<typename T>
typename MyList<T>::const_iterator MyList<T>::const_iterator::operator++(int)
{
  const_iterator tmp = *this;
  m_pointer = m_pointer->next;
  return tmp;
}

template<typename T>
bool MyList<T>::const_iterator::operator==(const MyList<T>::const_iterator &other) const
{
  return m_pointer == other.m_pointer;
}

template<typename T>
bool MyList<T>::const_iterator::operator!=(const MyList<T>::const_iterator &other) const
{
  return m_pointer != other.m_pointer;
}

template <typename T>
T& MyList<T>::operator[](std::size_t index)
{
  auto ptr = m_head;

  while(index--){
    ptr = ptr->next;
  }

  return ptr->data;
}

template <typename T>
const T& MyList<T>::operator[](std::size_t index) const
{
  auto ptr = m_head;

  while(index--){
    ptr = ptr->next;
  }

  return ptr->data;
}

template <typename T>
typename MyList<T>::const_iterator MyList<T>::begin() const
{
  return MyList::const_iterator(m_head);
}

template <typename T>
typename MyList<T>::const_iterator MyList<T>::end() const
{
  return MyList::const_iterator(nullptr);
}
#endif //LABS_LAB_04_V2_MYLIST_MYLIST_H_
