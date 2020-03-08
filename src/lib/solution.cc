#include "solution.h"

/************************* Problem 3 *************************/
void Graph::shortest_distance(int root) 
{
    std::map<int, int> marks;
    std::queue<int> q;
    q.push(root);
    marks[root] = 1;
    while (!q.empty()) 
    {
        int cur = q.front();

        q.pop();
        for (auto &n : edge_map_[cur]) 
        {
            if (!marks[n]) 
            {
                marks[n] = 1;
                q.push(n);
            }
        }
    }
}