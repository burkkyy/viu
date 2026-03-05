# CSCI 331 - Lab 4
# Author: Caleb Burke
# Date: March 4th, 2026

from collections import UserList
from pytictoc import TicToc
import sys
import random


# WRITE YOUR CODE HERE
class Lab4(UserList):
    def repeat(self, n: int) -> None:
        c = super().copy()
        for i in range(n):
            super().extend(c)

    def add(self, x) -> None:
        super().append(x)

    def remove(self, m: int, n: int) -> None:
        self.data[m:n] = []

    def concat(self, x: list) -> None:
        super().extend(x)

    def depth(self, l) -> int:
        max_depth = 0
        for ele in l:
            if isinstance(ele, UserList):
                current_depth = ele.depth(ele) + 1
            else:
                current_depth = 1

            if current_depth > max_depth:
                max_depth = current_depth

        return max_depth


if __name__ == "__main__":
    # DO NOT MODIFY THIS CODE

    R1 = 0
    R2 = 100

    t = TicToc()
    t.tic()  # start timer

    l4 = Lab4([random.randint(R1, R2) for r in range(4)])

    print("Test 0 - initial state:")
    print(l4)

    print("Test 1 - repeat():")
    l4.repeat(2)
    print(l4)

    print("Test 2 - add():")
    l4.add(random.randint(R1, R2))
    l4.add(random.randint(R1, R2))
    print(l4)

    print("Test 3 - remove():")
    l4.remove(5, 8)
    print(l4)

    print("Test 4 - concat():")
    l4.concat(Lab4([random.randint(R1, R2) for r in range(3)]))
    print(l4)

    print("Test 5 - depth():")
    l4.add(Lab4([random.randint(R1, R2) for r in range(2)]))
    n1 = random.randint(R1, R2)
    l4.add(Lab4([Lab4([random.randint(R1, R2) for r in range(1)]), n1]))
    print(l4)
    print("depth:", l4.depth(l4.data))

    t.toc()  # elapsed time
    print("*" * 13)
