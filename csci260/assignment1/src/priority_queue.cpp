/*
*
* TODO write doc
*
*/
#include "priority_queue.hpp"

#include "job.hpp"

#include <iostream>
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
    if(this->isEmpty()){
        this->data[0] = item;
        return true;
    }

    // itter through array for empty spot, then let sort fix the tree
    for(Node& i : this->data){
        std::cout << i.key << " " << i.value << std::endl;

        if(i.key == 1){
            i = item;

            // sort 

            return true;
        }
    }

    return false;
}

template<typename T>
T PriorityQueue<T>::remove(uint32_t key){
    // simply set the key to -1 and let sort() fix the tree
    for(Node& i : this->data){
        if(i.key == key){
            return i.value;
        }
    }
    throw "Key not in queue";
}

template<typename T>
T PriorityQueue<T>::removeIndex(int index){
    (void)index;
    throw "Not implemented";
}

template<typename T>
uint32_t PriorityQueue<T>::minKey(){
    return this->data[0].key;
}

template<typename T>
T PriorityQueue<T>::minElement(){
    if(this->isEmpty()){
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
void PriorityQueue<T>::traverse() const {
    // get number of levels for formatting the output better
    int len = this->length();
    int levels = std::floor(std::log2(len)) + 1;

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

}

template class adt::PriorityQueue<job::Job>;
