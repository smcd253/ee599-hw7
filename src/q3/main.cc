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
    std::vector<int> dfs_v = g.dfs(0);
    printf("dfs_v = ");
    for(auto n : dfs_v)
    {
        printf("%d ", n);
    }
    printf("\n");
}