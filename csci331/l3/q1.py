# CSCI 331 - Lab 3
# Author: Caleb Burke
# Date: Feb 17th, 2026

from nltk.tokenize import wordpunct_tokenize
from pytictoc import TicToc
import sys
import random

class Lab3(dict):
    def __setitem__(self, key, value) -> None:
        super().__setitem__(key, self.get(key, list()) + [value])

    def clear(self) -> None:
        super().clear()
        print("*+* Erasing data... *+*")

    def topKeys(self, number: int = 100) -> list:
        top_keys = []
        
        for k in self.keys():
            if len(self[k]) >= number:
                for i in self[k]:
                    if i > number:
                        top_keys.append(k)
                        break
        return top_keys

if __name__ == '__main__':
    #DO NOT MODIFY THIS CODE
    t = TicToc()
    t.tic() # start timer
    
    NCHAR = 5
    CHOICES = 10
    STOPWORDSFILE = 'txts/stopwords.txt'

    try:
        f = open(STOPWORDSFILE, 'r')
    except OSError:
        print('ERROR: cannot open', fn)
    else:
        stopWords = [line.strip() for line in f.readlines()]
        f.close()

    try:
        fn = sys.argv[1]
        f = open(fn, 'r')
    except OSError:
        print('ERROR: cannot open', fn)
    else:
        al = [wordpunct_tokenize(line) for line in f.readlines()]
        f.close()    

        if al:
            lab3 = Lab3()

            for counter, line in enumerate(al):
                for item in line:
                    if item not in stopWords and len(item) > NCHAR:
                        lab3[item] = counter

            if lab3.keys():
                print('***** Sample entries: *****')   
                for k in random.choices(list(lab3.keys()), k=CHOICES):
                    print(k, lab3[k])

                print('***** Top Keys: *****')
                tk = lab3.topKeys(100)
                for tt in tk:
                    print(tt, len(lab3[tt]))

            lab3.clear()
            print(lab3)

    t.toc() #elapsed time
    print('*' * 13)
