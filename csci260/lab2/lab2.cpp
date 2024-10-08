#include <iostream>
#include <vector>
#include <cassert>

#define P(x) std::cout << x << std::endl

class LinkedList {
  public:
    // constructor
    LinkedList(int capacity) : capacity{capacity}, size{1} {
      this->DataPile = new Cell[capacity];
      
      // create dummy node
      this->DataPile[0].data = 0.0;
      this->DataPile[0].next = 0;
      this->headIndex = 0;

      // set each cell next to -1 which means its an available spot
      for(int i = 1; i < capacity; i++){
        this->DataPile[i].next = -1;
      } 
    }

    // ignore duplicates, returns false if list already full{}
    bool insert(double newData){
      // check if available space
      if(this->capacity < this->size + 1){
        return false;
      }

      // find next available spot
      for(int i = 0; i < this->capacity; i++){
        if(this->DataPile[i].next == -1){
          // i is index of new cell
          this->DataPile[i].data = newData;
          this->DataPile[i].next = 0;
          
          // set head index
          this->DataPile[this->headIndex].next = i;
          this->headIndex = i;
          this->size++;

          return true;
        }
      }

      std::cout << "Unknown error in insert" << std::endl;
      return false;
    }

    // return the index of the array cell that contains parameter data
    // or return -1 if data doesn't exist in the list
    int find(double data){
      for(int i = 0; i < this->size; i++){
        if(this->DataPile[i].data == data){
          return i;
        }
      }
      return -1;
    }

    // return false if oldData doesn't exist in the list
    // or if the list already full
    bool insertAfter(double oldData, double newData){
      int parentIndex = find(oldData);

      // look for an open spot
      for(int i = 0; i < this->capacity; i++){
        if(this->DataPile[i].next == -1){
          this->DataPile[i].data = newData;
          this->DataPile[i].next = this->DataPile[parentIndex].next;
          this->DataPile[parentIndex].next = i;

          this->size++;
          return true;
        }
      }

      return false;
    }

    // return false if data doesn't exist in the list
    bool remove(double data){
      int i = 0;
      
      do {
        int nextIndex = this->DataPile[i].next;

        if(this->DataPile[nextIndex].data == data){
          if(nextIndex == 0){
            return false;
          } else if(nextIndex == this->headIndex){
            this->DataPile[i].next = 0;
            this->DataPile[nextIndex].next = -1;
            this->headIndex = i;
          } else {
            this->DataPile[i].next = this->DataPile[nextIndex].next;
            this->DataPile[nextIndex].next = -1;
          }
          
          this->size--;
          return true;
        }

        i = this->DataPile[i].next;
      } while(i != 0);

      return false;
    }

    // for testing purposes, display all data in the list
    void traverse(){
      // std::cout << "HEAD " << this->headIndex << std::endl;
      // for(int i = 0; i < this->capacity; i++){
      //   std::cout << this->DataPile[i].data << " " << this->DataPile[i].next << std::endl;
      // }

      // skip dummy node
      int i = this->DataPile[0].next;

      while(i != 0){
        std::cout << "Cell{ data: " << this->DataPile[i].data << ", next: " << this->DataPile[i].next << " } --> ";
        i = this->DataPile[i].next;
      }

      std::cout << "EMPTY" << std::endl;
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

    int capacity;
    int size;
    Cell* DataPile;
    // int freeListHead;
    int headIndex;
};

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  LinkedList list(10);

  assert(list.insert(11.0));
  assert(list.insert(-12.0));
  assert(list.insert(9871.142));

  P("insert after -12");
  assert(list.insertAfter(-12.0, 3.0));
  list.traverse();

  P("insert after 11.0");
  assert(list.insertAfter(11.0, 2.0));
  list.traverse();

  P("Remove -12");
  assert(list.remove(-12.0));
  list.traverse();

  P("Remove first node");
  assert(list.remove(11.0));
  list.traverse();

  P("Remove 2");
  assert(list.remove(2.0));
  list.traverse();

  P("Insert 15");
  assert(list.insert(15.0));
  list.traverse();

  P("Remove 15");
  assert(list.remove(15.0));
  list.traverse();

  P("Remove 3");
  assert(list.remove(3.0));
  list.traverse();

  P("Remove 0, bad val");
  assert(list.remove(0) == false);

  P("Remove 9871.14");
  assert(list.remove(9871.142));
  list.traverse();

  return 0;
}
