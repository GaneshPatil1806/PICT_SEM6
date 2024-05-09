#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cout << "Enter the number of vertices" << endl;
    cin >> n;

    cout << "Enter the number of edges" << endl;
    cin >> e;

    vector<vector<pair<int, int>>> adj(n + 1);

    cout << "Enter the edges(a,b), cost" << endl;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // taking starting vertex as 1
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mina = INT_MAX;
        int u;

        for (int j = 1; j <= n; j++)
        {
            if (mst[j] == false && key[j] < mina)
            {
                u = j;
                mina = key[j];
            }
        }

        mst[u] = true;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << parent[i] << ' ' << key[i] << endl;
    }

    return 0;
}