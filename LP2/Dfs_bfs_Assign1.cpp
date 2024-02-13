#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph {
public:
    int vertices;
    list<int>* adjacencyList;

    Graph(int vertices) {
        this->vertices = vertices;
        adjacencyList = new list<int>[vertices];
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); 
    }

    void bfs(int start) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor : adjacencyList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }

    void dfs(int start) {
        unordered_set<int> visited;
        dfs(start, visited);
    }

private:
    void dfs(int current, std::unordered_set<int>& visited) {
        visited.insert(current);
        cout << current << " ";

        for (int neighbor : adjacencyList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited);
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int choice;
    cout << "Choose traversal method:" << endl;
    cout << "1. BFS" << endl;
    cout << "2. DFS" << endl;
    cin >> choice;

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    switch (choice) {
        case 1:
            cout << "BFS traversal starting from node " << startNode << ": ";
            graph.bfs(startNode);
            break;
        case 2:
            cout << "DFS traversal starting from node " << startNode << ": ";
            graph.dfs(startNode);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
