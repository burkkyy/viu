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
  bool isEmpty() const { return this->empty; }
  bool isFull() const { return this->full; }
  void traverse() const;

private:
  void initialize();

  const int MAX_SIZE = 64;
  std::vector<Node> data;
  int size;
  bool empty;
  bool full;
};

}  // namespace adt
