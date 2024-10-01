#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <format>
#include <cstdlib>
#include <cmath>

#define P(x) std::cout << x << std::endl
#define NUMBER_NODES_ONSCREEN 10

class HashTable
{
  struct Node {
    int key;
    std::string value;
  };

  struct Bucket {
    std::vector<Node> nodes;

    Node& operator[](int i){ return this->nodes[i]; }

    void insert(int key, std::string value){ this->nodes.push_back({key, value}); }
    
    std::string find(int key){
      for(const Node& node : this->nodes){
        if(node.key == key){
          return node.value;
        }
      }
      throw "Key not found";
    }

    void traverse(int i){
      std::cout << i << ": ";

      // clutters screen too much
      if(this->nodes.size() > NUMBER_NODES_ONSCREEN){
        std::cout << "This bucket conatins " << this->nodes.size() << " nodes" << std::endl;
        return;
      }

      for(const Node& node : this->nodes){
        std::cout << "{ key: " << node.key << ", value: " << node.value << "} ->";
      }

      std::cout << std::endl;
    }
  };
  
  public:
    HashTable() {
      srand(time(0));

      a = 1471;
      b = 1693;

      // ensure for 0 < i < N, Bucket[i] exists
      data.reserve(N);
    }

    ~HashTable(){

    }

    bool insert(int k, std::string e){
      int i = h(k);
      
      if(0 > i || i >= N){
        std::cout << i << std::endl;
        throw "Hash returned out of bounds index";
      }

      this->data[i].insert(k, e);
      return true;
    }

    std::string lookup(int k){
      int i = h(k);
      
      if(0 > i || i >= N){
        throw "Hash returned out of bounds index";
      }

      return this->data[i].find(k);
    }

    // if hash table size == number of inserted elements
    bool ensureSize(int expectedSize){
      int s = 0;

      for(int i = 0; i < N; i++){
        s += this->data[i].nodes.size();
      }

      if(s == expectedSize){
        return true;
      } else {
        std::cout << "HashTableError :: expectedSize: " << expectedSize << " size: " << s << std::endl;
        return false;
      }
      return false;
    }

    void traverse(){
      for(int i = 0; i < N; i++){ this->data[i].traverse(i); }
    }

  private:
    int h(int k){
      return std::abs(a * k + b) % N;
    }

    int a;
    int b;
    const int N = 79;
    std::vector<HashTable::Bucket> data; 
};

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  HashTable list;

  try{

    const int TEST_NUM = 1000;

    // test insert
    for(int i = 0; i < TEST_NUM; i++){
      int key = i;
      std::string input = std::format("Testing step {}", i);
      assert(list.insert(key, input));
      
      std::string s = list.lookup(key);

      assert(s == input);
      assert(list.ensureSize(i + 1));
    }
    
    assert(list.ensureSize(TEST_NUM));

    // test lookup
    for(int i = 0; i < TEST_NUM; i++){
      int key = i;
      std::string ret = list.lookup(key);
      std::string expected = std::format("Testing step {}", i);

      assert(ret == expected);
    }

    list.traverse();

  } catch(const char* e){
    std::cout << e << std::endl;
    exit(1);
  }
  P("Tests pass.");

  return 0;
}
