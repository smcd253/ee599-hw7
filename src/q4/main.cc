#include <iostream>
#include "src/lib/solution.h"

int main() {
    std::map<int, std::set<int>> vertices = {
    {7, {5, 6}},
    {5, {2, 4}},
    {6, {3, 4}},
    {4, {}},
    {3, {1}},
    {2, {1}},
    {1, {0}},
    {0, {}}
    };
    Graph g(vertices);
    std::pair<std::set<int>, std::vector<int>> top = g.topological_sort();
    printf("topological sort results:\n");
    printf("Root nodes: ");
    for(auto& r : top.first)
    {
        printf("%d ", r);
    }
    printf("\nTopological order: ");
    for(auto& n : top.second)
    {
        printf("%d ", n);
    }
    printf("\n");
}