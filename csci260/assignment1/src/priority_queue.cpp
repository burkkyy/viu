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
    } else if(this->size < this->MAX_SIZE){        
        this->data.push_back({key, value});
        this->size++;
        this->sort();
        return true;
    }
    return false;
}

template<typename T>
T PriorityQueue<T>::remove(uint32_t key){
    if(this->isEmpty()){
        throw "Removal attempted on empty queue!";
    }

    for(Node& i : this->data){
        if(i.key == key){
            T copy = i.value;
            
            // swap node to remove with last node for trival removal
            i = this->data.back();

            // We now have a dupe of last node, remove it and sort
            this->data.pop_back();
            this->size--;
            
            // skip sort if trival
            if(this->size <= 1){
                return copy;
            }

            this->sort();

            return copy;
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

    Node& removalNode = this->data[index];

    T copy = removalNode.value;

    // swap removalNode with last node for trival removal
    removalNode = this->data.back();

    // We now have a dupe of last node, remove it and sort
    this->data.pop_back();
    this->size--;

    this->sort();

    return copy;
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
    uint32_t key = this->minKey();
    return this->remove(key);
}

template<typename T>
void PriorityQueue<T>::traverse() const {
    for (Node i : this->data){
        std::cout << i.key << ", ";
    }
    std::cout << std::endl;
}

template<typename T>
void PriorityQueue<T>::heapify(int n, int i){
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && this->data[left] > this->data[max]){
        max = left;
    }

    if(right < n && this->data[right] > this->data[max]){
        max = right;
    }

    if(max != i){
        std::swap(this->data[i], this->data[max]);
        heapify(n, max);
    }
}

template<typename T>
void PriorityQueue<T>::sort(){
    if(this->length() <= 1){ return; }

    int n = this->length();

    // this loop is O(n / 2 - 1) = O(n)
    for(int i = n / 2 - 1; i >= 0; i--){
        this->heapify(n, i); // O(log n)
    }

    // this loop is O(n - 1) = O(n)
    for(int i = n - 1; i > 0; i--){
        std::swap(this->data[0], this->data[i]);
        this->heapify(i, 0); // O(log n)
    }
    
    // calling a O(log n) function n times, therefore sort() has O(n log n)
}

}

template class adt::PriorityQueue<job::Job>;
