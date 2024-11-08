#pragma once

#include <string>

#include "customer.hpp"
#include "binary_search_tree.hpp"

class Manager {
public:
  Manager();
  ~Manager();
  
  void subscribe(std::string email);
  void unsubscribe(CUSTOMER_ID id);
  void show(CUSTOMER_ID id);
  void list();
  void spam();
  void quit();

private:
  CUSTOMER_ID getId(){
    this->current_id++;
    return this->current_id;
  }

  int keyFromEmail(std::string email);

  CUSTOMER_ID current_id = 100001;
  BST<Customer> tree;
};
