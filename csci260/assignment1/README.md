# CSCI 260 Assignment 1

## Specification

Program should take user input to create/store jobs with the following functionality:

- submit: to submit a new job request. Your program should ask for the job's time, its estimated execution time, its user id, its command name and a line to describe the resources the job requires. Then your program should insert the job into the job queue.
  Your program can give your job queue a pre-defined capacity. If the job queue is full when a new job request is submitted, the new submission should be denied its service with an explanation.

- execute: to remove the job with the highest priority from the job queue to be executed. To simulate the execution of a job, your program simply displays the job's information. If the job queue is empty when this command is entered, your program should show an appropriate message.

- lottery: to randomly remove a lucky job from the job queue to be executed. This command is designed to give the long and/or user jobs a chance to be executed earlier than its priority warrents.

- quit: to terminate your program. Before the termination, your program should empty the job queue by removing them one by one as a simulation of forcibly killing all uncompleted jobs.

(copied from http://csci.viu.ca/~liuh/260/assignments/pex1.html)

## Design

I choose to break compenents of the program into different classes. For example user input is required, so a `Console` class was written.

Definitions for classes are found in `include/`, implementation for classes are found in `src/`

Other classes:

- `PriorityQueue` - General non-type dependant implementation of a priority queue via a min-heap
- `Job` - Object for storing information and helper functions related to creating/storing/executing jobs
- `Manager` - Implements the functions defined in the assignment requirements. This is done with the help of `Job` and `PriorityQueue`
- `Console` - frontend of program / handles user input which is handed off to `Manager`

## Implementation

- One downside to my implementation is priorities are bounded to 0 - 10. This is not very flexiable in general practice.

## Analysis

### submit

Code found in `src/manager.cpp:44`

```cpp
void Manager::submit(...){
  // calculate priority
  uint32_t priority = calculatePriority(uid, estimated_execution_time);

  if(queue.insert(priority, {...})){...}
}
```

- `calculatePriority()` runs in O(1)

Code for `queue.insert()` found in `src/priority_queue.cpp:32`.

See comments below for time complexity for each step

```cpp
bool PriorityQueue<T>::insert(uint32_t key, T value){
  if(this->isFull()){
    return false;
  } // O(1)

  this->data.push_back({key, value}); // O(1)
  this->size++; // O(1)

  int i = this->size - 1; // O(1)

  // we bubble up to the spot the key should go, worst case is
  // the height of the tree which is log N. Therefore O(log n)
  while(i != 0 && this->data[i] < this->data[(i - 1) / 2]){
    std::swap(this->data[i], this->data[(i - 1) / 2]);
    i = (i - 1) / 2;
  }

  return true;
}
```

Longest operation is O(log n), therefore time complexity for insert is O(log n)

### execute

This function is found in `src/manager.cpp:55`.

```cpp
void Manager::execute(){
  *** snip ***

    Job removedJob = queue.removeMin();

  *** snip ***
}
```

Looking into `queue.removeMin()` in `src/priority_queue.cpp:100`

```cpp
template<typename T>
T PriorityQueue<T>::removeMin(){
  ** snip **

  T copy = this->data.front().value; // O(1)
  std::swap(this->data[0], this->data[this->size - 1]); // O(1)

  this->data.pop_back(); // O(1)
  this->size--; // O(1)

  // ensure min heap
  this->heapify(0);

  return copy;
}
```

Looking at `queue.heapify` in `src/priority_queue.cpp:132`

```cpp
template<typename T>
void PriorityQueue<T>::heapify(int i){
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int min = i;

  if(left < this->size && this->data[left] < this->data[min]){
    min = left;
  } // O(1)

  if(right < this->size && this->data[right] < this->data[min]){
    min = right;
  } // O(1)

  if(min != i){
    std::swap(this->data[i], this->data[min]); // O(1)

    heapify(min);
  }
}
```

At each call of `heapity()`, worst case it gets called to the last level of the tree. The height of the tree is log n, n is number of elements. Therefore time complexity is O(log n)

### lottery

This function is found in `src/manager.cpp:44`.

```cpp
void Manager::lottery(){
  ** snip **

    Job removedJob = queue.removeIndex(randomIndex);
    std::cout << "Executing random job..." << std::endl;
    removedJob.execute();

  ** snip **
}
```

Looking at `queue.removeIndex` in `src/priority_queue.cpp:65`

```cpp
T PriorityQueue<T>::removeIndex(int index){
  ** snip **

  this->data[index].key = 0;

  // while loop is at most each level of the tree. Height is log n for n=number of elements therefore this while loop is O(log n)
  while (index > 0 && this->data[index].key <= this->data[(index - 1) / 2].key){
    std::swap(this->data[index], this->data[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
  return this->removeMin(); // already stated as O(log n)
}
```

Longest operation is O(log n), therefore time complexity for lottery is O(log n).

## Accomplishment

- program compilies with zero errors or warnings
- console for user interaction with the adt
- submit functionalty
- execute functionalty
- lottery functionalty
- quit functionalty
- priority queue with insert O(log n)
- priority queue with removeMin O(log n)
- each job in the queue is an object with the properties job type, estimated execution time, uid, command name and a resource list

## Testing

todo

## Know Bugs

- negative values should not be accepted, even though it does not produce undefined behaviour
- On submit command, the console could be cleaner and have better user input validation i.e. spaces, new line

## Note

- job type is implicit from job uid (<1000 system)

## Authors

Caleb Burke
