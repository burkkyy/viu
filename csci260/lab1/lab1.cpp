#include <iostream>
#include <vector>

#define P(x) std::cout << x << std::endl

template<typename T>
void print_array(T* A, int size, const char* name = "Array"){
  for(int i = 0; i < size; i++){
    std::cout << name << "[" << i << "] = " << A[i] << std::endl;
  }
}

void compare_solns(int S1[], int S2[], int size1, int size2){
  if(size1 != size2){
    P("Array sizes are not the same.");
    return;
  }

  bool same = true;
  for(int i = 0; i < size1; i++){
    if(S1[i] != S2[i]){
      P("Error found at " << i);
      P("\t" << S1[i] << " " << S2[i]);
      same = false;
    }
  }
  
  if(same){
    P("Array comparison passed.");
  } else {
    P("Array comparison failed.");
    throw 1;
  }
}

/*
 * Time complexity: O(n log n)
 */
void quadratic_soln(double X[], int size, int S[]){
  for(int i = 0; i < size; i++){  
    S[i] = 0;
    //P(i << " " << X[i]);
    for(int j = i + 1; j < size; j++){
      //P("\t" << j << " " << X[j]);
      if(X[j] <= X[i]){ 
        S[i]++; 
      } else {
        break;
      }
    } 
  }
}

/* 
 * Linear span soln.
 *
 * This soln is O(N) because we itter over input array of size N, and each element is only pushed onto stack once
 * and popped off of stack once.
 * 
 * Procedure:
 * 1. Let stack be a stack, X be input array, and S be soln array
 * 2. Loop over X. Let i be each index.
 *  i. If the stack is not empty and X[stack.top] < X[i], Then
 *    - S[stack.top] = i - stack.top - 1 (minus 1 because we dont count element in question for span)
 *    - pop an element off of stack
 *    - Repeat i. until we dont perform pop step
 *  ii. Push i onto stack
 * 3. Pop all elements off of stack until empty, before each pop perform:
 *  - S[stack.top] = i - stack.top - 1 (minus 1 because we dont count element in question for span)
 * 
 * NOTE last element of S should always be 0
 */
void linear_soln(double X[], int size, int S[]){
  std::vector<int> stack;

  for(int i = 0; i < size; i++){
    if(!stack.empty()){
      int index = stack.back();
      while(!stack.empty() && X[index] < X[i]){
        S[index] = i - index - 1;
        stack.pop_back();
        index = stack.back();
      }
    }

    stack.push_back(i);
    //for(auto j : stack) { std::cout << j << " "; } std::cout << std::endl;
  }

  while(!stack.empty()){
    int index = stack.back();
    S[index] = size - index - 1;
    stack.pop_back();
  }
}

void calculate_span(double X[], int size){
  int* S1 = new int[size];
  int* S2 = new int[size];

  P("Input Array: ");
  print_array(X, size, "X");

  P(">>>>>>>>>> Quadratic soln");
  quadratic_soln(X, size, S1);
  P("--- Results --- ");
  print_array(S1, size, "S");
  P("<<<<<<<<<<");

  P(">>>>>>>>>> Linear Soln");
  linear_soln(X, size, S2);
  P("--- Results --- ");
  print_array(S2, size, "S");
  P("<<<<<<<<<<");

  compare_solns(S1, S2, size, size);

  delete[] S1;
  delete[] S2;
}

int main(int argc, const char** argv){
  (void)argc;
  (void)argv;

  int size1 = 4;
  double* X1 = new double[size1];

  X1[0] = 3;
  X1[1] = 4;
  X1[2] = 3;
  X1[3] = 2;

  calculate_span(X1, size1);
  delete[] X1;

  int size2 = 10;
  double* X2 = new double[size2];

  X2[0] = 0;
  X2[1] = 1;
  X2[2] = 1;
  X2[3] = 3;
  X2[4] = 10;
  X2[5] = 8;
  X2[6] = 9;
  X2[7] = 8;
  X2[8] = 7;
  X2[9] = 3;

  calculate_span(X2, size2);
  delete[] X2;

  int size3 = 9;
  double* X3 = new double[size3];

  X3[0] = 11;
  X3[1] = 1;
  X3[3] = 0;
  X3[3] = 0;
  X3[4] = 1;
  X3[5] = 0;
  X3[6] = 2;
  X3[7] = 1;
  X3[8] = 1;

  calculate_span(X3, size3);
  delete[] X3;
  
  return 0;
}

