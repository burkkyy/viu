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

  Job(double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list, uint32_t priority);
  ~Job();

  Job(const Job& other)
    : level(other.level),
      estimated_execution_time(other.estimated_execution_time),
      uid(other.uid),
      command_name(other.command_name),
      resource_list(other.resource_list),
      priority(other.priority) {}

  Job& operator=(const Job& other) {
    if (this == &other) {
      return *this;
    }

    this->level = other.level;
    this->estimated_execution_time = other.estimated_execution_time;
    this->uid = other.uid;
    this->command_name = other.command_name;
    this->resource_list = other.resource_list;
    this->priority = other.priority;

    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Job& job) {
    os << job.json();
    return os;
  }

  void execute(){ this->print(); }
  std::string json() const;

private:
  void initialize();
  void print() const;

  Level level;
  double estimated_execution_time;
  uint16_t uid;
  std::string command_name; // ???
  std::string resource_list; // ???
  uint32_t priority;
};

} // namespace job
