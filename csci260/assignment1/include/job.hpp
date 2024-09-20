/** 
*
*
*/
#pragma once

#include <iostream>
#include <string>
#include <cstdint>

namespace job {

class Job { 
public:
  enum class Level {
    SYSTEM,
    USER,
  };

  Job(const Job&) = delete;
  Job& operator=(const Job&) = delete;

  Job(double time, double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list);
  ~Job();

  void print() const;

private:
  void initialize();
  std::string json() const;

  Level level;
  double estimated_execution_time;
  uint16_t uid;
  double priority;
  std::string command_name; // ???
  std::string resource_list; // ???
};

} // namespace job

