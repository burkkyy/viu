#include <iostream>
#include "job.hpp"

int main(int argc, const char** argv){
  (void) argc;
  (void) argv;
  std::cout << "#" << std::endl;
  job::Job j;
  j.print();
  return 0;
}

