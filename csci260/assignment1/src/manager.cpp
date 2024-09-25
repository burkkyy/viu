/*
*
* TODO write doc
*
*/
#include "manager.hpp"

namespace job {

Manager::Manager(){
    initialize();
}

Manager::~Manager(){
    
}

void Manager::print_jobs() const {
    queue.traverse();
}

void Manager::submit(double time, double estimated_execution_time, uint16_t uid, std::string command_name, std::string resource_list){
    // ask for input?

    // calculate priority
    uint32_t priority = 0.0f;
    if(queue.insert(priority, {time, estimated_execution_time, uid, command_name, resource_list})){

    } else {
        std::cout << "Insert into job queue failed.";
    }
    throw "Not implemented";
}

void Manager::execute(){
    if(queue.isEmpty()){
        std::cout << "Queue is empty. Ignoring execute..." << std::endl;
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
    uint32_t length = queue.length();  
    if(length <= 0){
        std::cout << "Queue is empty. Ignoring execute..." << std::endl;
        return;
    }

    int randomIndex = rand() % length;

    try {
        Job removedJob = queue.removeIndex(randomIndex);
        std::cout << "Executing random job..." << std::endl;
        removedJob.execute();
    } catch(...){
        std::cout << "An Error has occurred while removing a random job!" << std::endl;
    }
}

void Manager::quit(){
    throw "Not implemented";
}

void Manager::initialize(){
    throw "Not implemented";
}

}  // namespace job
