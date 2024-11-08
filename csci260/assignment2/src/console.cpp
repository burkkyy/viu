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
  } else if(command == "subscribe"){
    this->manager.subscribe();
  } else if(command == "unsubscribe"){
    this->manager.unsubscribe();
  } else if(command == "show"){
    this->manager.show();
  } else if(command == "list"){
    this->manager.list();
  } else if(command == "spam"){
    this->manager.spam();
  } else if(command == "quit"){
    this->manager.quit();
    this->running = false;
  } else {
    std::cout << "Command not found." << std::endl;
  }
}

void Console::printHelp(){
  std::cout << "Available commands: " << std::endl;
  std::cout << "\tsubmit\t\topens console to submit a new job to queue" << std::endl;
  std::cout << "\texecute\t\truns highest priority job" << std::endl;
  std::cout << "\tlottery\t\truns random job" << std::endl;
  std::cout << "\tprint\t\tprints out all jobs" << std::endl;
  std::cout << "\tquit\t\texits program" << std::endl;
  std::cout << "\thelp\t\tprints this message" << std::endl;
}

void Console::initialize(){
  printHelp();
}
