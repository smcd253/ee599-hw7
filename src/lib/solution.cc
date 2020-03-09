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