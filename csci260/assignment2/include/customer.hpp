#pragma once

#include <iostream>
#include <cstdint>
#include <string>

using CUSTOMER_ID = uint64_t;

struct Customer {
  CUSTOMER_ID id;
  std::string email;
  std::string name;
  bool active;
};
