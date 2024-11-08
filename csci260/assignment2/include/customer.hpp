#pragma once

#include <cstdint>
#include <string>

struct Customer {
  uint64_t id;
  std::string email;
  std::string name;
  bool active;
};
