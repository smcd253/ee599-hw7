#include <iostream>
#include "src/lib/solution.h"

int main() {
    std::map<int, std::set<int>> vertices = {
    {8, {2, 6,}},
    {7, {5, 6}},
    {6, {5, 7, 8}},
    {5, {0, 6}},
    {4, {0}},
    {3, {1, 2}},
    {2, {1, 3, 8}},
    {1, {0, 1, 2}},
    {0, {1, 4, 5}}
    };
    Graph g(vertices);
    std::vector<bool> n_in_p = nodes_in_path(g);
    printf("nodes lying in the shortest path from node 0 to node %d: ", (int)g.v_.size() - 1);
    for(int i = 0; i < (int)n_in_p.size(); i++)
    {
        if(n_in_p[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}