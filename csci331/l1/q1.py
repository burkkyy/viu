# CSCI 331 - Lab 1
# Author: Caleb Burke
# Date: January 21, 2026

from pytictoc import TicToc
import sys


class LabOne:
    al = []  # all lines
    result = 0

    def readFile(self, fn: str) -> None:
        lines = ""
        with open(fn, "r") as f:
            lines = f.readlines()

        for line in lines:
            arr = line.strip().split()
            row = []
            for i in arr:
                row.append(int(i))
            self.al.append(row)

        print(self.al)

    def process(self) -> None:
        for i in range(len(self.al) - 2, -1, -1):
            for j in range(len(self.al[i])):
                self.al[i][j] += max(self.al[i+1][j], self.al[i+1][j+1])
        self.result = self.al[0][0]

    def getResult(self) -> int:
        return self.result


if __name__ == "__main__":
    # DO NOT MODIFY THIS CODE
    t = TicToc()
    t.tic()  # start timer

    solution = LabOne()
    solution.readFile(sys.argv[1])
    if solution.al:
        solution.process()

    print("*" * 7)
    print("*" * 13)
    print(solution.getResult())
    t.toc()  # elapsed time
    print("*" * 13)
