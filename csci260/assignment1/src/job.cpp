/**
*
*
*/
#include "job.hpp"

#include <sstream>

namespace job {

Job::Job(double time, double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list) : estimated_execution_time(estimated_execution_time), uid(uid), command_name(command_name), resource_list(resource_list) {
  initialize(); 
}


Job::~Job(){

}

void Job::initialize(){

}

void Job::print() const {
  std::cout << ">>>>>>>>>>" << std::endl;
  std::cout << this->json();
  std::cout << "<<<<<<<<<<" << std::endl;
}

std::string Job::json() const {
  auto level_to_string = [this](){
    switch(this->level){
      case Level::SYSTEM: return "system";
      case Level::USER: return "user";
      default: return "null";
    }
  };

  std::stringstream buffer;
  buffer << "Job {\n\tLevel: " << level_to_string() << ",\n\tUID: " << this->uid << ",\n\tEstimated Execution time (S): " << this->estimated_execution_time << ",\n\tPriority: " << this->priority << ",\n\tCommand Name: \"" << this->command_name << "\",\n\tResource List: \"" << this->resource_list << "\"\n}\n";
  return buffer.str();
}

} // namespace job

