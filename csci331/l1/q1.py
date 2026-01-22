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

    def convertFlatToRowWise(self, flat: list):
        rows = []
        i = 0
        rowSize = 1
        while i < len(flat):
            rows.append(flat[i : i + rowSize])
            i += rowSize
            rowSize += 1
        return rows

    def pyramidSum(self, pyramid):
        sum = 0
        for row in pyramid:
            for element in row:
                sum += element
        return sum

    def pyramidSplit(self, pyramid):
        l = []
        r = []

        for i in range(len(pyramid)):
            row = pyramid[i]
            l.extend(row[0:i])
            r.extend(row[1 : i + 1])

        lPyramid = self.convertFlatToRowWise(l)
        rPyramid = self.convertFlatToRowWise(r)

        return lPyramid, rPyramid

    def process(self) -> None:
        self.result += self.al[0][0]

        while len(self.al) > 1:
            l, r = self.pyramidSplit(self.al)
            if self.pyramidSum(l) < self.pyramidSum(r):
                self.al = r
            else:
                self.al = l

            self.result += self.al[0][0]

        print(self.al)

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
