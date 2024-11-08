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
  void submitWrapper();

  Manager manager;
  bool running = true;
};
