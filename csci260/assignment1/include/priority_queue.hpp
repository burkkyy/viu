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

  bool insert(Node item);
  bool remove(uint32_t key);
  uint32_t min_key();
  uint32_t min_element();
  bool remove_min();
  uint32_t length();
  bool is_empty();
  bool is_full();
  void traverse();
  bool sort();

private:
  std::vector<T> data;
  uint32_t size;
  const uint32_t MAX_SIZE;
  bool empty;
  bool full;
};

}  // namespace adt

