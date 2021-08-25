#include <bits/stdc++.h>

using namespace std;
#define int long long

class Graph {
    map<int, vector<int>> graph;
public:
    void insert(int p, int q, bool bi);
    void dfs(int node);
};

void Graph::insert(int p, int q, bool bi = true) {
    graph[p].push_back(q);
    if (bi)
        graph[q].push_back(p);
}

void travel(int node, map<int, bool>& visited, map<int, vector<int>> graph) {
    cout << node << ", ";
    visited[node] = true;
    for (auto i : graph[node]) {
        if (not visited[i]) {
            travel(i, visited, graph);
        }
    }
}

void Graph::dfs(int node) {
    map<int, bool> visited;
    travel(node, visited, graph);
}

int32_t main() {
    Graph graph;
    graph.insert(1, 4);
    graph.insert(1, 3);
    graph.insert(4, 6);
    graph.insert(6, 7);
    graph.insert(6, 9);
    graph.insert(9, 3);
    graph.insert(3, 2);
    graph.dfs(1);

}