#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
//2
TEST_CASE("Test operator +")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0,2 , 2},
        {2, 0, 2},
        {2, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 3, 4]\n[5, 0, 6]\n[7, 8, 0]");



}

TEST_CASE("Test operator +=")
{
ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 2, 2},
        {2, 0, 2},
        {2, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 += g2;
    


    CHECK(g1.printGraph() == "[0, 3, 3]\n[3, 0, 3]\n[3, 3, 0]");


}


TEST_CASE("Test operator unary +")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "[0, 1, 2]\n[1, 0, 2]\n[1, 2, 0]");

}

TEST_CASE("Test operator -")
{
 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0,1 , 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");


}

TEST_CASE("Test operator -=")
{


ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {2, 0, 2},
        {3, 3, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> g3 = {
        {0, 3, 3},
        {2, 0, 2},
        {1, 1, 0}};
    g2.loadGraph(g3);
    g1 -= g2;
  CHECK(g1.printGraph() == "[0, -2, -2]\n[0, 0, 0]\n[2, 2, 0]");

}


TEST_CASE("Test operator unary -")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;
      CHECK(g2.printGraph() == "[0, -1, -2]\n[-1, 0, -2]\n[-1, -2, 0]");
    
}

TEST_CASE("Test operator * scalar ")
{
  ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 * 3;
    
    CHECK(g2.printGraph() == "[0, 3, 6]\n[3, 0, 6]\n[3, 6, 0]");

}


TEST_CASE("Test operator *= scalar ")
{
ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 3},
        {2, 1, 0}};
    g1.loadGraph(graph);
    g1 *= 3;
    
    CHECK(g1.printGraph() == "[0, 3, 6]\n[9, 0, 9]\n[6, 3, 0]");

}

TEST_CASE("Test operator *graph ")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0,5, 10},
        {5, 0, 10},
        {5, 10, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * g2;
    
    CHECK(g3.printGraph() == "[0, 10, 10]\n[5, 0, 10]\n[5, 5, 0]");
}

TEST_CASE("Test operator *= graph ")
{



ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 4},
        {5, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> g3 = {
        {0, 6, 5},
        {4, 0, 3},
        {2, 1, 0}};
    g2.loadGraph(g3);
    g1 *= g2;
   
    CHECK(g2.printGraph() ==  "[0, 6, 5]\n[4, 0, 3]\n[2, 1, 0]");
}

TEST_CASE("operator pre increment ")
{
 
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 2},
        {10, 11, 0}};
    g1.loadGraph(graph);
    ++g1;
     CHECK(g1.printGraph() == "[0, 2, 3]\n[2, 0, 3]\n[11, 12, 0]");


}

TEST_CASE("operator pre decrement")
{

   ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 5, 10},
        {15, 0, 20},
        {25, 30, 0}};
    g1.loadGraph(graph);
    --g1;
   
    CHECK(g1.printGraph() == "[0, 4, 9]\n[14, 0, 19]\n[24, 29, 0]");


}

TEST_CASE("operator post increment")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 4},
        {3, 0, 4},
        {3, 4, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1++;
    
     CHECK(g2.printGraph() == "[0, 3, 4]\n[3, 0, 4]\n[3, 4, 0]");
     CHECK(g1.printGraph() == "[0, 4, 5]\n[4, 0, 5]\n[4, 5, 0]");

}

TEST_CASE("operator post decrement")
{

  ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 4},
        {3, 0, 4},
        {3, 4, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1--;
   CHECK(g2.printGraph() == "[0, 3, 4]\n[3, 0, 4]\n[3, 4, 0]");
   
     CHECK(g1.printGraph() == "[0, 2, 3]\n[2, 0, 3]\n[2, 3, 0]");

}


TEST_CASE("operator  comparaison")
{
ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);
    
    CHECK((g1 < g2) == true); 
    CHECK((g1 > g2) == false); 
    CHECK((g1 <= g2) == true);
    CHECK((g1 >= g2) == false); 
    CHECK((g1 == g2) == false);
    CHECK((g1 != g2) == true);

}
TEST_CASE("Invalid operations")
{

 ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};
    g2.loadGraph(graph2);
  
    CHECK_THROWS(g1 * g2);
    CHECK_THROWS(g1 + g2);
    CHECK_THROWS(g1 - g2);
     CHECK_THROWS(g1 *= g2);
    CHECK_THROWS(g1 += g2);
    CHECK_THROWS(g1 -= g2);

}
TEST_CASE("Test /")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 4},
        {6, 0, 8},
        {10, 12, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 / 2;
    CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");
}
TEST_CASE("Test /=")
{

    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 4},
        {6, 0, 8},
        {10, 12, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 /= 2;
    CHECK(g2.printGraph() == "[0, 1, 2]\n[3, 0, 4]\n[5, 6, 0]");
}
TEST_CASE("Test for * friend")
{

    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {3, 0, 3},
        {2, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = 2 * g1;
    CHECK(g2.printGraph() == "[0, 2, 4]\n[6, 0, 6]\n[4, 4, 0]");
    
}