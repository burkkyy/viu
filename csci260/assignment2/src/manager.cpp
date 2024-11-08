#include "manager.hpp"

Manager::Manager(){

}

Manager::~Manager(){
  
}

/*
a new customer subscription with given customer email and customer name
your program should assign a unique customer ID to this new customer; the 
customer ID starts from 100001 the new customer's status is set to active 
*/
void Manager::subscribe(std::string email){
  Customer newCustomer;
  newCustomer.id = getId();
  newCustomer.email = email;
  newCustomer.active = true;

  int key = keyFromEmail(email);
  
  tree.insert(key, newCustomer);
}

/*
change the status of the customer with the given parameter customer ID 
123456 from active to inactive
*/
void Manager::unsubscribe(CUSTOMER_ID id){
  throw "Not Implemented";
}

/*
display ALL information about the customer with the given parameter 
customer ID 123456
*/
void Manager::show(CUSTOMER_ID id){
  throw "Not Implemented";
}

/*
list the customer ID and name ONLY of ALL customers in ascending order 
of the customer ID
*/
void Manager::list(){
  throw "Not Implemented";
}

/*
list the email and name ONLY of ALL customers whose status is active in 
ascending order of the customer email
*/
void Manager::spam(){
  tree.inorder();
}

/*
quit the program and abandon all the information stored in your program.
Remember to clean up the dynamically allocated memory space
*/
void Manager::quit(){
  std::cout << "Cleaned out customers" << std::endl;
  // done in destructors
}

int Manager::keyFromEmail(std::string email){
  int key = 0;
  const int prime = 7;

  for (auto c : email){
    key = key * prime + static_cast<int>(c);
  }

  return key;
}
