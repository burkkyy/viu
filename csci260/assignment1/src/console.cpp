/*
*
* TODO write doc
*
*/
#include "console.hpp"

#include <iostream>
#include <limits>

namespace job {

Console::Console(){
  initialize();
}

Console::~Console(){

}

void Console::run(){
  std::string input;

  while(this->running){
    std::cout << "> ";
    std::getline(std::cin, input);

    this->runCommand(input);
  }
}

void Console::runCommand(const std::string& command){
  if(command.empty()){ return; }

  if(command == "help"){
    printHelp();
  } else if(command == "submit"){
    this->submitWrapper();
  } else if(command == "execute"){
    this->manager.execute();
  } else if(command == "lottery"){
    this->manager.lottery();
  } else if(command == "print"){
    this->manager.printJobs();
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

void Console::submitWrapper(){
  double estimated_execution_time = 0.0;
  uint16_t uid = 0;
  std::string command_name;
  std::string resource_list;

  std::cout << "Job submit console, input the following:" << std::endl;
  std::cout << "\tEstimated execution time(S): "; std::cin >> estimated_execution_time;
  std::cout << "\tUID (1000 user, <1000 for system): "; std::cin >> uid;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  std::cout << "\tCommand name: ";
  std::getline(std::cin, command_name);
  std::cout << "\tResource list: ";
  std::getline(std::cin, resource_list);

  std::cout << "Submitting job..." << std::endl;

  this->manager.submit(estimated_execution_time, uid, command_name, resource_list);
}

void Console::initialize(){
  printHelp();
}

}  // namespace job
