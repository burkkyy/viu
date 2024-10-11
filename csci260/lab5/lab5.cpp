#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <format>
#include <cstdlib>
#include <cmath>

#define P(x) std::cout << x << std::endl
#define NUMBER_NODES_ONSCREEN 10

class AVLTree {
public:
  AVLTree(){ }

  ~AVLTree(){
    deleteRecursive(this->root);
  }

  void inOrder() const {
    P("In order: ");
    inOrderRecursive(this->root);
    std::cout << std::endl;
  }

  void preOrder() const {
    P("Pre order: ");
    preOrderRecursive(this->root);
    std::cout << std::endl;
  }

  void postOrder() const {
    P("Post order: ");
    postOrderRecursive(this->root);
    std::cout << std::endl;
  }

  void insert(double k){
    this->root = insertRecursive(this->root, k);
  }

  void remove(double k){ (void)k; throw "Not Implemented"; }

private:
  struct TreeNode {
    double data;
    TreeNode *left;
    TreeNode *right;
    int balance;

    TreeNode(double k) : data{k} {}
  };

  TreeNode* insertRecursive(TreeNode* root, double k){
    if(root == nullptr){ return new TreeNode(k); }

    if(k < root->data){
      root->left = insertRecursive(root->left, k);
    } else if(k > root->data){
      root->right = insertRecursive(root->right, k);
    } else {
      return root; // dupe keys
    }

    root->balance = getBalance(root);

    // left-left case
    if(root->balance > 1 && root->left->data > k){
      return rightRotate(root);
    }

    // right-right case
    if(root->balance < -1 && root->right->data < k){
      return leftRotate(root);
    }

    // left-right case
    if(root->balance > 1 && root->left->data < k){
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }

    // right-left case
    if(root->balance < -1 && root->left->data > k){
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }

    return root;
  }

  int getBalance(TreeNode* root){
    if(root == nullptr){ return 0; }
    return getHeight(root->left) - getHeight(root->right);
  }

  int getHeight(TreeNode* root){
    if(root == nullptr){ return 0; }
    return 1 + std::max(getHeight(root->left), getHeight(root->right)); 
  }

  void deleteRecursive(TreeNode* root){
    if(root == nullptr){ return; }
    deleteRecursive(root->left);
    deleteRecursive(root->right);
    delete root;
  }

  void inOrderRecursive(TreeNode* current) const {
    if(current == nullptr){ return; }
    inOrderRecursive(current->left);
    std::cout << "{ " << current->data << " } --> ";
    inOrderRecursive(current->right);
  }

  void preOrderRecursive(TreeNode* current) const {
    if(current == nullptr){ return; }
    std::cout << "{ " << current->data << " } --> ";
    preOrderRecursive(current->left);
    preOrderRecursive(current->right);
  }

  void postOrderRecursive(TreeNode* current) const {
    if(current == nullptr){ return; }
    postOrderRecursive(current->left);
    postOrderRecursive(current->right);
    std::cout << "{ " << current->data << " } --> ";
  }

  TreeNode* rightRotate(TreeNode* currentRoot){
    TreeNode* newRoot = currentRoot->left;
    TreeNode* child = newRoot->right;

    newRoot->right = currentRoot;
    currentRoot->left = child;

    currentRoot->balance = getBalance(currentRoot);
    newRoot->balance = getBalance(newRoot);

    return newRoot;
  }

  TreeNode* leftRotate(TreeNode* currentRoot){
    TreeNode* newRoot = currentRoot->right;
    TreeNode* child = newRoot->left;

    newRoot->left = currentRoot;
    currentRoot->right = child;

    currentRoot->balance = getBalance(currentRoot);
    newRoot->balance = getBalance(newRoot);

    return newRoot;
  }

  TreeNode* root = nullptr;
};

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  try{
    const int TEST_NUM = 10;
    AVLTree tree;

    tree.insert(0);
    tree.postOrder();

    // test insert
    srand(time(0));
    for(int i = 0; i < TEST_NUM; i++){
      double input = 1 + i;
      tree.insert(input);
    }
    
    tree.preOrder();
    tree.postOrder();

  } catch(const char* e){
    std::cout << e << std::endl;
    exit(1);
  }
  P("Tests pass.");

  return 0;
}
