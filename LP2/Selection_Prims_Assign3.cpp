#include<bits/stdc++.h>
using namespace std;

void selection_sort()
{
    int n;
    cout<<"Enter the numbers:"<<endl;
    cin>>n;

    vector<int> v(n);
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int iter=0;

    for(int i=0;i<v.size();i++){
        int min=i;

        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(v[i],v[min]);
        }

        cout<<"Iteration "<<iter++<<endl;
        for(auto  i:v){
            cout<<i<<' ';
        }
        cout<<endl;
        cout<<"-------------------------"<<endl;
    }
}

void mst_prims() {
    int v;
    cout << "Enter the number of vertices" << endl;
    cin >> v;

    vector<vector<pair<int, int>>> adj(v);
    int edges;
    cout << "Enter the number of edges" << endl;
    cin >> edges;

    cout << "Enter the edges(a,b), cost" << endl;
    for (int i = 0; i < edges; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    cout << "Enter the starting vertex" << endl;
    int s, ans = 0;
    cin >> s;
    vector<bool> vis(v, false);

    vector<int> minWeight(v, INT_MAX);

    for (int i = 0; i < adj[s - 1].size(); i++) {
        minWeight[adj[s - 1][i].first] = min(adj[s - 1][i].second, minWeight[adj[s - 1][i].first]);
    }

    minWeight[s - 1] = 0;
    vis[s - 1] = true;

    int cnt = v - 1, j = 0;
    int last_vis = s - 1;

    while (j < cnt) {
        int min_dist = INT_MAX;
        int next_vertex = -1;

        for (int i = 0; i < v; i++) {
            if (!vis[i] && min_dist > minWeight[i]) {
                min_dist = minWeight[i];
                next_vertex = i;
            }
        }

        if (next_vertex == -1) {
            cout << "Graph is not connected!" << endl;
            return;
        }

        ans += min_dist;

        cout << "Visited Edge: " << last_vis << " -> " << next_vertex 
        << " with cost: " << min_dist << endl;

        for (int i = 0; i < adj[next_vertex].size(); i++) {
            if (!vis[adj[next_vertex][i].first])
                minWeight[adj[next_vertex][i].first] = min(adj[next_vertex][i].second, minWeight[adj[next_vertex][i].first]);
        }

        vis[next_vertex] = true;
        j++;
        last_vis = next_vertex;
    }

    cout << "Minimum Cost of Spanning Tree: " << ans << endl;
}

int main()
{
    int i=0;
    while(1)
    {
        cout<<"Enter the choice"<<endl;
        cout<<"1.Selection sort"<<endl;
        cout<<"2.Prim's"<<endl;
        cout<<"3.Exit"<<endl;
        int ch;
        cin>>ch;;

        switch (ch)
        {
            case 1:
                selection_sort();
                break;
            
            case 2:
                mst_prims();
                break;
            case 3:
                exit(1);

            default:
                break;
        }
        i++;
    }
}