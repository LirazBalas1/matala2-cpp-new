#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>

namespace ariel
{

    class Graph
    {
    public:

        void loadGraph(const std::vector<std::vector<int>> &matrix);
        std::string printGraph() const;

        unsigned int size() const;
        void transpose_graph();

        /**
         *This function receive two number that correspond to two vertices and return the weight of the edge between this two vertices. 
         *If no edge exists,this function returns 0.
         */
        const int getWeight(unsigned int x, unsigned int y) const;

        /**
         * This function receive aumber that coresponds to  the index of the vertex a
         * This function return a vector that contains all vertex  connected to the specified vertex that receive in function.
         */
        std::vector<unsigned int> getVoisin_specificvertix(unsigned int vertex) const;
        

        // Operator overloads
        Graph operator+() const; // Unary plus
        Graph operator+(const Graph &other) const;
        Graph &operator+=(const Graph &other);

        Graph operator-() const; // Unary minus
        Graph operator-(const Graph &other) const;
        Graph &operator-=(const Graph &other);

        Graph &operator++();   // Pre-increment
        Graph operator++(int); // Post-increment

        Graph &operator--();   // Pre-decrement
        Graph operator--(int); // Post-decrement

        Graph operator*(int scalar) const;
        Graph &operator*=(int scalar);

        Graph &operator/(int scalar);
        Graph &operator/=(int scalar);

        Graph operator*(const Graph &other) const;
        Graph &operator*=(const Graph &other);

        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator<=(const Graph &other) const;
        bool operator>(const Graph &other) const;
        bool operator>=(const Graph &other) const;

        
        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
   
        friend Graph operator/(int scalar, const Graph &graph);
        
        friend Graph operator*(int scalar, const Graph &graph);
         
        static bool check_symetric(const std::vector<std::vector<int>> &matrix);

    private:
        
        bool contain_graph(const Graph &other) const;
        std::vector<std::vector<int>> matrix;

        size_t count_edge() const;
    };

} // namespace ariel

#endif // GRAPH_HPP