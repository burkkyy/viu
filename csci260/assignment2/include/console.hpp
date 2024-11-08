#pragma once

#include <string>

#include "manager.hpp"

class Console { 
public:
  Console(const Console&) = delete;
  Console& operator=(const Console&) = delete;

  Console();

  void run();

private:
  void initialize();
  void execute(const std::string& command);
  void printHelp();
  
  /* 
    Wrappers for manager.
    This is done so console input is proccessed 
    so it can be passed to manager
  */
  void subscribeWrapper();
  void unsubscribeWrapper();
  void showWrapper();
  void listWrapper();
  void spamWrapper();

  Manager manager;
  bool running = true;
};
