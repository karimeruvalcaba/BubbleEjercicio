#include "LinkedList.h"
#include "Dungeon.h"
#include "Map.h"
#include "Monster.h"
#include "SpellAndAbility.h"
#include <iostream>
using namespace std;
template <typename T> LinkedList<T>::LinkedList() { first = nullptr; }

template <typename T> void LinkedList<T>::print() {
  Node<T> *temp = first;
  while (temp != nullptr) {
    cout << temp->getData() << endl;
    temp = temp->getNext();
  }
}
template <typename T> int LinkedList<T>::find(T data) {
  Node<T> *temp = first;
  int count = 0;
  while (temp != nullptr) {
    if (temp->getData() == data) {
      break;
    }
    count++;
    temp = temp->getNext();
  }
  if (temp == nullptr) {
    return -1;
  }
  return count;
}
template <typename T> void LinkedList<T>::addNode(T data) {
  Node<T> *newNode = new Node<T>(data);
  if (!first) {
    first = newNode;
  } else {
    Node<T> *current = first;
    while (current->getNext()) {
      current = current->getNext();
    }
    current->setNext(newNode);
  }
}

template <typename T> void LinkedList<T>::swap(int x, int y) {
  T temp = findAtPos(x)->getData();
  findAtPos(x)->setData(findAtPos(y)->getData());
  findAtPos(y)->setData(temp);
}
template <typename T> Node<T> *LinkedList<T>::findAtPos(int pos)  {
  Node<T> *temp = first;
  int count = 0;
  while (temp != nullptr) {
    if (count == pos) {
      return temp;
    }
    count++;
    temp = temp->getNext();
  }
  return nullptr;
}

template <typename T> void LinkedList<T>::bubbleSort() {
  Node<T> *temp1 = first;
  while (temp1 != nullptr) {
    Node<T> *temp2 = first;
    int j = 0;
    while (temp2->getNext() != nullptr) {
      if (temp2->getData() > temp2->getNext()->getData()) {
        swap(j, j + 1);
      }
      j++;
      temp2 = temp2->getNext();
    }
    temp1 = temp1->getNext();
  }
}

template <typename T> int LinkedList<T>::getSize() {
  int count = 0;
  Node<T> *temp = first;
  while (temp) {
    count++;
    temp = temp->getNext();
  }
  return count;
}

template <typename T> T LinkedList<T>::getAtPos(int pos) {
  Node<T> *temp = findAtPos(pos);
  if (temp) {
    return temp->getData();
  } else {
    return T();
  }
}

template <typename T> T LinkedList<T>::getData(int index) {
  if (index < 0 || index >= getSize()) {
    throw std::out_of_range("Index out of range");
  }
  Node<T> *current = first;
  for (int i = 0; i < index; i++) {
    current = current->getNext();
  }
  return current->getData();
}


template class LinkedList<int>;
template class LinkedList<Monster>;
template class LinkedList<SpellAndAbility>;
template class LinkedList<Dungeon>;
