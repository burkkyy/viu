#include <iostream>
#include "manager.hpp"

int main(int argc, const char** argv){
  (void) argc;
  (void) argv;
  std::cout << "#" << std::endl;
  
  try {
    job::Manager manager;
    
    manager.submit(0.1, 100, "echo 1", "");
    manager.submit(1.0, 100, "ls -al", "");
    manager.submit(10.0, 100, "printenv", "");
    manager.submit(0.1, 100, "su root", "");
    manager.submit(0.0, 100, "du -ahc", "");
    manager.printJobs();

    manager.execute();
    manager.lottery();
    manager.execute();
    manager.execute();
    manager.printJobs();

    manager.quit();
  } catch (const char* e){
    std::cout << e << std::endl;
  }

  return 0;
}
