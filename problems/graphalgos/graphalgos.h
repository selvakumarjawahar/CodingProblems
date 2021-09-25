//
// Created by selva on 03-08-2020.
//

#ifndef SOLUTIONS_GRAPHALGOS_H
#define SOLUTIONS_GRAPHALGOS_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace graph_algos{

template<typename T>
struct Vertex {
  T data;
  int vertexID;
  std::map<std::string, std::string> attributes;
  Vertex* adjVertex;
  Vertex():vertexID{0},adjVertex{nullptr}{}
};

template<typename T>
struct Graph {

  void addVertex(Vertex<T> vertex) {
    vArray.push_back(vertex);
  }

  void addEdge(int vertexID1, int vertexID2) {
    auto itr1 = std::find_if(vArray.begin(),vArray.end(),
                              [vertexID1](const Vertex<T>& vertex){
                                return vertex.vertexID == vertexID1;
                                });
    if(itr1 == vArray.end()){
      return;
    }
    auto itr2 = std::find_if(vArray.begin(),vArray.end(),
                             [vertexID2](const Vertex<T>& vertex){
                               return vertex.vertexID == vertexID2;
                             });
    if(itr2 == vArray.end()){
      return;
    }
    Vertex<T>* cptr = &(*itr1);
    Vertex<T>* pptr;
    while(cptr != nullptr){
      pptr = cptr;
      cptr = cptr->adjVertex;
    }
    pptr->adjVertex = new Vertex<T>;
    pptr->adjVertex->vertexID = vertexID2;
  }

  std::vector<Vertex<T>> BFS(int vertexID) {


  }

  void printGraph() {
    std::cout<<"size = "<<vArray.size()<<'\n';
    for(auto& vertex : vArray) {
      std::cout<<vertex.vertexID;
      auto *tptr = vertex.adjVertex;
      while(tptr != nullptr){
        std::cout<<"->"<<tptr->vertexID;
        tptr = tptr->adjVertex;
      }
      std::cout <<'\n';
    }
  }
  ~Graph(){
    for(auto& vertex : vArray){
      auto* vptr = vertex.adjVertex;
      while(vptr != nullptr){
        auto *tptr = vptr;
        vptr = vptr->adjVertex;
        delete tptr;
      }
    }
  }

private:
  std::vector<Vertex<T>> vArray;
};



}

#endif // SOLUTIONS_GRAPHALGOS_H
