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

struct MissingConnection {
  Server from;
  Server to;
  double volume_needed;
};

struct CommunicationRequirement {
  Server s1;
  Server s2;
  double volume_needed;
  double volume;
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

  void analyzeConnection(int s1, int s2, CommunicationDemand demand);
  void addMissingConnection(int s1, int s2, double volume_needed);

  int getIndexOfServer(Server s);
  ConnectionCost getConnection(Server s1, Server s2);

  Graph<Server, ConnectionCost> graph;
  std::vector<CommunicationDemand> demands;

  // array of connections that are not possible from a demand
  std::vector<MissingConnection> missingConnections;

  // array of connections to increase volume
  std::vector<CommunicationRequirement> connectionRequirements;

  std::string input_filename;
  std::string ouput_filename;
};
