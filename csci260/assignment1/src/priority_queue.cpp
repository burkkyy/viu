/*
*
* TODO write doc
*
*/
#include "priority_queue.hpp"

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
    Node item = {key, value};
    // if tree is empty just make root node the new node
    if(this->empty()){
        this->data[i]  = item;
        return true;
    }

    // itter through array for empty spot, then let sort fix the tree
    for(auto& i :: this->data){
        std::cout << i.key << " " << i.value << std::endl;

        if(i.key == -1){
            i = item;
            return this->sort();
        }
    }

    return false;
}

template<typename T>
T PriorityQueue<T>::remove(uint32_t key){
    // simply set the key to -1 and let sort() fix the tree
    for(auto& i :: this->data){
        if(i.key == key){
            i.key = -1;
            return this->sort();
        }
    }
    return false;
}

template<typename T>
T PriorityQueue<T>::removeIndex(int index){
    return false;
}

template<typename T>
uint32_t PriorityQueue<T>::minKey(){
    return this->data[0].key;
}

// returns key of element with smallest value
template<typename T>
uint32_t PriorityQueue<T>::minElement(){
    if(this->empty()){
        throw "Empty tree";
    }

    return this->data[0].value;
}

template<typename T>
T PriorityQueue<T>::removeMin(){
    uint32_t key = this->minKey();
    return this->remove(key);
}

template<typename T>
int PriorityQueue<T>::length(){
    return this->size;
}

template<typename T>
bool PriorityQueue<T>::isEmpty(){
    return this->empty;
}

template<typename T>
bool PriorityQueue<T>::isFull(){
    return this->full;
}

template<typename T>
void PriorityQueue<T>::traverse() const{
    // get number of levels for formatting the output better
    int levels = std::floor(std::log2(this->length())) + 1;

    for(int i = 0; i < levels; i++){
        int elements = 1 << i;
        for(int j = i; j < elements; j++){
            std::cout << this->data[j].key << " " << "SOMEVALUE" << "\t";
        }
        std::cout << std::endl;
        
        for(int j = i; j < elements; j++){
            std::cout << "/\t\\\t";
        }
        
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

template<typename T>
bool PriorityQueue<T>::sort(){
    
}

}
