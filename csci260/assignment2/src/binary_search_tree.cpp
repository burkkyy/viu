#include "binary_search_tree.hpp"

#include <iostream>

#include "customer.hpp"

template<typename T>
BST<T>::BST(){
  this->root = nullptr;
}

template<typename T>
BST<T>::~BST(){
  deleteRecursive(this->root);
}

template<typename T>
void BST<T>::insert(int key, T newData){
  if(this->root == nullptr){
    this->root = new Node(key, newData);
    return;
  }

  this->insert(key, newData, this->root);
}

template<typename T>
T BST<T>::find(int key){
  if(this->root == nullptr){
    throw "Tree is empty";
  }

  return find(key, this->root);
}

template<typename T>
void BST<T>::inorder(){
  inorder(this->root);
}

template<typename T>
void BST<T>::insert(int key, T newData, Node*& current){
  if(current == nullptr){ return; }

  if(current->key <= key){
    if(current->left == nullptr){
      current->left = new Node(key, newData);
      return;
    }

    this->insert(key, newData, current->left);
  } else {
    if(current->right == nullptr){
      current->right = new Node(key, newData);
      return;
    }

    this->insert(key, newData, current->right);
  }
}

template<typename T>
T BST<T>::find(int key, Node* current){
  if(current == nullptr){
    throw "Key not found in tree";
  }

  if(current->key <= key){
    return find(key, current->left);
  } else {
    return find(key, current->right);
  }
}

template<typename T>
void BST<T>::inorder(Node* current){
  if(current == nullptr){
    return;
  }
  inorder(current->left);
  std::cout << current->data << std::endl;
  inorder(current->right);
}

template<typename T>
void BST<T>::deleteRecursive(Node*& current){
  if(current == nullptr){
    return;
  }

  deleteRecursive(current->left);
  deleteRecursive(current->right);
  
  delete current;
  current = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
  return os << "customer { id: " << customer.id << ", email: " << customer.email << ", name: " << customer.name << ", active: " << customer.active << " }" << std::endl;
}

template class BST<Customer>;
