#include <iostream>
#include <vector>

#define P(x) std::cout << x << std::endl

class LinkedList {
  public:
    // constructor
    LinkedList(int capacity){
      DataPile = new Cell[capacity];
    }

    // ignore duplicates, returns false if list already full{}
    bool insert(double newData){
      if(DataPile == 0){ 
        Cell n{newData, 1};
        DataPile[0] = n;
      }
    } 

    // return the index of the array cell that contains parameter data
    // or return -1 if data doesn't exist in the list
    int find(double data){
      for(int i = 0; i < this->size; i++){
        if(DataPile[i].data == data){
          return i;
        }
      }
      return -1;
    }

    // return false if oldData doesn't exist in the list
    // or if the list already full
    bool insertAfter(double oldData, double newData){

    }

    // return false if data doesn't exist in the list
    bool remove(double data){

    }

    // for testing purposes, display all data in the list
    void traverse(){
      for(int i = 0; i < size; i++){
        std::cout << DataPile[i].data << std::endl;
      }
    }

    // destructor
    ~LinkedList(){
      delete[] DataPile;
    }

  private:
    struct Cell {
        double data; // data part of the linked list node
        int next;    // link part of the linked list node
    };

    // suggested data fields
    int capacity;
    int size; // optional
    Cell *DataPile;
    int freeListHead;
    int listHead;
    // any other data fields that could be useful
};


int main(int argc, const char** argv){
  (void)argc;
  (void)argv;
  return 0;
}

