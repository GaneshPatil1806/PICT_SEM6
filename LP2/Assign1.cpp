#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) {
        vertices = v;
        adjacencyList.resize(vertices+1);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); 
    }

    // Recursive DFS
    void dfsRecursive(int start) {
        unordered_set<int> visited;
        dfsRecursive(start, visited);
    }

    void dfsRecursive(int current, unordered_set<int>& visited) {
        visited.insert(current);
        cout << current << " ";

        for (int neighbor : adjacencyList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    // Iterative DFS
    void dfsIterative(int start) {
        unordered_set<int> visited;
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (visited.find(current) == visited.end()) {
                cout << current << " ";
                visited.insert(current);

                for (int neighbor : adjacencyList[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }
    }

    // Iterative BFS
    void bfsIterative(int start) {
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
    cout << "2. DFS (Recursive)" << endl;
    cout << "3. DFS (Iterative)" << endl;
    cin >> choice;

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    switch (choice) {
        case 1:
            cout << "BFS traversal starting from node " << startNode << ": ";
            graph.bfsIterative(startNode);
            break;
        case 2:
            cout << "DFS (Recursive) traversal starting from node " << startNode << ": ";
            graph.dfsRecursive(startNode);
            break;
        case 3:
            cout << "DFS (Iterative) traversal starting from node " << startNode << ": ";
            graph.dfsIterative(startNode);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
