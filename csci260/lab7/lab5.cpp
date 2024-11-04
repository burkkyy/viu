#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define P(x) std::cout << x << std::endl
#define NUMBER_NODES_ONSCREEN 10

struct TreeNode {
  struct Node {
    int key;
    std::string data;
  };

  std::vector<Node> nodes;
  TreeNode* children; // at most 5

  int size = 0;
  const int max_size = 5;
  bool full = false;

  TreeNode(){
    nodes.reserve(5);
  }

  bool put(int key, std::string data){
    if(size == max_size){
      full = true;
      return false;
    }

    for(auto& node : nodes){
      if(node.key == key){
        node.data = data;
        size++;
        return true;
      }
    }

    return false;
  }

  void insert(int key, std::string data){
    nodes.push_back({key, data});
    std::sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b){ return a.key < b.key; });
  }
};

class TwoFourTree {
public:
  TwoFourTree(){
    root = new TreeNode;
    root->children = new TreeNode[5];
  }
  
  ~TwoFourTree(){
    if(root == nullptr){ return; }
    delete root;
  }

  bool insert(int key, std::string data){
    if(root == nullptr){ return false; }



    return false;
  }

  bool lookup(int key, std::string& data){
    TreeNode* n = root;
    while(n != nullptr){
      if(n->put(key, data)){ return true; }

      int index = 4;  // assume key is > all keys in nodes
      for(int i = 0; i < n->size; i++){
        if(key < n->nodes[i].key){
          index = i;
          break;
        }
      }

      n = &n->children[index];
    }
    
    return false;
  }
private:
  

  TreeNode* root;
};

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  try{

    TwoFourTree tree;

    // test insert
    const int TEST_NUM = 10;
    for(int i = 0; i < TEST_NUM; i++){
      std::string input = "step " + i;
      tree.insert(i, input);
    }

    // test lookup
    for(int i = 0; i < TEST_NUM; i++){
      std::string input = "found " + i;
      tree.lookup(i, input);
    }
  } catch(const char* e){
    std::cout << e << std::endl;
    exit(1);
  }
  P("Tests pass.");

  return 0;
}
