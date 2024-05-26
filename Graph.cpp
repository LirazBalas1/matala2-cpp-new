//Liraz Balas
//211801220
//lbalad13@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

namespace ariel
{

void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph:0 in the diagonal.");
		}
    }
    matrix = graph;
}

// This function returns a string that is a representation of the adjacency matrix.
std::string Graph::printGraph() const {
    std::ostringstream os;
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            os << "[";
            for (size_t j = 0; j < matrix[i].size(); ++j)
            {
                os << matrix[i][j];
                if (j < matrix[i].size() - 1)
                {
                    os << ", ";
                }
            }
            os << "]";
            if (i < matrix.size() - 1)
            {
                os << "\n";
            }
        }
        return os.str();
}

//This function return the size of the adjacency matrix:that is the number of vertices in the graph.
unsigned int Graph::size() const{
    return matrix.size();
}

//  This function transposes the graph
void Graph::transpose_graph() {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix.size(); j++) {

            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

//This function receive two number that correspond to two vertices and return the weight of the edge between this two vertices. 
//If no edge exists,this function returns 0.
const int Graph::getWeight(unsigned int x, unsigned int y) const{

    if (x >= matrix.size() || y >= matrix[0].size()) {
        throw out_of_range("Index out of range");
    }

    return matrix[x][y];
}

//This function receive aumber that coresponds to  the index of the vertex a
//This function return a vector that contains all vertex  connected to the specified vertex that receive in function.
vector<unsigned int> Graph::getVoisin_specificvertix(unsigned int vertex) const {

    vector<unsigned int> voisin_specific_vert;

    if (vertex >= matrix.size()) {
        throw out_of_range("Index out of range");
    }


    const vector<int>& edges = matrix[vertex];
    for (unsigned int i = 0; i < edges.size(); ++i) {
        if (edges[i] != 0) {
            voisin_specific_vert.push_back(i);
        }
    }

    return voisin_specific_vert;
}


//operaors

Graph Graph::operator+(const Graph &other) const
    {   
        
         if (matrix.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("The graph is empty");
        
         }
        
        if (matrix.size() != other.size())
        {
            throw invalid_argument("Graphs must be of same size .");
        }
        std::vector<std::vector<int>> v(matrix.size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                v[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(v);
        return ans;
    }


Graph &Graph::operator+=(const Graph &other)
    {
           if (matrix.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("The graph is empty");
        
         }
        
        if (matrix.size() != other.size())
        {
            throw invalid_argument("Graphs must be  the same size .");
        }
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j <matrix.size(); ++j)
            {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }


 Graph Graph::operator+() const
    {
        return *this;
    }
    
    
    
Graph Graph::operator-(const Graph &other) const
    {   
        
         if (matrix.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("The graph is empty");
        
         }
        
        if (matrix.size() != other.size())
        {
            throw invalid_argument("Graphs must be  the same size .");
        }
        std::vector<std::vector<int>> v(matrix.size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                v[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(v);
        return ans;
    }


Graph &Graph::operator-=(const Graph &other)
    {
           if (matrix.size() == 0 || other.size() == 0) 
         {
        throw std::invalid_argument("The graph is empty");
        
         }
        
        if (matrix.size() != other.size())
        {
            throw invalid_argument("Graphs must be the same size");
        }
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j <matrix.size(); ++j)
            {
                matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }
    
    Graph Graph::operator-() const
    {
        std::vector<std::vector<int>> v(matrix.size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                v[i][j] = -matrix[i][j];
            }
        }
        Graph ans;
        ans.loadGraph(v);
        return ans;
    }
    
      Graph &Graph::operator++()
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                ++matrix[i][j];
            }
        }
        
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            matrix[i][i] = 0;
        }
        return *this;
    }
    
    Graph Graph::operator++(int)
    {
        Graph temp = *this;
        ++(*this);
        return temp;
    }
    
     Graph &Graph::operator--()
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                --matrix[i][j];
            }
        }
        
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            matrix[i][i] = 0;
        }
        return *this;
    }
    
     Graph Graph::operator--(int)
    {
        Graph temp = *this;
        --(*this);
        return temp;
    }
    
    
    
     Graph Graph::operator*(int scalar) const
    {
        std::vector<std::vector<int>> v(matrix.size(), std::vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                v[i][j] = matrix[i][j] * scalar;
            }
        }
        Graph ans;
        ans.loadGraph(v);
        return ans;
    }
    
    Graph &Graph::operator*=(int scalar)
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                matrix[i][j] *= scalar;
            }
        }
        return *this;
    }
    
    
  
    
     Graph Graph::operator*(const Graph &other) const
    {
        if (matrix.size() != other.matrix.size())
        {
            throw invalid_argument("Impossible to multiply .Not valid dimensions.");
        }
        std::vector<std::vector<int>> v(matrix.size(), std::vector<int>(matrix.size(), 0));
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                for (size_t k = 0; k < matrix.size(); ++k)
                {
                    v[i][j] += matrix[i][k] * other.matrix[k][j];
                }
                
                if (i == j)
                {
                    v[i][j] = 0;
                }
            }
        }
        Graph ans;
        ans.loadGraph(v);
        return ans;
    }
    
    Graph &Graph::operator*=(const Graph &other)
    {
        if (matrix.size() != other.matrix.size())
        {
            throw invalid_argument("Error :Graphs must be of the same size.");
        }

        std::vector<std::vector<int>> v(matrix.size(), std::vector<int>(matrix.size(), 0));

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                for (size_t k = 0; k < matrix.size(); ++k)
                {
                    v[i][j] += matrix[i][k] * other.matrix[k][j];
                }
                if (i == j)
                {
                    v[i][j] = 0; 
                }
            }
        }

        this->loadGraph(v);
        return *this;
    }
    
    
       Graph operator*(int scalar, const Graph &graph)
    {
        return graph * scalar; 
    }
    
    
    Graph &Graph::operator/(int scalar)
    {
        if (scalar == 0)
        {
            throw invalid_argument("Division by zero isimpossibe.");
        }
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                matrix[i][j] /= scalar;
            }
        }
        return *this;
    }

   
    Graph &Graph::operator/=(int scalar)
    {
        if (scalar == 0)
        {
            throw invalid_argument("Division by zero is impossible.");
        }
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix.size(); ++j)
            {
                matrix[i][j] /= scalar;
            }
        }
        return *this;
    }

   
   
    
     std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        os << graph.printGraph() << "\n"; 
        return os;
    }
    
    
    bool Graph::operator==(const Graph &g) const
    {
       
        if (matrix.size() == g.matrix.size())
        {
            for (size_t i = 0; i < matrix.size(); i++)
            {
                for (size_t j = 0; j < matrix[i].size(); j++)
                {
                    if (matrix[i][j] != g.matrix[i][j])
                    {
                        return false; 
                    }
                }
            }
            return true; 
        }
        
        else if (!((*this) < g) && !(g < *this))
        {
            return true; 
        }
        return false; 
    }

    bool Graph::operator!=(const Graph &g) const
    {
        return !(*this == g);
    }
    
       bool Graph::operator>(const Graph &other) const
    {
        return other < *this;
    }
      bool Graph::operator<=(const Graph &g) const
    {
        return (*this < g) || (*this == g);
    }
    
  bool Graph::operator>=(const Graph &g) const
    {
        return g <= *this;
    }
    
    
     bool Graph::contain_graph(const Graph &other) const
    {

          
        std::vector<size_t> vect(other.size());
        std::iota(vect.begin(), vect.end(), 0);

        if (matrix.size() > other.matrix.size())
        {
            return false;
        }


        do
        {
            bool flag = true;
            for (size_t i = 0; i < matrix.size() && flag; ++i)
            {
                for (size_t j = 0; j < matrix.size() && flag; ++j)
                {
                    if (matrix[i][j] != 0 && other.matrix[vect[i]][vect[j]] == 0)
                    {
                        flag = false;
                    }
                }
            }
            if (flag)
            {
                return true;
            }
        }while (std::next_permutation(vect.begin(), vect.end()));

        return false;
    }
    
    bool Graph::operator<(const Graph &other) const
    {
        
        if (this->contain_graph(other) && !other.contain_graph(*this))
        {
            return true;
        }

        
        if (other.contain_graph(*this) && !this->contain_graph(other))
        {
            return false;
        }

        
        size_t edge1 = this->count_edge();
        size_t edge_2 = other.count_edge();
        if (edge1 != edge_2)
        {
            return edge1 < edge_2;
        }

        
        return this->matrix.size() < other.matrix.size();
    }

    size_t Graph::count_edge() const
    {
        size_t counter = 0;
        if (check_symetric(this->matrix))
        {
            for (size_t i = 0; i < matrix.size(); ++i)
            {
                for (size_t j = 0; j < matrix.size(); ++j)
                {
                    if (this->matrix[i][j] != 0)
                    {
                        counter++;
                    }
                }
            }
            counter = counter / 2;
        }
        else
        {
            for (size_t i = 0; i < matrix.size(); ++i)
            {
                for (size_t j = 0; j <matrix.size(); ++j)
                {
                    if (matrix[i][j] != 0)
                    {
                        counter++;
                    }
                }
            }
            counter = counter;
        }
        return counter;
    }

   
    bool Graph::check_symetric(const std::vector<std::vector<int>> &matrix)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Graph operator/(int scalar, const Graph &graph)
    {
        std::vector<std::vector<int>> result(graph.size(), std::vector<int>(graph.size(), 0));
        for (size_t i = 0; i < graph.size(); ++i)
        {
            for (size_t j = 0; j < graph.size(); ++j)
            {
                if (i != j && graph.matrix[i][j] != 0)
                {
                    result[i][j] = scalar / graph.matrix[i][j];
                }
            }
        }
        Graph ans;
        ans.loadGraph(result);
        return ans;
    }
}
