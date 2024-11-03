#ifndef MAP_CPP_H
#define MAP_CPP_H

#include <gtest/gtest.h>

#include <initializer_list>
#include <iostream>
#include <utility>

template <typename Key, typename T>
class Map {
 private:
  using value_type = T;
  using key_type = Key;
  using pair = std::pair<key_type, value_type>;
  struct Node {
    pair data;
    Node* right;
    Node* left;
    Node* parent;

    Node(key_type key, value_type value)
        : data(key, value), right(nullptr), left(nullptr), parent(nullptr) {}
  };
  Node* head;
  size_t size_map;

 public:
  Map() : head(nullptr), size_map(0) {}
  ~Map();
  size_t size();
  void clear_map(Node*);
  class iterator;
  iterator begin();
  iterator end();
  iterator insert(pair);
  class iterator {
   private:
    Node* current;

   public:
    friend class Map;
    iterator(Node* current) : current(current) {}
    pair* operator->() { return &current->data; }
  };
};

template <typename Key, typename T>
Map<Key, T>::~Map() {
  clear_map(head);
}

template <typename Key, typename T>
size_t Map<Key, T>::size() {
  return size_map;
}

template <typename Key, typename T>
void Map<Key, T>::clear_map(Node* head) {
  if (head) {
    clear_map(head->left);
    clear_map(head->right);
    delete head;
  }
}

template <typename Key, typename T>
typename Map<Key, T>::iterator Map<Key, T>::begin() {
  return iterator(head);
}

template <typename Key, typename T>
typename Map<Key, T>::iterator Map<Key, T>::end() {
  return iterator(nullptr);
}

template <typename Key, typename T>
typename Map<Key, T>::iterator Map<Key, T>::insert(pair item) {
  Node* new_node = new Node(item.first, item.second);
  if (!head) {
    head = new_node;
    head->parent = new_node;
  } else {
    Node* current = head;
    Node* parrent = nullptr;
    while (current) {
      if (current->data.first > item.first) {
        parrent = current;
        current = current->left;
      } else {
        parrent = current;
        current = current->right;
      }
    }
    if (parrent->data.first > item.first) {
      new_node->parent = parrent;
      parrent->left = new_node;
    } else {
      new_node->parent = parrent;
      parrent->right = new_node;
    }
  }
  size_map++;
  return iterator(new_node);
}

#endif
