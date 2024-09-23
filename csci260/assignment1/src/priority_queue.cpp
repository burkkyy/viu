/*
*
* TODO write doc
*
*/
#include "priority_queue.hpp"

#include <cmath>

namespace adt {

template<typename T>
bool PriorityQueue<T>::insert(Node item){
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
bool PriorityQueue<T>::remove(uint32_t key){
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
uint32_t PriorityQueue<T>::min_key(){
    return this->data[0].key;
}

// returns key of element with smallest value
template<typename T>
uint32_t PriorityQueue<T>::min_element(){
    if(this->empty()){
        throw "Empty tree";
    }

    return this->data[0].value;
}

template<typename T>
bool PriorityQueue<T>::remove_min(){
    uint32_t key = this->min_key();
    return this->remove(key);
}

template<typename T>
uint32_t PriorityQueue<T>::length(){
    return this->size;
}

template<typename T>
bool PriorityQueue<T>::is_empty(){
    return this->empty;
}

template<typename T>
bool PriorityQueue<T>::is_full(){
    return this->full;
}

template<typename T>
void PriorityQueue<T>::traverse(){
    // get number of levels for formatting the output better
    int levels = std::floor(std::log2(this->length())) + 1;

    for(int i = 0; i < levels; i++){
        int elements = 1 << i;
        for(int j = i; j < elements; j++){
            std::cout << this->data[j].key << " " << this->data[j].value << "\t";
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
