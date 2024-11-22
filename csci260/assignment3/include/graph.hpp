#pragma once

#include <vector>

template<typename T, typename U>
class Graph {
public:
  struct Vertex {
    T data;
    std::vector<Edge> edges;
  };

  struct Edge {
    Edge(const Vertex& u, const Vertex& v) : u{u}, v{v} {}
    const Vertex& u;
    const Vertex& v;

    U weight;
  };

  Graph();
  ~Graph();

  Vertex& addVertex(T data);
  Vertex& getVertex(int index);
  
  Edge& addEdge(Vertex& u, Vertex& v);
  Edge& getEdge(Vertex& u, Vertex& v);

private:
  

  std::vector<Vertex> vertices;
};
