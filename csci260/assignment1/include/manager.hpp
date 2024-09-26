/** 
*
*
*/
#pragma once

#include <iostream>
#include <cstdint>

#include "job.hpp"
#include "priority_queue.hpp"

namespace job {

class Manager { 
public:
  Manager(const Manager&) = delete;
  Manager& operator=(const Manager&) = delete;

  Manager();
  ~Manager();

  void printJobs() const;

  void submit(double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list);
  void execute();
  void lottery();
  void quit();

private:
  void initialize();

  adt::PriorityQueue<Job> queue;
};

} // namespace job
