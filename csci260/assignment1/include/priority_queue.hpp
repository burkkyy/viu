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
  uint32_t minElement();
  T removeMin();
  int length();
  bool isEmpty();
  bool isFull();
  void traverse() const;
  bool sort();

private:
  void initialize();

  const int MAX_SIZE = 64;
  std::vector<T> data(MAX_SIZE);
  int size;
  bool empty;
  bool full;
};

}  // namespace adt

