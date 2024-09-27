/*
*
* TODO write doc
*
*/
#include "manager.hpp"

#include <algorithm>

namespace job {

Manager::Manager(){
  initialize();
}

Manager::~Manager(){

}

void Manager::printJobs() const {
  queue.traverse();
}

uint32_t Manager::calculatePriority(uint16_t uid, double estimated_execution_time){
  // these values are purely arbitrary
  const int MIN_PRIORITY = 0;
  const int MAX_PRIORITY = 10;
  const int BASE_PRIORITY = (MAX_PRIORITY + MIN_PRIORITY) / 4;

  // linear interpolation 
  double time_priority = MIN_PRIORITY + estimated_execution_time * (MAX_PRIORITY - MIN_PRIORITY);

  int priority = static_cast<int>(time_priority);

  // uid < 1000 => system user, therefore decrease priority
  uid < 1000 ? priority -= BASE_PRIORITY : priority += BASE_PRIORITY;

  // assure min <= priority <= max (non negative)
  priority = std::clamp(priority, MIN_PRIORITY, MAX_PRIORITY);

  return static_cast<uint32_t>(priority);
}

void Manager::submit(double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list){
  // ask for input?

  // calculate priority
  uint32_t priority = calculatePriority(uid, estimated_execution_time);
  
  if(queue.insert(priority, {estimated_execution_time, uid, command_name, resource_list, priority})){
    std::cout << "Inserted new job with priority " << priority << std::endl;
  } else {
    std::cout << "Job queue is full. Insert failed." << std::endl;
  }
}

void Manager::execute(){
  if(queue.isEmpty()){
    std::cout << "Job queue is empty. Ignoring execute..." << std::endl;
    return;
  }

  try {
    Job removedJob = queue.removeMin();
    std::cout << "Executing highest priority job..." << std::endl;
    removedJob.execute();
    return;
  } catch(...){
    std::cout << "An Error has ocurred while removing job!" << std::endl;
  }
}

void Manager::lottery(){
  srand(time(0));

  uint32_t length = queue.length();  
  if(length <= 0){
    std::cout << "Job queue is empty. Ignoring lottery..." << std::endl;
    return;
  }

  int randomIndex = rand() % length;
  std::cout << "Executing " << randomIndex << std::endl;

  try {
    Job removedJob = queue.removeIndex(randomIndex);
    std::cout << "Executing random job..." << std::endl;
    removedJob.execute();
  } catch(...){
    std::cout << "An Error has occurred while removing a random job!" << std::endl;
  }
}

void Manager::quit(){
  std::cout << "Executing remaining jobs before quit." << std::endl;
  std::cout << queue.length() << std::endl;
  for(int i = 0; i <= queue.length(); i++){
    this->execute();
  }

  std::cout << "Quiting..." << std::endl;
}

void Manager::initialize(){

}

}  // namespace job
