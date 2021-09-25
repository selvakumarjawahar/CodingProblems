//
// Created by selva on 03-08-2020.
//

#include <graphalgos/graphalgos.h>

#include <bandit/bandit.h>

using namespace snowhouse;
using namespace bandit;
using namespace graph_algos;
// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.
  describe("test the graph algos", []() {

    it("test with a unique string", [&]() {
      Graph<int> graph;
      Vertex<int> vertex;
      vertex.vertexID = 1;
      graph.addVertex(vertex);
      vertex.vertexID = 2;
      graph.addVertex(vertex);
      vertex.vertexID = 3;
      graph.addVertex(vertex);
      vertex.vertexID = 4;
      graph.addVertex(vertex);

      graph.addEdge(1,2);
      graph.addEdge(1,3);
      graph.addEdge(2,4);
      graph.addEdge(3,4);
      graph.printGraph();
    });

  },false);
});
