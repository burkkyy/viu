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

  void insert(Node item);
  void remove(uint32_t key);
  void min_key();
  void min_element();
  void remove_min();
  void size();
  void is_empty();
  void is_full();

  void sort(T A, int N);

private:
  std::vector<T> data;
  uint32_t size;
  const uint32_t MAX_SIZE;
  bool empty;
  bool full;
};

}  // namespace adt

