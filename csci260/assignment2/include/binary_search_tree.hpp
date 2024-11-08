#pragma once

template<typename T>
class BST {
public:
  BST();
  ~BST();

  void insert(int key, T newData);
  T find(int key);

  void inorder();

private:
  struct Node {
    Node(int key, T newData) : key{key}, data{newData}, left{nullptr}, right{nullptr} {}
    
    int key;
    T data;
    Node* left;
    Node* right;
  };

  void insert(int key, T newData, Node*& current);
  T find(int key, Node* current);
  void inorder(Node* current);

  void deleteRecursive(Node*& current);
  
  Node* root;
};
