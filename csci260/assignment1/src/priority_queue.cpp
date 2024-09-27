/*
*
* TODO write doc
*
*/
#include "priority_queue.hpp"

#include "job.hpp"

#include <iostream>
#include <algorithm>
#include <cmath>

namespace adt {

template<typename T>
PriorityQueue<T>::PriorityQueue(){
  this->initialize();
}

template<typename T>
PriorityQueue<T>::~PriorityQueue(){

}

template<typename T>
void PriorityQueue<T>::initialize(){
    
}

template<typename T>
bool PriorityQueue<T>::insert(uint32_t key, T value){
  if(this->isFull()){
    return false;
  }

  this->data.push_back({key, value});
  this->size++;

  int i = this->size - 1;

  while(i != 0 && this->data[i] < this->data[(i - 1) / 2]){
    std::swap(this->data[i], this->data[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
  return true;
}

template<typename T>
T PriorityQueue<T>::remove(uint32_t key){
  if(this->isEmpty()){
    throw "Removal attempted on empty queue!";
  }

  for(int i = 0; i < this->size; i++){
    if(this->data[i].key == key){
      return this->removeIndex(i);
    }
  }

  throw "Key not in queue!";
}

template<typename T>
T PriorityQueue<T>::removeIndex(int index){
  if(this->isEmpty()){
    throw "Removal attempted on empty queue!";
  } else if(this->size <= index && index <= 0){
    throw "Removal index is out of bounds of queue";
  }

  this->data[index].key = 0; // lowest key value

  // bubble to the top and let removeMin deal with it.
  // Really we dont need these checks. This is allowed since 
  // we can safelly assume min heap property in the queue
  while (index > 0 && this->data[index].key <= this->data[(index - 1) / 2].key){
    std::swap(this->data[index], this->data[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
  return this->removeMin();
}

template<typename T>
uint32_t PriorityQueue<T>::minKey(){
  if(this->isEmpty()){
    throw "Calling for minKey on empty queue!";
  }
  return this->data.front().key;
}

template<typename T>
T PriorityQueue<T>::minElement(){
  if(this->isEmpty()){
    throw "Calling for minElement on empty queue!";
  }
  throw "Not Implemented";
}

template<typename T>
T PriorityQueue<T>::removeMin(){
  if(this->isEmpty()){
    throw "Empty queue";
  } else if(this->size == 1){
    T copy = this->data.front().value;
    this->data.pop_back();
    this->size--;
    return copy;
  }

  T copy = this->data.front().value;
  std::swap(this->data[0], this->data[this->size - 1]);

  this->data.pop_back();
  this->size--;

  // ensure min heap
  this->heapify(0);

  return copy;
}

template<typename T>
void PriorityQueue<T>::traverse() const {
  for (Node i : this->data){
    std::cout << "{ Priority: " << i.key << ", " << i.value << " }, ";
  }
  std::cout << std::endl;
}

template<typename T>
void PriorityQueue<T>::heapify(int i){
  // all this does is take data[i] as the root node 
  // and esures data[i] is smallest key in the tree (technically subtree)

  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int min = i;

  if(left < this->size && this->data[left] < this->data[min]){
    min = left;
  }

  if(right < this->size && this->data[right] < this->data[min]){
    min = right;
  }

  // if min == i we are at root and therefore already 
  // the smallest key found in each subtree
  if(min != i){
    std::swap(this->data[i], this->data[min]);

    // We know which child has smaller key,
    // simply assume that to be the root node 
    // of some subtree and check its children
    // for any smaller keys (recursive impl is alot simplier)
    heapify(min);
    // when this returns we are the smallest key in all subtrees
  }
}

}

template class adt::PriorityQueue<job::Job>;
