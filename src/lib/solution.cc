#include "solution.h"

/************************* Problem 3 *************************/
// Runtime = &theta;(n + m) --> O(n)
std::map<int, int> Graph::shortest_distance(int vertex) 
{
    // input validation
    if(this->v_.empty() || 
        vertex < 0 ||
        vertex >= this->v_.size())
    {
        return {};
    }
    
    // bfs variables
    std::vector<int> visited(this->v_.size(), 0);
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    // shortest distance variables
    std::map<int, int> dist;
    for (int i = 0; i < (int)this->v_.size();i++)
    {
        dist[i] = INT_MAX;
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

                if(dist[cur] == INT_MAX)
                {
                    dist[cur] = 0;
                }

                dist[n] = dist[cur] + 1;
            }
        }
    }
    
    return dist;
}

// Runtime = &theta;(n + m) --> O(n)
std::map<int, std::vector<int>> Graph::shortest_path(int vertex) 
{
    // input validation
    if(this->v_.empty() || 
        vertex < 0 ||
        vertex >= this->v_.size())
    {
        return {};
    }

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
// Runtime = &theta;(n + n + n + m) --> O(n)
std::pair<std::set<int>, std::vector<int>> Graph::topological_sort()
{
    // input validation
    if(this->v_.empty())
    {
        return {};
    }

    int n = this->v_.size();
    std::set<int> root_result = {};
    std::vector<int> top_result(n, -1);
    std::pair<std::set<int>, std::vector<int>> result(root_result, top_result);

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
            result.first.insert(i); // O(n)
        }
    }
    
    // return empty graph is cyclic or undirected
    if(q.empty())
    {
        return {};
    }

    // perform topological sort by degree
    int ri = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        result.second[ri] = i;
        ri++;

        // decrease degree of node j if i -> j & push j to queue if j
        // has no more incoming edges
        for (int j : this->v_[i])
        {
            --deg[j];
            if(deg[j] == 0)
            {
                q.push(j);
            }
        }

        // cycle detected, empty top sort, keep roots
        if(q.empty() && ri < (int)result.second.size())
        {
            result.second = {};
        }
    }

    return result;
}

/************************* Problem 5 *************************/
// Runtime = &theta;(2*(n + m) + n) --> O(n)
std::vector<bool> nodes_in_path(Graph& g)
{
    // input validation
    if(g.v_.empty())
    {
        return {};
    }

    std::vector<bool> result(g.v_.size(), false);
    int num_nodes = g.v_.size();
    // get shortest distances from node 0 to all other nodes
    std::map<int, int> dist_0 = g.shortest_distance(0);
    // get shortest distances from node N-1 to all other nodes
    std::map<int, int> dist_nmin1 = g.shortest_distance(num_nodes - 1);

    // return all false if path does not exist
    if(dist_0[num_nodes - 1] == INT_MAX || dist_nmin1[0] == INT_MAX)
    {
        return result;
    }

    // check to see if distance from node 0 to node i + distance from 
    // node i to node N-1 equals the distance from node 0 to node N-1
    int d_0_to_nmin1 = dist_0[num_nodes - 1];
    for (int i = 0; i < num_nodes; i++)
    {
        int d_0_to_i = dist_0[i];
        int nmin1_to_i = dist_nmin1[i];
        if(d_0_to_i + nmin1_to_i == d_0_to_nmin1)
        {
            result[i] = true;
        }
    }

    return result;
}