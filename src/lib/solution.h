#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <iostream>     // for debugging
#include <vector>       // std::vector<int>
#include <stack>        // std::order_stack<int>
#include <queue>        // std::queue<int>
#include <set>          // std::set<int>
#include <map>          // std::map<int std::set<int>>
#include <iterator>     // std::set::iterator
#ifdef __linux__ 
    #include <climits>      // INT_MAX (linux)

#elif __APPLE__
    #include <limits>       // INT_MAX (darwin)
#endif


class Graph 
{
    public:
        std::map<int, std::set<int>> v_;
        Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}

        // member functions
        /************************* Problem 3 *************************/
        std::map<int, int> shortest_distance(int vertex);
        std::map<int, std::vector<int>> shortest_path(int vertex);
        /************************* Problem 4 *************************/
        std::pair<std::vector<int>, std::vector<int>> topological_sort();
};

/************************* Problem 5 *************************/
/**
 * Evaluates which nodes in the graph lie in the shortest distance path
 * between node 0 and node N-1
 * */
std::vector<bool> nodes_in_path(Graph& g);
#endif

