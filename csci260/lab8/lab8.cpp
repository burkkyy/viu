#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

#define P(x) std::cout << x << std::endl

class SkipList {
public:
  SkipList(){
    this->sentinel = new Node(-1);
    this->height = 0;
  }

  ~SkipList(){
    delete this->sentinel;
  }

  bool insert(int key, const std::string& data){
    Node* current = this->sentinel;
    std::vector<Node*> path;
    path.reserve(this->height + 1);

    for(int i = this->height; i >= 0; i--){
      while (current->next != nullptr && current->next->key < key){
        current = current->next;
      }

      path.push_back(current);

      if(i > 0 && current->below != nullptr){
        current = current->below;
      }
    }

    if(current->next != nullptr && current->next->key == key){
      return false;
    }

    int nodeHeight = randh();

    // extending height?
    while(nodeHeight > this->height){
      Node* _sentinel = new Node(-1, data); // create new sentinel for new height
      
      _sentinel->below = this->sentinel; // old sentinel is on prev level
      this->sentinel = _sentinel;
      
      path.insert(path.begin(), sentinel); // puts sentinel at the front of path
      this->height++; // we can now safely extend height, with a sentinel on this new level
    }

    // inserting new node at each level
    Node* bnode = nullptr; // the same node but on the level below
    for(int i = 0; i <= nodeHeight; i++){
      Node* _node = new Node(key, data); // create the new node for the level
      
      _node->next = path.at(i)->next;
      path.at(i)->next = _node;
      
      _node->below = bnode;
      bnode = _node;
    }

    return true;
  }

  std::string lookup(int key){
    Node* node = this->search(key);

    if(node == nullptr){
      throw "Key not found";
    }

    return node->data;
  }


private:
  struct Node {
    Node(int k, const std::string& s = "") : key{k}, data{s} {}
    int key;
    std::string data;
    Node* next = nullptr;
    Node* below = nullptr;
  };

  Node* search(int key){
    Node* current = this->sentinel;

    for(int i = this->height - 1; i >= 0; i--){
      while(current->next != nullptr && current->next->key < key){
        current = current->next;
      }

      if(current->next->key == key){
        return current->next;
      }

      if(i > 0){
        current = current->below;
      }
    }

    return nullptr;
  }

  bool randb() { return rand() % 2; }
  
  int randh(){
    int h = 1;
    while(randb() && h < this->height + 1){ h++; }
    return h;
  }

  Node* sentinel;
  int height;
};

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  srand(time(0));
  
  try{

    SkipList list;

    // test insert
    const int TEST_NUM = 10;
    for(int i = 0; i < TEST_NUM; i++){
      std::string data = std::to_string(i);
      assert(list.insert(i, data) == true);
    }

    // test search
    for(int i = 0; i < TEST_NUM; i++){
      std::string data = std::to_string(i); // expected
      std::string s = list.lookup(i);
      assert(s == data);
    }
  } catch(const char* e){
    std::cout << e << std::endl;
    exit(1);
  }
  P("Tests pass.");

  return 0;
}
