//Liraz Balas
//211801220
//lbalad13@gmail.com
#pragma once
  
#include "Graph.hpp"
#include <unordered_set>
  
using namespace std;

 
namespace ariel
{
  
class Algorithms
  {
  
public:
		/**
         * This function checks if the graph is strongly connected.This returns true or false
         */ 
	static bool isConnected (Graph & graph);
	
 
		/**
         * This functionfinds the shortest path between two vertices .We use the algorithm of  Bellman-Ford algorithm.
         */ 
	static string shortestPath (const Graph & graph, unsigned int start,
								unsigned int end);
	
 
		/**
         * This function check if  the graph contains cycle.
         */ 
	static string isContainsCycle (const Graph & graph);
	
 
		/**
         * This function check if the graph is bipartite.
         */ 
	static string isBipartite (const Graph & graph);
	
 
		/**
         * This function check if the graph contains  a negative cycle 
         */ 
	static string negativeCycle (const Graph & graph);
  
 
private:
 
		/**
         * Depth-First Search
         */ 
	static void DFS (const Graph & graph, unsigned int v,
					 vector < bool >&visited);
	
 
		/**
         * Depth-first search help fur check if cycle
         */ 
	static bool DFS2 (unsigned int node, unsigned int parentNode,
					  const Graph & graph, vector < bool >&visited,
					  vector < unsigned int >&parent, string & cyclePath);
	
 
		/**
         * Breadth-first search (BFS)
         */ 
	static bool BFS (const Graph & graph, unsigned int start,
					 vector < int >&color, unordered_set < unsigned int >&A,
					 unordered_set < unsigned int >&B);
	
 
 
		/**
         * This function construct a string for the function bipartite
         */ 
	static string construct_string_bipartite (const unordered_set <
											  unsigned int >&s);
};

}