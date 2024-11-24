#include "graph.hpp"

#include <algorithm>
#include <limits>

#include "analyzer.hpp"

template<typename T, typename U>
Graph<T, U>::Graph(){

}

template<typename T, typename U>
Graph<T, U>::~Graph(){

}

template <typename T, typename U>
void Graph<T, U>::addVertex(T data){
  for(const auto& vertex : this->vertices){
    if(vertex.data == data){
      throw "This data is already in the graph";
    }
  }

  vertices.push_back({data});
}

template <typename T, typename U>
Graph<T, U>::Vertex& Graph<T, U>::getVertex(int index){
  return vertices.at(index);
}

template <typename T, typename U>
Graph<T, U>::Vertex& Graph<T, U>::getVertex(T data){
  for(auto& vertex : this->vertices){
    if(vertex.data == data){
      return vertex;
    }
  }

  throw "Vertex with this data is not in graph";
}

template <typename T, typename U>
void Graph<T, U>::addEdge(Vertex& v, Vertex& u, U weight){
  for(const auto& edge : this->edges) {
    if((*edge.v == v && *edge.u == u) || (*edge.v == u && *edge.u == v)){
      throw "Edge between these vertices is already in the graph";
    }
  }

  this->edges.push_back({&v, &u, weight});
}

template <typename T, typename U>
Graph<T, U>::Edge& Graph<T, U>::getEdge(Vertex& v, Vertex& u){
  for(auto& edge : this->edges) {
    if((*edge.v == v && *edge.u == u) || (*edge.v == u && *edge.u == v)){
      return edge;
    }
  }

  throw "Edge does not exists on these vertices";
}

template <typename T, typename U>
std::vector<typename Graph<T, U>::Vertex*> Graph<T, U>::adjacentVertices(Vertex& v){
  std::vector<Vertex*> adjacentVertices;

  for(const auto& edge : this->edges){
    if(edge.v == &v) {
      adjacentVertices.push_back(edge.u);
    } else if(edge.u == &v){
      adjacentVertices.push_back(edge.v);
    }
  }

  return adjacentVertices;
}

/*
  Impl of dijkstra algo in custom graph class.

  The impl is very ugly. 

  @return DijkstraResult template struct
*/
template <typename T, typename U>
GRAPH_T::DijkstraResult GRAPH_T::dijkstra(Vertex& src){
  std::vector<int> visited;
  visited.reserve(this->vertices.size());

  std::vector<bool> unvisted(this->vertices.size(), true);
  std::vector<double> weights(this->vertices.size(), INF);
  std::vector<int> previouses(this->vertices.size(), -1);
  
  DijkstraResult d {
    weights,
    previouses
  };

  // helper func for calc dis. Takes index
  auto distance = [&](int prev, int des){
    // Get weight of prev
    double prev_w = d.weights.at(prev);

    // Get weight of prev to des from edge
    auto& prev_v = getVertex(prev);
    auto& des_v = getVertex(des);
    auto& edge = getEdge(prev_v, des_v);

    return prev_w + edge.weight();
  };

  // 1. Initialize
  int src_i = indexOf(this->vertices, src);
  d.weights[src_i] = 0.0;
  d.previouses[src_i] = src_i;

  int current = src_i;
  
  while(visited.size() < this->vertices.size()){
    auto& v = getVertex(current);
    
    // 2. Calculate distances from current to adjacents
    auto adjacents = adjacentVertices(v);

    for(auto adj : adjacents){
      int adj_i = indexOf(this->vertices, *adj);
      double dis = distance(current, adj_i);
      if(unvisted.at(adj_i) && d.weights.at(adj_i) > dis){
        d.weights[adj_i] = dis;
        d.previouses[adj_i] = current;
      }
    }
    
    // 3. Make current visited
    unvisted[current] = false;
    visited.push_back(current);

    // 4. Pick lowest unvisted vertex to be new current
    double min_weight = INF;
    int min_weight_i = -1;
    for(size_t i = 0; i < this->vertices.size(); i++){
      if(unvisted.at(i) && min_weight >= d.weights.at(i)){
        min_weight = d.weights.at(i);
        min_weight_i = i;
      }
    }

    if(min_weight_i == -1){ 
      break;
    }

    current = min_weight_i;
  }

  std::cout << "\nIndex\tVertex\tWeight\tPrev" << std::endl;
  std::cout << "-----\t------\t------\t----" << std::endl;
  for(size_t i = 0; i < this->vertices.size(); i++){
    std::cout << i << "\t" << this->vertices.at(i).data << "\t"
    << d.weights.at(i) << 
    "\t" << d.previouses.at(i) << std::endl;
  }

  return d;
}

template <typename T, typename U>
void Graph<T, U>::printVertices(){
  for(const auto& vertex : this->vertices) {
    std::cout << "Vertex { ";
    std::cout << vertex.data << ", " << std::hex << &vertex;
    std::cout << " }" << std::endl;
  }
}

template <typename T, typename U>
void Graph<T, U>::printEdges(){
  for(const auto& edge : this->edges) {
    std::cout << "Edge { ";
    std::cout << std::hex << edge.v << ", " << std::hex << edge.u;
    std::cout << " }" << std::endl;
  }
}

// template <typename T, typename U>
// std::ostream& operator<<(std::ostream& os, const Graph<T, U>& g){
//   for(int i = 0; i < g.vertices.size(); i++){
//     const Graph::Vertex& v = g.vertices.at(i);
    
//     std::cout << i << ": ";
//     for(const auto& edge : v.edges){
//       std::cout << 
//     }
//   }
// }

template <typename T, typename U>
int Graph<T, U>::indexOf(const std::vector<Vertex>& v, Vertex u) const {
  for(size_t i = 0; i < v.size(); i++){
    if(v.at(i) == u){ return i; }
  }

  throw "Vertex not in vector";
}

template <typename T, typename U>
bool Graph<T, U>::findAndRemove(std::vector<Vertex>& v, Vertex u){
  // super ugly remove element winext->datath data 
  for(size_t i = 0; i < v.size(); i++){
    if(v.at(i) == u){
      v.erase(std::find(v.begin(), v.end(), u));
      return true;
    }
  }

  return false;
}

template class Graph<Server, ConnectionCost>;
