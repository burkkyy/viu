# CSCI 331 - Lab 2
# Author: Caleb Burke
# Date: Jan 29th, 2026

from bs4 import BeautifulSoup
from pytictoc import TicToc
from typing import TextIO
import sys


class LabTwo:
    def readFile(self, fileName: str) -> BeautifulSoup:
        """
        Opens a text file, and returns a BeautifulSoup
        object from its contents
        parameters: filename as a string
        returns: BeautifulSoup object
        """

        try:
            with open(fileName) as f:
                xml = f.read()
                return BeautifulSoup(xml, "html.parser")
        except FileNotFoundError:
            print(f"ERROR: cannot open {fileName}")

    def getPlayName(self, soup: BeautifulSoup) -> str:
        """
        Returns the name of play obtained from parsing a
        BeautifulSoup object
        hint: you can use the the find() method of a
        BeautifulSoup object
        parameters: BeautifulSoup object
        returns: string
        """
        play = soup.find("play")
        return play.attrs["name"]

    def getCharacters(self, soup: BeautifulSoup) -> dict:
        """
        Returns a Python dictionary: Character names as
        keys, values are Python lists.
        Each item in the list corresponds to a scene and
        act where the character in the key appears.
        parameters: BeautifulSoup object
        returns: Python dictionary
        """
        characters = {}
        acts = soup.find_all("div", {"type": "act"})

        for act in acts:
            act_number = act.attrs["n"]
            scenes = act.find_all("div", {"type": "scene"})
            for scene in scenes:
                scene_number = scene.attrs["n"]
                dialogs = scene.find_all("sp")
                for dialog in dialogs:
                    if dialog.has_attr("who"):
                        name = dialog.attrs["who"][1::]
                        if name in characters:
                            characters[name].add((act_number, scene_number))
                        else:
                            characters[name] = {(act_number, scene_number)}
        return characters


if __name__ == "__main__":
    # DO NOT MODIFY THIS CODE
    t = TicToc()
    t.tic()  # start timer

    lab2 = LabTwo()
    f = lab2.readFile(sys.argv[1])
    if f:
        print("Play name:", lab2.getPlayName(f))
        print("Characters:")
        characters = lab2.getCharacters(f)
        if characters:
            for k, v in characters.items():

                print(k + ":", "".join([a + "." + b + " " for (a, b) in v]))

            print("*" * 13)

    t.toc()  # elapsed time
