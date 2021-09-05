#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100000

void insert(map<int, vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dumpDataIntoGraph(map<int, vector<int>>& graph) {
    insert(graph, 1, 4);
    insert(graph,  4, 2);
    insert(graph, 2, 7);
    insert(graph, 7, 6);
    insert(graph, 7, 0);
    insert(graph, 0, 3);
    insert(graph, 0, 5);
    insert(graph, 6, 3);
    insert(graph, 3, 5);
    insert(graph, 0, 6);
}

void printList (map<int, vector<int>>& graph) {
    for (const auto& node : graph) {
        cout << node.first << ": ";
        for (auto neighbour: node.second)
            cout << neighbour << ", ";
        cout << endl;
    }
}

void dfsRecursive(map<int, vector<int>>& graph, map<int, bool>& visited, int node) {
    cout << node << ", ";
    visited[node] = true;
    for (auto neighbour: graph[node]) {
        if (not visited[neighbour]) {
            dfsRecursive(graph, visited, neighbour);
        }
    }
}

void dfsIterative(map<int, vector<int>>& graph, int start) {
    map<int, bool> visited;
    stack<int> s;
    s.push(start);
    while (not s.empty()) {
        int top = s.top();
        s.pop();
        visited[top] = true;
        cout << top << ", ";
        for (auto i : graph[top]) {
            if (not visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }

}

int32_t main() {
    map<int, vector<int>> graph;
    map<int, bool> visited;
    dumpDataIntoGraph(graph);
//    printList(graph);
    dfsRecursive(graph, visited, 0);

   
    dfsIterative(graph, 0);
}