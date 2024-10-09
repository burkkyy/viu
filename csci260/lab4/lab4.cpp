#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <format>
#include <cstdlib>
#include <cmath>

#define P(x) std::cout << x << std::endl
#define NUMBER_NODES_ONSCREEN 10

class Tree {
public:
  // n represents the maximum children allowed for each node in the tree
  Tree(int n) : size{0}, capacity{n} { }

  ~Tree(){
    deleteRecursive(this->root);
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

  int getHeight() const {
    return getHeightRecursive(this->root);
  }
  
  int getSize() const { return this->size; }

  // insert as root, the old root becomes child of this new root
  void insert(std::string item){
    if(this->size >= this->capacity){ return; }

    Node* newRootp = new Node;
    newRootp->data = item;

    // trivial case
    if(this->root == nullptr){
      this->root = newRootp;
      this->size++;
      return;
    }

    this->root->p = newRootp;
    newRootp->r = root;
    this->root = newRootp;
    this->size++;
  }

  // parent should already be in the tree
  void insert(const std::string parent, std::string child){
    if(this->size >= this->capacity){ return; }

    Node* childp = find(this->root, child); // should return nullptr
    Node* parentp = find(this->root, parent);

    // dupe string or parent is not in tree
    if(childp || parentp == nullptr) { 
      return;
    }

    childp = new Node;  // note node is not in tree yet
    childp->data = child;
    childp->p = parentp;

    if(parentp->l == nullptr){
      parentp->l = childp;
    } else if(parentp->r == nullptr){
      parentp->r = childp;
    } else {
      delete childp;
      return; // both child are already occupided, therefore non valid parent
    }

    this->size++;
  }

  // display descendant strings of the given parameter string
  void listDescendants(const std::string item) const {
    Node* n = find(this->root, item);
    preOrderRecursive(n->l);
    preOrderRecursive(n->r);
  }

  // display child strings of the given parameter string
  void listChildren(const std::string item) const {
    Node* parent = find(this->root, item);
    if(parent == nullptr){ return; }

    std::string left = "", right = "";
    
    if(parent->l){ left = parent->l->data; }
    if(parent->r){ right = parent->r->data; }

    P("Child of " << item << ": left=" << left << " right=" << right);
  }

private:
  struct Node {
    Node* l;  // left child
    Node* r;  // right child
    Node* p; // parent
    std::string data;
  };

  Node* find(Node* current, std::string item) const {
    if(this->root == nullptr){ return nullptr; }

    if(current == nullptr || current->data == item){
      return current;
    }
    
    Node* left = find(current->l, item);
    Node* right = find(current->r, item);

    // if left is not null then we found item. Otherwise 
    // return right as it being null or not doesnt matter
    if(left != nullptr){
      return left;
    }
    return right;
  }

  // deletes all under root including root
  void deleteRecursive(Node* root){
    if(root == nullptr){ return; }
    deleteRecursive(root->l);
    deleteRecursive(root->r);
    delete root;
  }

  int getHeightRecursive(Node* current) const {
    if(current == nullptr){ return 0; }
    return 1 + std::max(getHeightRecursive(current->l), getHeightRecursive(current->r));
  }

  void preOrderRecursive(Node* current) const {
    if(current == nullptr){ return; }
    std::cout << "{ " << current->data << " } --> ";
    preOrderRecursive(current->l);
    preOrderRecursive(current->r);
  }

  void postOrderRecursive(Node* current) const {
    if(current == nullptr){ return; }
    postOrderRecursive(current->l);
    postOrderRecursive(current->r);
    std::cout << "{ " << current->data << " } --> ";
  }
  
  Node* root = nullptr;
  int size;
  int capacity;
};

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  try{
    const int TEST_NUM = 10;
    Tree tree(TEST_NUM);

    std::string rootString = "orig root!";
    tree.insert(rootString);
    tree.postOrder();

    std::string lastIn = rootString;
    
    // test insert
    for(int i = 0; i < TEST_NUM - 2; i++){
      std::string item = "child ";
      item += std::to_string(i);
      tree.insert(lastIn, item);
      lastIn = item;

      // ensure tree size
      assert(tree.getSize() == i + 2);
    }
    
    tree.insert("new root!");
    assert(tree.getSize() == TEST_NUM);
    
    tree.preOrder();
    tree.postOrder();

  } catch(const char* e){
    std::cout << e << std::endl;
    exit(1);
  }
  P("Tests pass.");

  return 0;
}
