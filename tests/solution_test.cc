#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <string>       // std::string
#include <iostream>     // CaptureStdout

/*************************** Graph::shortest_distance ***************************/
TEST(GRAPH_SHORTEST_DISTANCE, STANDARD)
{
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

    std::map<int, int> actual = g.shortest_distance(root);
    std::map<int, int> expected = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 1},
        {6, 3}
    };

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_DISTANCE, EMPTY)
{
    std::map<int, std::set<int>> vertices;
    Graph g(vertices);
    int root = 0;

    std::map<int, int> actual = g.shortest_distance(root);
    std::map<int, int> expected;

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_DISTANCE, VERTEX_OOB)
{
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
    int root = -1;

    std::map<int, int> actual = g.shortest_distance(root);
    std::map<int, int> expected;

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_DISTANCE, DISCONNECTED)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1, 2, 5}},
    {1, {0, 2}},
    {2, {0, 1}},
    {3, {4, 6}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
    };
    Graph g(vertices);
    int root = 0;

    std::map<int, int> actual = g.shortest_distance(root);
    std::map<int, int> expected = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, INT_MAX},
        {4, INT_MAX},
        {5, 1},
        {6, INT_MAX}

    };

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_DISTANCE, CYCLIC)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2}},
    {2, {3}},
    {3, {0}}
    };
    Graph g(vertices);
    int root = 0;

    std::map<int, int> actual = g.shortest_distance(root);
    std::map<int, int> expected = {
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 3}
    };

    EXPECT_EQ(actual, expected);
}

/*************************** Graph::shortest_path ***************************/
TEST(GRAPH_SHORTEST_PATH, STANDARD)
{
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

    std::map<int, std::vector<int>> actual = g.shortest_path(root);
    std::map<int, std::vector<int>> expected = {
        {0, {0}},
        {1, {0, 1}},
        {2, {0, 2}},
        {3, {0, 1, 3}},
        {4, {0, 1, 3, 4}},
        {5, {0, 5}},
        {6, {0, 1, 3, 6}}
    };

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_PATH, EMPTY)
{
    std::map<int, std::set<int>> vertices;
    Graph g(vertices);
    int root = 0;

    std::map<int, std::vector<int>> actual = g.shortest_path(root);
    std::map<int, std::vector<int>> expected;

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_PATH, VERTEX_OOB)
{
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
    int root = -1;

    std::map<int, std::vector<int>> actual = g.shortest_path(root);
    std::map<int, std::vector<int>> expected;

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_PATH, DISCONNECTED)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1, 2, 5}},
    {1, {0, 2}},
    {2, {0, 1}},
    {3, {4, 6}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
    };
    Graph g(vertices);
    int root = 0;

    std::map<int, std::vector<int>> actual = g.shortest_path(root);
    std::map<int, std::vector<int>> expected = {
        {0, {0}},
        {1, {0, 1}},
        {2, {0, 2}},
        {5, {0, 5}}
    };

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_SHORTEST_PATH, CYCLIC)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2}},
    {2, {3}},
    {3, {0}}
    };
    Graph g(vertices);
    int root = 0;

    std::map<int, std::vector<int>> actual = g.shortest_path(root);
    std::map<int, std::vector<int>> expected = {
        {0, {0}},
        {1, {0, 1}},
        {2, {0, 1, 2}},
        {3, {0, 1, 2, 3}}
    };

    EXPECT_EQ(actual, expected);
}

/*************************** Graph::topological_sort ***************************/
TEST(GRAPH_TOPOLOGICAL_SORT, STANDARD)
{
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

    std::pair<std::vector<int>, std::vector<int>> actual = g.topological_sort();
    std::vector<int> expected_roots = {7};
    std::vector<int> expected_top_sort = {7, 5, 6, 2, 3, 4, 1, 0};
    std::pair<std::vector<int>, std::vector<int>> expected(expected_roots, expected_top_sort);

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_TOPOLOGICAL_SORT, EMPTY)
{
    std::map<int, std::set<int>> vertices;
    Graph g(vertices);

    std::pair<std::vector<int>, std::vector<int>> actual = g.topological_sort();
    std::vector<int> expected_roots = {};
    std::vector<int> expected_top_sort = {};
    std::pair<std::vector<int>, std::vector<int>> expected(expected_roots, expected_top_sort);

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_TOPOLOGICAL_SORT, DISCONNECTED)
{
    std::map<int, std::set<int>> vertices = {
    {7, {5, 6}},
    {5, {4}},
    {6, {4}},
    {4, {}},
    {3, {1}},
    {2, {1}},
    {1, {0}},
    {0, {}}
    };
    Graph g(vertices);

    std::pair<std::vector<int>, std::vector<int>> actual = g.topological_sort();
    std::vector<int> expected_roots = {2, 3, 7};
    std::vector<int> expected_top_sort = {2, 3, 7, 1, 5, 6, 0, 4};
    std::pair<std::vector<int>, std::vector<int>> expected(expected_roots, expected_top_sort);

    EXPECT_EQ(actual, expected);
}


TEST(GRAPH_TOPOLOGICAL_SORT, CYCLIC)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2}},
    {2, {3}},
    {3, {0}}
    };
    Graph g(vertices);

    std::pair<std::vector<int>, std::vector<int>> actual = g.topological_sort();
    std::vector<int> expected_roots = {};
    std::vector<int> expected_top_sort = {};
    std::pair<std::vector<int>, std::vector<int>> expected(expected_roots, expected_top_sort);

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_TOPOLOGICAL_SORT, HAS_CYCLE)
{
    std::map<int, std::set<int>> vertices = {
    {7, {5, 6}},
    {5, {4}},
    {6, {3, 4}},
    {4, {2}},
    {3, {1}},
    {2, {1, 5}},
    {1, {0}},
    {0, {}}
    };
    Graph g(vertices);

    std::pair<std::vector<int>, std::vector<int>> actual = g.topological_sort();
    std::vector<int> expected_roots = {7};
    std::vector<int> expected_top_sort = {};
    std::pair<std::vector<int>, std::vector<int>> expected(expected_roots, expected_top_sort);

    EXPECT_EQ(actual, expected);
}

TEST(GRAPH_TOPOLOGICAL_SORT, UNDIRECTED)
{
    std::map<int, std::set<int>> vertices = {
    {7, {5, 6}},
    {5, {2, 4, 7}},
    {6, {3, 4, 7}},
    {4, {5, 6}},
    {3, {1, 6}},
    {2, {1, 5}},
    {1, {0, 2, 3}},
    {0, {1}}
    };
    Graph g(vertices);

    std::pair<std::vector<int>, std::vector<int>> actual = g.topological_sort();
    std::vector<int> expected_roots = {};
    std::vector<int> expected_top_sort = {};
    std::pair<std::vector<int>, std::vector<int>> expected(expected_roots, expected_top_sort);

    EXPECT_EQ(actual, expected);
}

/*************************** nodes_in_path ***************************/
TEST(NODES_IN_PATH, STANDARD)
{
    std::map<int, std::set<int>> vertices = {
    {8, {2, 6, 7}},
    {7, {5, 6}},
    {6, {5, 7, 8}},
    {5, {0, 6}},
    {4, {0}},
    {3, {1, 2}},
    {2, {1, 3, 8}},
    {1, {0, 2, 3}},
    {0, {1, 4, 5}}
    };
    Graph g(vertices);

    std::vector<bool> actual = nodes_in_path(g);
    std::vector<bool> expected = {true, true, true, false, false, true, true, false, true};

    EXPECT_EQ(actual, expected);
}

TEST(NODES_IN_PATH, EMPTY)
{
    std::map<int, std::set<int>> vertices;
    Graph g(vertices);

    std::vector<bool> actual = nodes_in_path(g);
    std::vector<bool> expected = {};

    EXPECT_EQ(actual, expected);
}

// should return false for all because no path exists from 0 to N-1
TEST(NODES_IN_PATH, DISCONNECTED_0_TO_NMIN1)
{
    std::map<int, std::set<int>> vertices = {
    {8, {}},
    {7, {5, 6}},
    {6, {5, 7}},
    {5, {0, 6}},
    {4, {0}},
    {3, {1, 2}},
    {2, {1, 3}},
    {1, {0, 2, 3}},
    {0, {1, 4, 5}}
    };
    Graph g(vertices);

    std::vector<bool> actual = nodes_in_path(g);
    std::vector<bool> expected = {false, false, false, false, false, false, false, false, false};

    EXPECT_EQ(actual, expected);
}

// should return false for all because no path exists from 0 to N-1
TEST(NODES_IN_PATH, DISCONNECTED_OTHER)
{
    std::map<int, std::set<int>> vertices = {
    {8, {2, 6, 7}},
    {7, {5, 6}},
    {6, {5, 7, 8}},
    {5, {0, 6}},
    {4, {0}},
    {3, {}},
    {2, {1, 8}},
    {1, {0, 2}},
    {0, {1, 4, 5}}
    };
    Graph g(vertices);

    std::vector<bool> actual = nodes_in_path(g);
    std::vector<bool> expected = {true, true, true, false, false, true, true, false, true};

    EXPECT_EQ(actual, expected);
}