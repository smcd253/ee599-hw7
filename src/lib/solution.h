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
class TreeNode 
{
    private:
        

    public:
        int vertex;
        TreeNode* parent;
        
        TreeNode() : vertex(-1) , parent(NULL) {}
        TreeNode(int x) : vertex(x) , parent(NULL) {}
        TreeNode(int x, TreeNode* p) : vertex(x), parent(p) {}

        // assignment overload
        TreeNode* operator = (int rhs)
        {
            TreeNode* result = nullptr;
            result->vertex = rhs;
            return result;            
        }

        TreeNode* operator = (std::pair<int, TreeNode*> rhs)
        {
            TreeNode* result = nullptr;
            result->vertex = rhs.first;
            result->parent = rhs.second;
            return result; 
        }
};

class Graph 
{
    public:
        std::map<int, std::set<int>> v_;
        Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}

        // member functions
        std::map<int, int> shortest_distance(int vertex);
        std::map<int, std::vector<int>> shortest_path(int vertex);
};


#endif

