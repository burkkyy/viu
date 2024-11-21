#include "console.hpp"

#include <iostream>
#include <limits>

Console::Console(){
  initialize();
}

void Console::run(){
  std::string input;

  while(this->running){
    std::cout << "> ";
    std::getline(std::cin, input);

    this->execute(input);
  }
}

void Console::execute(const std::string& command){
  if(command.empty()){ return; }

  if(command == "help"){
    printHelp();
  } else if(command == "quit"){
    this->manager.quit();
    this->running = false;
  } else {
    std::cout << "Command not found." << std::endl;
  }
}

void Console::printHelp() {
  std::cout << "Available commands: " << std::endl;
  std::cout << "\tsubscribe\t\tsubscribe a new customer" << std::endl;
  std::cout << "\tshow\t\t\tdisplay information of a customer by ID" << std::endl;
  std::cout << "\tlist\t\t\tlist all customer IDs and names" << std::endl;
  std::cout << "\tspam\t\t\tlist emails and names of active customers" << std::endl;
  std::cout << "\tunsubscribe\t\tset customer status to inactive" << std::endl;
  std::cout << "\tquit\t\t\texit the program" << std::endl;
}

void Console::initialize(){
  printHelp();
}
