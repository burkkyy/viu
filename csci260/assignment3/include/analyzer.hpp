#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "graph.hpp"

struct Server {
  std::string name;
  // other data such as server location

  bool operator==(const Server& s) const {
    return name == s.name;
  }

  friend std::ostream& operator<<(std::ostream& os, const Server& s){
    os << s.name;
    return os;
  }
};

struct ConnectionCost {
  double cost;
  double volume;

  double get() const {
    return cost;
  }
};

struct CommunicationDemand {
  Server s1;
  Server s2;
  double volume_needed;
};

class Analyzer {
public:
  void read(const std::string& filename);
  void dump(const std::string& filename);
  void analyze();

private:
  void createServer(const std::string& name);
  void createConnectionCost(const std::string& s1, const std::string& s2, double cost, double volume);
  void createCommunicationDemand(const std::string& s1, const std::string& s2, double volume_needed);

  Graph<Server, ConnectionCost> graph;
  std::vector<CommunicationDemand> demands;

  std::string input_filename;
  std::string ouput_filename;
};
