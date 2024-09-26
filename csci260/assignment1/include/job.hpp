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

  Job(double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list);
  ~Job();

  Job(const Job& other)
    : level(other.level),
      estimated_execution_time(other.estimated_execution_time),
      uid(other.uid),
      priority(other.priority),
      command_name(other.command_name),
      resource_list(other.resource_list) {}

  Job& operator=(const Job& other) {
    if (this == &other) {
      return *this;
    }

    this->level = other.level;
    this->estimated_execution_time = other.estimated_execution_time;
    this->uid = other.uid;
    this->priority = other.priority;
    this->command_name = other.command_name;
    this->resource_list = other.resource_list;

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
  double priority;
  std::string command_name; // ???
  std::string resource_list; // ???
};

} // namespace job
