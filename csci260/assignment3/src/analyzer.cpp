#include "analyzer.hpp"

#include <fstream>

void Analyzer::read(const std::string& filename){
  this->input_filename = filename;

  std::ifstream f(filename);
  if(!f.is_open()){
    throw "Failed to open file";
  }

  std::string dummy;

  // Read servers
  int servers_len = 0;
  f >> servers_len;
  std::getline(f, dummy);

  for(int i = 0; i < servers_len; i++){
    std::string server_name;
    std::getline(f, server_name);

    if(server_name.empty()){
      throw "Empty server name";
    }
    
    createServer(server_name);
  }
  //std::cout << "Created servers: " << std::endl;
  //graph.printVertices();

  // Read Connection costs
  int connection_costs_len = 0;
  f >> connection_costs_len;
  std::getline(f, dummy);

  for(int i = 0; i < connection_costs_len; i++){
    // read line with connection cost info
    std::string s1_name, s2_name;
    double cost, volume;

    f >> s1_name >> s2_name >> cost >> volume;
    f.ignore();

    if(s1_name.empty()){
      throw "Server 1 name is missing";
    }

    if(s2_name.empty()){
      throw "Server 2 name is missing";
    }
    createConnectionCost(s1_name, s2_name, cost, volume);
  }
  //std::cout << "Created Connections: " << std::endl;
  //graph.printEdges();

  // Read Communication demands
  int communication_demands_len = 0;
  f >> communication_demands_len;
  std::getline(f, dummy);

  for(int i = 0; i < communication_demands_len; i++){
    // read line with communcation demands info
    std::string s1_name, s2_name;
    double volume_needed;
    f >> s1_name >> s2_name >> volume_needed;

    if(s1_name.empty()){
      throw "Server 1 name is missing";
    }

    if(s2_name.empty()){
      throw "Server 2 name is missing";
    }

    f.ignore();
    createCommunicationDemand(s1_name, s2_name, volume_needed);
  }

  f.close();
}

void Analyzer::dump(const std::string& filename){
  std::ofstream f(filename);
  if(!f.is_open()){
    throw "Failed to create file";
  }

  f << "Analysis based on data from " << this->input_filename << "\n";

  f.close();
}

void Analyzer::analyze(){
  graph.printVertices();

  for(int i = 0; i < graph.numberOfVerticies(); i++){
    auto& v = graph.getVertex(i);
    graph.dijkstra(v);
  }
}

void Analyzer::createServer(const std::string& name){
  //std::cout << "createServer " << name << std::endl;
  try {
    graph.addVertex({name});
  } catch (const char* e){
    std::cout << "[WARN] attempted to add dupelicate server. Skipping..." << std::endl;
  }
}

void Analyzer::createConnectionCost(const std::string& s1, const std::string& s2, double cost, double volume){
  //std::cout << "createConnectionCost " << s1 << " " << s2 << " " << cost << " " << volume << std::endl;

  ConnectionCost connection{cost, volume};
  Server server1{s1};
  Server server2{s2};

  auto& v = graph.getVertex(server1);
  auto& u = graph.getVertex(server2);
  //std::cout << "v: " << std::hex << &v << " u: " << std::hex << &u << std::endl;
  graph.addEdge(v, u, connection);
}

void Analyzer::createCommunicationDemand(const std::string& s1, const std::string& s2, double volume_needed){
  //std::cout << "createCommunicationDemand " << s1 << s2 << volume_needed << std::endl;
  this->demands.push_back({s1, s2, volume_needed});
}
