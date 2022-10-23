//
// Created by Alexandr on 10/23/2022.
//

#ifndef LABS_LAB_04_V2_MYLIST_MYLIST_H_
#define LABS_LAB_04_V2_MYLIST_MYLIST_H_

#include <cstddef>
template<typename T>
struct Node {
  T data;
  Node *next;
};

template<typename T>
class MyList {
 private:
  Node<T> *m_head;
  std::size_t m_size;
 public:
  MyList();
  ~MyList();

  void push_back(T val);
  void push_front(T val);
  void pop_back();
  void pop_front();
  bool empty();
  std::size_t size();
  T &back();
  T &front();

};

template<typename T>
void MyList<T>::push_back(T val) {
  auto *new_node = new Node<T>;
  new_node->data = val;
  new_node->next = m_head;
  m_head = new_node;
  m_size++;
}

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

template<typename T>
void MyList<T>::pop_back() {
  auto *temp_ptr = m_head;
  m_head = m_head->next;
  delete temp_ptr;
  m_size--;
}

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

template<typename T>
bool MyList<T>::empty() {
  return m_head == nullptr;
}
template<typename T>
std::size_t MyList<T>::size() {
  return m_size;
}
template<typename T>
T &MyList<T>::back() {
  return m_head->data;
}
template<typename T>
T &MyList<T>::front() {
  auto *temp_ptr = m_head;
  while (temp_ptr && temp_ptr->next != nullptr) {
    temp_ptr = temp_ptr->next;
  }
  return temp_ptr->data;
}
template<typename T>
MyList<T>::MyList() {
  m_head = nullptr;
  m_size = 0;
}
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

#endif //LABS_LAB_04_V2_MYLIST_MYLIST_H_
