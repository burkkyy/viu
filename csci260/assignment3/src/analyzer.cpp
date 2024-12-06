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

  std::cout << "Dumping analysis to " << filename << std::endl;

  f << "Analysis based on data from " << this->input_filename << "\n";

  f << "\nThe following communication demand(s) can't be met\nby current infrastructure due to lack of routes\nbetween the two servers:\n";
  for(const auto& c : this->missingConnections){
    f << c.from << " " << c.to << " " << c.volume_needed << "\n";
  }

  f << "\nIn order to meet the rest of the communication demands\nwith the lowest cost, the following direct link(s)\nmust expand their capacity:\n";
  for(const auto& c : this->connectionRequirements){
    f << c.s1 << " to " << c.s2 << " from " << c.volume << " to " << c.volume + c.volume_needed << "\n";    
  }

  f.close();
}

void Analyzer::analyze(){
  //graph.printVertices();
  // for(int i = 0; i < graph.numberOfVerticies(); i++){
  //   auto& v = graph.getVertex(i);
  //   auto d = graph.dijkstra(v);

  //   std::cout << "\nIndex\tVertex\tWeight\tPrev" << std::endl;
  //   std::cout << "-----\t------\t------\t----" << std::endl;
  //   for(int i = 0; i < graph.numberOfVerticies(); i++){
  //     std::cout << i << "\t" << graph.getVertex(i).data << "\t"
  //     << d.weights.at(i) << 
  //     "\t" << d.previouses.at(i) << std::endl;
  //   }
  // }

  for(auto& demand : this->demands){
    //std::cout << "\n\n" << demand.s1 << " " << demand.s2 << " " << demand.volume_needed << std::endl;
    int s1_index = getIndexOfServer(demand.s1);
    int s2_index = getIndexOfServer(demand.s2);
    
    auto starting_vertex = graph.getVertex(demand.s1);
    auto d = graph.dijkstra(starting_vertex);

    int end = s1_index;
    int current = getIndexOfServer(demand.s2);

    while(current != end){
      int next = d.previouses.at(current);
      if(next == current){
        std::cout << "How? Recursive prev" << std::endl;
        break;
      }

      if(next == -1){
        addMissingConnection(s1_index, s2_index, demand.volume_needed);
        break;
      }

      analyzeConnection(current, next, demand);

      //std::cout << "At " << current << " going to " << next << std::endl;
      current = next;
    }
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

void Analyzer::analyzeConnection(int s1, int s2, CommunicationDemand demand){
  auto v1 = graph.getVertex(s1);
  auto v2 = graph.getVertex(s2);

  // Look for this connection in connectionRequirments.
  // Edit that connection in connectionRequirments otherwise create it
  // Note order of s1 and s2 does not matter
  for(auto& c : this->connectionRequirements){
    if((v1.data == c.s1 && v2.data == c.s2) || (v2.data == c.s1 && v1.data == c.s2)){
      c.volume_needed += demand.volume_needed;
      return;
    }
  }

  // connection not found, create it 
  auto connection = getConnection(v1.data, v2.data);
  double volume_required = demand.volume_needed - connection.volume;
  this->connectionRequirements.push_back({v1.data, v2.data, volume_required, connection.volume});

  // std::cout << " The connection between " << s1 << " " << s2 << std::endl;
  // std::cout << "\tVolumne rn " << connection.volume << std::endl;
  // std::cout << "\tVolumn needed " << demand.volume_needed << std::endl;
}

void Analyzer::addMissingConnection(int s1, int s2, double volume_needed){
  auto v1 = graph.getVertex(s1);
  auto v2 = graph.getVertex(s2);

  //std::cout << "Missing connection from " << v1.data << " to " << v2.data << " volume: " << volume_needed << std::endl;
  missingConnections.push_back({v1.data, v2.data, volume_needed});
}

int Analyzer::getIndexOfServer(Server s){
  for(int i = 0; i < graph.numberOfVerticies(); i++){
    auto v = graph.getVertex(i);
    if(v.data == s){
      return i;
    }
  }

  throw "Server not found";
}

ConnectionCost Analyzer::getConnection(Server s1, Server s2){
  auto v1 = graph.getVertex(s1);
  auto v2 = graph.getVertex(s2);
  auto e = graph.getEdge(v1, v2);
  return e.w;
}
