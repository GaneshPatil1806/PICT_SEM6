#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int inf = 1e18;
const int ninf = -1e18;
const int limit = 1e7;

void dijkstra() {

    int n,e;
    cin>>n>>e;

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    vector<int> dist(n,inf);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,0});
    dist[0]=0;

    while(!pq.empty()){

        pair<int,int> a=pq.top();
        pq.pop();

        int w=a.first;
        int u=a.second;

        for(auto i:adj[u]){
            int v=i.first;
            int d=i.second;

            int new_dist = d+w;
            if(dist[v]>new_dist){
                dist[v]=new_dist;
                pq.push({new_dist,v});
            }
        }
        
    }

    cout<<"Distance"<<endl;
    for(auto i:dist){
        cout<<i<<' ';
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    dijkstra();
    return 0;
}