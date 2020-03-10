#include "solution.h"

/************************* Problem 3 *************************/
// Runtime = &theta;(n + m)
std::map<int, int> Graph::shortest_distance(int vertex) 
{
    // bfs variables
    std::vector<int> visited(this->v_.size(), 0);
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    // shortest distance variables
    std::map<int, int> dist;
    for(auto& d : dist)
    {
        d.second = INT_MAX;
    }

    // bfs
    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        for (auto &n : v_[cur]) 
        {
            if (!visited[n]) 
            {
                visited[n] = 1;
                q.push(n);

                dist[n] = dist[cur] + 1;
            }
        }
    }
    
    return dist;
}

std::map<int, std::vector<int>> Graph::shortest_path(int vertex) 
{
    // bfs variables
    std::vector<int> visited(this->v_.size(), 0);
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    // shortest path variables
    std::map<int, std::vector<int>> path_map;
    path_map[vertex].push_back(vertex);

    // bfs
    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        for (auto& n : v_[cur]) 
        {
            if (!visited[n]) 
            {
                visited[n] = 1;
                q.push(n);
 
                path_map[n] = path_map[cur];
                path_map[n].push_back(n);
            }
        }
    }

    return path_map;
}

/************************* Problem 4 *************************/
// Kahn's Algorithm
std::pair<std::vector<int>, std::vector<int>> Graph::topological_sort()
{
    int n = this->v_.size();
    std::pair<std::vector<int>, std::vector<int>> result(1, n);

    // count incoming edges for each node
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j : this->v_[i])
        {
            deg[j]++;
        }
    }

    // initialize queue with root nodes
    // push root nodes to root node result
    std::queue<int> q;
    // O(n^2) --> consider changing result to queue or stack
    for (int i = 0; i < n; i++)
    {
        if(deg[i] == 0)
        {
            q.push(i);  // O(1)
            result.first.push_back(i); // O(n)
        }
    }
    
    // perform topological sort by degree
    int ri = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        result.second[ri] = i;
        ri++;

        // decrease degree of node j if i -> j & push j to queu if j
        // has no more incoming edges
        for (int j : this->v_[i])
        {
            --deg[j];
            if(deg[j] == 0)
            {
                q.push(j);
            }
        }
    }

    return result;
}