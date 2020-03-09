#include <iostream>
#include "src/lib/solution.h"

int main() {
    std::map<int, std::set<int>> vertices = {
    {0, {1, 2, 5}},
    {1, {0, 2, 3}},
    {2, {0, 1, 3}},
    {3, {1, 2, 6, 4}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
    };
    Graph g(vertices);
    int root = 0;
    std::map<int, int> dist = g.shortest_distance(root);
    printf("distance to all nodes from node %d: \n", root);
    for(auto& n : dist)
    {
        printf("distance to %d = %d\n ", n.first, n.second);
    }
    printf("\n");
    
    std::map<int, std::vector<int>> paths = g.shortest_path(root);

    printf("distance to all nodes from node %d: \n", root);
    for(auto& n : paths)
    {
        printf("path to %d: ", n.first);
        for(auto& p : n.second)
        {
            printf("%d ", p);
        }
        printf("\n");
    }
    printf("\n");
}