# CSCI 260 Written Assignment 1

## Author

Caleb Burke

## 1.

Given a binary tree, where each of its tree node has the following struct TreeNode type:

```cpp
struct TreeNode {
    int key;
    Data * data;
    TreeNode *left;
    TreeNode *right;
};
```

Write a C++ function style algorithm to check whether this binary tree is an AVL tree where in-order traversal list the keys sorted from the smallest to the largest.

**Soln**

```cpp

int getHeight(TreeNode* root){
    if(root){
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return 1 + l < r ? r : l;
    }
    return 0;
}

bool isAVLTree(TreeNode *root){
    if(root->left){
        // ensure left subtree is valid
        bool ret = isAVLTree(root->left);

        if(!ret || root->left->key > root->key){
            return false;
        }
    }

    if(root->right){
        // ensure right subtree is valid
        bool ret = isAVLTree(root->right);

        if(!ret || root->right->key <= root->key){
            return false;
        }
    }

    // ensure subtrees height differences is <=1
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if(std::abs(lh - rh) > 1){ return false; }

    // if we are here, all checks passed or root has no children or root is nullptr (still valid AVL)
    return true;
}
```

## 2.

Suppose you are given an array A that contains N unique integer numbers in the range of [0..N] in sorted order (from smallest to largest). Note that there must be one number in the range [0..N] that is not in the array A.
Write a C++ function style algorithm that can find the missing integer (the integer that is not in array A) in Θ(logN) time.

**Soln**

```cpp
int findMissing(int* A, int N){
    int l = 0, r = N;

    while(l < r){
        int mid = l + (r - l) / 2;

        // mid point index matches A at mid, this means the left hand side from l up to mid is correct.
        // Therefore the missing index is on the right side, so move left side since missing is inbetween index mid + 1 and N - 1
        if(A[mid] == mid){
            l = mid + 1;
        // mid point does not match expected value. The single missing element somewhere inbetween l and mid in A is causing
        // elements to be one larger then expected from index l to N - 1.
        // Therefore the missing element is on left side, so move r to mid since missing is inbetween l and mid.
        } else {
            r = mid;
        }
    }

    // here l == r which is the missing point in question where index 0 to l - 1 are their expected value and index l to N - 1 is one
    // larger then expected value. Index l is first occorence of one larger then ecpected value therefore mssing point is at index l
    return l;
}
```

## 3.

Given the following strings and their corresponding hash codes, draw the resulting 13-cell hash table by inserting these strings in the given order to the hash table and using linear probing to resolve (possible) collisions.

string hash code
brute 10
force 11
greedy 7
backtracking 10
dynamic 7
programming 8
abstract 0
methodology 9

**Soln**

N = 13

Index = hash code (mod N)

| string       | hash code | Index                                                     |
| ------------ | --------- | --------------------------------------------------------- |
| brute        | 10        | 10 (mod 13) = 10                                          |
| force        | 11        | 11 (mod 13) = 11                                          |
| greedy       | 7         | 7 (mod 13) = 7                                            |
| backtracking | 10        | 10 (mod 13) = 10, collision with 10 and 11, next=12       |
| dynamic      | 7         | 7 (mod 13) = 7, collision with 7, next=8                  |
| programming  | 8         | 8 (mod 13) = 8 collision with 8, next=9                   |
| abstract     | 0         | 0 (mod 13) = 0                                            |
| methodology  | 9         | 9 (mod 13) = 9 collision with 8, 9, 10, 11, 12, 0, next=1 |

| Index | string       |
| ----- | ------------ |
| 0     | abstract     |
| 1     | methodology  |
| 2     |              |
| 3     |              |
| 4     |              |
| 5     |              |
| 6     |              |
| 7     | greedy       |
| 8     | dynamic      |
| 9     | programming  |
| 10    | brute        |
| 11    | force        |
| 12    | backtracking |

## 4.

Find a Ο characterization of the running time for the function shown below. Explain briefly how you reached your conclusion, including how you choose the problem size to perform the analysis.

```cpp
// one layer neural network forward calculation;
// there are M neurons in the previous layer, and
// inputs[M] are the M outputs from these M neurons respectively;
// there are N neurons in the current layer;
// the purpose of this function is to calculate the output
// of each of the neurons in the current layer
Algorithm AIForward
    (double weights[M][N], double inputs[M], double outputs[N], int M, int N)
{
    for (int i = 0; i < N; i++) {
        p = 0
        for (int j = 0; j < M; j++) {
            p = p + weight[j][i] * inputs[j]
        }
        outputs[i] = 1/(1+pow(e, -p));
    }
}
```

**Soln**
Outter loop itters from 0 to N - 1, which is `O(N)` time. At each step of outer loop, inner loop itters from 0 to M - 1, which is `O(M)` time. This means overall time complexity is `O(N) * O(M)`. Therefore this function runs in `O(MN)` time.

## 5.

Consider the following recurrence equation that defines T(N) as
T(N) = 2, if N = 1
T(N) = 2T(N-1) + 2, otherwise.
Prove, by induction, that T(N) = 2^(N+1) - 2.

**Soln**

## 6.

Consider the following recurrence equation, defining T(N), as
T(N) = 2, if N = 1
T(N) = T(N-1) + 2N, otherwise.
Solve this recurrence equation and prove your solution by induction.

**Soln**

## 7.

Characterize each of the following recurrence equations using the master theorem (assuming that T(N) = c for N <= d, for constants c > 0, and d >= 1). Explain your reasons briefly.
a. T(N) = 2T(N/2) + 100
b. T(N) = 2T(N/2) + N
c. T(N) = 6T(N/3) + N^2
d. T(N) = 4T(N/2) + (NlogN)^3
e. T(N) = T(N/2) + (log^2)N
f. T(N) = 8T(N/2) + (N^2)logN

**Soln**
