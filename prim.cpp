#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;
vector<pair<int, int>> adj[nmax]; /// (neighbour, cost)

int dist[nmax];
bool completed[nmax];

/// O(E log V)
void prim(int root, int n){
    for(int i= 1; i<=n; i++) dist[i] = 1e9, completed[i] = false;
    dist[root] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; /// (dist, node)

    pq.push(make_pair(0, root));

    while(!pq.empty()){
        int u = pq.top().second;
        int c = pq.top().first;

        if(completed[u]) continue;
        completed[u] = true;

        pq.pop();


        for(auto e : adj[u]){
            if(dist[e.first] > e.second){
                dist[e.first] = e.second;
                pq.push(make_pair(e.first, e.second));
            }
        }
    }
}

int main(){
    int V, E;
    cin>>V>>E;

    for(int i = 0; i<E; i++){
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }


    prim(1, V);
}
