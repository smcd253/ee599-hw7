#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <iostream>     // for debugging
#include <vector>       // std::vector<int>
#include <stack>        // std::order_stack<int>
#include <queue>        // std::queue<int>
#include <set>          // std::set<int>
#include <map>          // std::map<int std::set<int>>
#include <iterator>     // std::set::iterator


/************************* Problem 3 *************************/
class Graph 
{
    public:
        std::map<int, std::set<int>> v_;
        Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}

        // member functions
        std::vector<int> shortest_distance(int vertex);
        std::vector<int> dfs_all();
};


#endif

