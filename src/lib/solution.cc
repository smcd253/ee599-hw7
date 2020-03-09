#include "solution.h"

/************************* Problem 3 *************************/
// Runtime = &theta;(n + m)
std::map<int, int> Graph::shortest_distance(int vertex) 
{
    // bfs variables
    std::vector<int> visited;
    visited.reserve(this->v_.size());
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    // shortest path variables
    std::map<int, int> dist;

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

                // modify path tree if distance is shorter
                // than old distance to 
                int d = dist[cur] + 1;
                if(d > dist[n])
                {
                    dist[n] = d;
                }
            }
        }
    }

    return dist;
}

std::map<int, std::vector<int>> Graph::shortest_path(int vertex) 
{
    // bfs variables
    std::vector<int> visited;
    visited.reserve(this->v_.size());
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    // shortest path variables
    std::map<int, int> dist;
    TreeNode* path_tree[this->v_.size() - 1];
    path_tree[0]->vertex = vertex;
    std::map<int, std::vector<int>> path_map;

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

                // modify path tree if distance is shorter
                // than old distance to 
                int d = dist[cur] + 1;
                if(d > dist[n])
                {
                    path_tree[n] = (n, cur);
                    dist[n] = d;
                }
            }
        }
    }

    // build path_map
    // Runtime = &theta;(n + n)
    for (TreeNode* v : path_tree)
    {
        TreeNode* cur = v;
        while(cur->first != vertex)
        {
            path_map[n].push_back(cur->first);
            cur = cur->parent;
        }
    }

    return path_map;
}