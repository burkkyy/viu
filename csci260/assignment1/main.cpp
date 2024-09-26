#include <iostream>
#include "manager.hpp"

int main(int argc, const char** argv){
  (void) argc;
  (void) argv;
  std::cout << "#" << std::endl;
  
  try {
    job::Manager manager;
    
    manager.submit(0.8, 1000, "echo 1", "");
    manager.printJobs();

    manager.submit(0.3, 1000, "ls -al", "");
    manager.printJobs();

    manager.submit(0.8, 1000, "printenv", "");
    manager.printJobs();

    manager.submit(0.5, 0, "su root", "");
    manager.printJobs();

    manager.submit(1.0, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.8, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.7, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.6, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.9, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.8, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.0, 200, "du -ahc", "");
    manager.printJobs();

    manager.submit(0.1, 200, "du -ahc", "");
    manager.printJobs();

    manager.execute();
    manager.printJobs();

    manager.execute();
    manager.printJobs();

    manager.execute();
    manager.printJobs();

    manager.lottery();
    manager.printJobs();

    manager.lottery();
    manager.printJobs();

    manager.lottery();
    manager.printJobs();

    manager.lottery();
    manager.printJobs();

    manager.lottery();
    manager.printJobs();
    
    manager.quit();
  } catch (const char* e){
    std::cout << e << std::endl;
  }

  return 0;
}
