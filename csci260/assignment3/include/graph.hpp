#pragma once

#include <vector>
#include <ostream>

#define INF std::numeric_limits<double>::infinity()

#define GRAPH_T Graph<T, U>

// I found myself writting this funky code a ton
#define __ENSURE_SAFE_DEF(ptr) \
if(ptr == nullptr){ throw "Attempting to dereference a nullptr"; }

// T: vertex data type
// U: edge weight type
template<typename T, typename U>
class Graph {
public:
  struct Vertex {
    T data;

    bool operator==(const Vertex& v) const {
      return data == v.data;
    }
  };

  struct Edge {
    Edge(Vertex* v, Vertex* u, U w) : v{v}, u{u}, w{w} {}

    Vertex* v;
    Vertex* u;
    U w;

    auto weight() const {
      return w.get();
    }
  };

  struct DijkstraResult {
    std::vector<double> weights; // should be U but too lazy to make it work
    std::vector<int> previouses;
  };

  Graph();
  ~Graph();

  bool hasVertex(T data);
  void addVertex(T data);
  Vertex& getVertex(int index);
  Vertex& getVertex(T data);
  int numberOfVerticies() const { return this->vertices.size(); }
  
  bool hasEdge(Vertex& v, Vertex& u);
  bool hasEdge(T v, T u);
  void addEdge(Vertex& v, Vertex& u, U weight);
  Edge& getEdge(Vertex& v, Vertex& u);

  U getWeight(Vertex* v, Vertex* u);
  U getWeight(T v, T u);

  std::vector<Vertex*> adjacentVertices(Vertex& v);

  DijkstraResult dijkstra(Vertex& src);

  void printVertices();
  void printEdges();

private:
  // friend std::ostream& operator<<(std::ostream& os, const Graph& g);

  int indexOf(const std::vector<Vertex>& v, Vertex u) const;
  bool findAndRemove(std::vector<Vertex>& v, Vertex d);  

  std::vector<Vertex> vertices;
  std::vector<Edge> edges;
};
