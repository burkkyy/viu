#include <iostream>

#include "console.hpp"

int main(int argc, const char** argv){
  (void) argc;
  (void) argv;
  
  try {
    job::Console console;

    console.run();
    
  } catch (const char* e){
    std::cout << e << std::endl;
  }

  return 0;
}
