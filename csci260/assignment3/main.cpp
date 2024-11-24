#include <iostream>

#include "analyzer.hpp"

/*
Pipeline

- (console) Get file name of infrastructure data from stdin
- Read infrastructure data and convert its contents to class variables
- Analyze the infrastructure data
- Identify any of the communication demands that can't be met by the current infrastructure due to lack of connected routes between the two servers listed in the demand.
- Excluding all the unrealizable demands identified in the previous task, if all the rest communication demands must be met with the lowest cost possible, can the current infrastructure handle them? If not, identify any direct link whose volume capacity must be expanded and calculate how much its volume capacity must be expanded, with the assumption that the unit cost of the link would remain the same after its capacity expansion.
- Dump analyze to techAnalysisResult.txt
*/

int main(int argc, const char** argv){
  (void) argc;
  (void) argv;

  if(argc < 3){
    std::cout << "Invalid args. Usage: " << std::endl;
    std::cout << "./pxe3 <INPUT FILENAME> <OUTPUT FILENAME>" << std::endl;
    return 0;
  }

  std::string input_filename = argv[1];
  std::string output_filename = argv[2];

  try {
    Analyzer a;
    a.read(input_filename);
    a.analyze();
    a.dump(output_filename);
  } catch (const char* e){
    std::cout << e << std::endl;
  }

  return 0;
}
