/** 
*
*
*/
#pragma once

#include "manager.hpp"

#include <string>

namespace job {

class Console { 
public:
  Console(const Console&) = delete;
  Console& operator=(const Console&) = delete;

  Console();
  ~Console();

  void run();

private:
  void initialize();
  void runCommand(const std::string& command);
  void printHelp();
  void submitWrapper();

  Manager manager;
  bool running = true;
};

} // namespace job
