/*
*
* TODO write doc
*
*/

#include <vector>
#include <cstdint>

namespace adt {

template<typename T>
class PriorityQueue {
public:
  struct Node {
    uint32_t key;
    T value;

    bool operator<(const Node& o) const { return this->key < o.key; }
    bool operator>(const Node& o) const { return this->key > o.key; }
  };

  PriorityQueue();
  ~PriorityQueue();

  bool insert(uint32_t key, T value);
  T remove(uint32_t key);
  T removeIndex(int index);
  uint32_t minKey();
  T minElement();
  T removeMin();
  int length() const { return this->size; }
  bool isEmpty() const { return this->size <= 0; }
  bool isFull() const { return this->length() == MAX_SIZE; }
  void traverse() const;

private:
  void initialize();
  void heapify(int i);

  const int MAX_SIZE = 16;
  std::vector<Node> data;
  int size = 0;
};

}  // namespace adt
