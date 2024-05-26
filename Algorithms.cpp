//Liraz Balas
//211801220
//lbalad13@gmail.com
#include "Algorithms.hpp"
#include <vector>
#include <climits>
#include <queue> 


using namespace ariel;

//finish
//This function checks if the graph is strongly connected.This returns true or false
bool Algorithms::isConnected(Graph& graph) {
//check if the original graph is connected
    vector<bool> vertex_visited(graph.size(), false);
    DFS(graph, 0, vertex_visited);
 // we check if all vertex if true 
    for (bool v : vertex_visited) {
        if (!v){
            return false; 
        }
    }
//check if the transpose of the graph is connected
    fill(vertex_visited.begin(), vertex_visited.end(), false); 
    graph.transpose_graph();
    DFS(graph, 0, vertex_visited);

    // return the graph to the original graph 
    graph.transpose_graph();

    // we check if all vertex if true 
    for (bool v : vertex_visited) {
        if (!v){
            return false; 
        }
    }

    return true;
}

//finish
// Shortest shortest_path using the Bellman-Ford algorithm
string Algorithms::shortestPath(const Graph& graph, const unsigned int start, const unsigned int end) {

    const unsigned int count_vertex = graph.size(); 
    if(start >= count_vertex || end >= count_vertex) {
        throw invalid_argument("Invalid values: the start and the end vertex not be in range.");
    }

    vector<int> distance(count_vertex, INT_MAX); 
    distance[start] = 0; 
    vector<int> pred(count_vertex, -1); 

    for (unsigned int i = 0; i < count_vertex; i++) {
        for (unsigned int j = 0; j < count_vertex; j++) {
            for (unsigned int k = 0; k < count_vertex; k++) {

                if(graph.getWeight(j,k) != 0) {

                    // check if distance is more little
                    if (distance[j] != INT_MAX && distance[j] + graph.getWeight(j,k) < distance[k]) {
                        distance[k] = distance[j] + graph.getWeight(j,k);
                        pred[k] = static_cast<int>(j);
                    }
                }
            }
        }
    }


    for (unsigned int i = 0; i < count_vertex; i++) {
        for (unsigned int j = 0; j < count_vertex; j++) {
            if(graph.getWeight(i,j) != 0) {

                if (distance[i] != INT_MAX && distance[i] + graph.getWeight(i,j) < distance[j]) {

                    return "The graph contains a negative cycle.";
                }
            }
        }
    }
//no shortest_path 
    if (distance[static_cast<unsigned int>(end)] == INT_MAX) {
        return "-1";
    }

    string shortest_path = to_string(end);

    for (unsigned int i = end; i != start; i = static_cast<unsigned int>(pred[i])) {
        shortest_path.insert(0, "->");
        shortest_path.insert(0, to_string(pred[i]));
    }

    // Return the shortest_path
    return shortest_path;

}
//finish
// This function check if  the graph contains cycle.
string Algorithms::isContainsCycle(const Graph& graph) {
    string cycle = "";
    const unsigned int count_vertex = graph.size(); 
    vector<bool> vertex_visited(count_vertex, false);
    vector<unsigned int> pred(count_vertex, INT_MAX);
   
    for (unsigned int i = 0; i < count_vertex; i++) {
        if (!vertex_visited[i]) {
            if (DFS2(i, INT_MAX, graph, vertex_visited, pred, cycle)) {

                unsigned int temp = 0;
                for (const char ch : cycle) {
                     if (ch == '>') {
                        temp++;
                    }
                 }
                if (temp >2) {
                    return cycle;
                }

                else {
                    cycle = "";
                    fill(vertex_visited.begin(), vertex_visited.end(), false);
                }
            }
        }
    }
//no cycle
    return "0";
}

//finish
// This function check if the graph is bipartite.
string Algorithms::isBipartite(const Graph& graph) {
    string biparti = "";
    const unsigned int count_vertex = graph.size(); 
    vector<int> color_vertex(count_vertex, -1);
    unordered_set<unsigned int> setA, setB;

    for (unsigned int i = 0; i < count_vertex; i++) {
        if (color_vertex[i] == -1) {

            if (!BFS(graph, i, color_vertex, setA, setB)) {
                return "The graph is not bipartite"; 
            }
        }
    }
    biparti="The graph is bipartite:";
    biparti=biparti+" setA={";
    biparti.append(construct_string_bipartite(setA));
    biparti.append("}, setB={");
    biparti.append(construct_string_bipartite(setB));
    biparti.append("}.");
    return biparti;
}

// Find out if there is negative cycle in the shortest_path
string Algorithms::negativeCycle(const Graph& graph) {

    const unsigned int count_vertex = graph.size(); // The size of the graph

    // We will check if there is a negative cycle in the shortest shortest_path from each vertex to himself.
    // If the vertex on negative cycle the shortest will return there is a negative cycle in the shortest_path.
    for(unsigned int i = 0; i < count_vertex; i++) {
        if(shortestPath(graph, i, i) == "The graph contains a negative cycle.") {

            // There is a negative cycle in the shortest_path
            return "The graph contains negative cycle";
        }
    }

    // There is no negative cycle in the graph
    return "The graph not contains negative cycle";
}


//finish
// DFS
void Algorithms::DFS(const Graph& graph, unsigned int v, vector<bool>& vertex_visited) {
    vertex_visited[v] = true;
    for (unsigned int i : graph.getVoisin_specificvertix(v)) {

        if (!vertex_visited[i]) {
            DFS(graph, i, vertex_visited);
        }
    }
}
//finish
//help function
bool Algorithms::DFS2(const unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& vertex_visited, vector<unsigned int>& parent, string& cycle) {

    vertex_visited[node] = true; 
    parent[node] = parentNode; 
    for (const unsigned int nextNode : graph.getVoisin_specificvertix(node)) {

        if (!vertex_visited[nextNode]) {
            if (DFS2(nextNode, node, graph, vertex_visited, parent, cycle)) {
                return true;
            }
        }

        else if (nextNode != parentNode) {
            unsigned int temp = node;

            cycle = "The cycle in the graph is : " ;
            cycle=cycle+to_string(nextNode);
            while (temp != INT_MAX && temp != nextNode) {
                cycle += "->" + to_string(temp); 
                temp = parent[temp];
            }

            cycle += "->" + to_string(nextNode); 
            return true;
        }
    }

    return false;
}


// BFS
bool Algorithms::BFS(const Graph& graph, const unsigned int start, vector<int>& color_vertex, unordered_set<unsigned int>& setA, unordered_set<unsigned int>& setB) {

    queue<unsigned int> q; 
    q.push(start); 
    bool bool1 = false;
    bool bool2 = false;
     vector<unsigned int>voisins=graph.getVoisin_specificvertix(start);
    for(const unsigned int voisin : voisins) {
        if (color_vertex[voisin] == 1) {
            bool1 = true;
        }
        if (color_vertex[voisin] == 2) {
            bool2 = true;
        }
    }

    if (bool1 && bool2) {
        return false;
    }

    if(bool1) {
        color_vertex[static_cast<unsigned int>(start)] = 2;
        setB.insert(start);
    }

    else {
        color_vertex[start] = 1; 
        setA.insert(start);
    }

    while (!q.empty()) {
        unsigned int temp_node = q.front();
        q.pop();
        vector<unsigned int>voisins=graph.getVoisin_specificvertix(temp_node);
        for (const unsigned int voisin : voisins) {
            if (color_vertex[voisin] == -1) {
                int num_colore= 3 - color_vertex[temp_node]; 

                color_vertex[voisin] = num_colore; 

                if(color_vertex[voisin] == 1) {
                    setA.insert(voisin);
                }

                else {
                    setB.insert(voisin);
                }
                q.push(voisin);
            }

            else if (color_vertex[voisin] == color_vertex[temp_node]) {
                return false; // Not bipartite
            }
        }
    }

    return true; 
}

//finish
// This function construct a string for the function bipartite
string Algorithms::construct_string_bipartite(const unordered_set<unsigned int>& s) {

    string ans_biparti;
    for (const unsigned int elem : s) {
        ans_biparti = ", " + to_string(elem) + ans_biparti;
    }

    if (!ans_biparti.empty()) {
        ans_biparti.erase(0, 2);
    }
    return ans_biparti;
}