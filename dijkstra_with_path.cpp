#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

vector<pair<int, int>> adj[nmax];
int dist[nmax];
int link[nmax];

using pii = pair<int, int>;

void dijkstra(int source, int n){
    for(int i = 1; i<=n; i++)
        dist[i] = 1e9 + 10;

    dist[source] = 0;

    priority_queue< pii , vector<pii> , greater<pii> > pq;

    pq.push({0, source});

    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();

        int d = p.first;
        int u = p.second;

        if(dist[u] != d){
            continue;
        }

        for(auto q : adj[u]){
            int c = q.first;
            int v = q.second;

            if(d + c < dist[v]){
                dist[v] = d+c;
                link[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

/// 1e5 edge, cost: 1e4   total => 1e9

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;     /// edge u, v with cost w
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dijkstra(1, n);

    for(int i = 1; i<=n; i++){
        cout<<"distance to "<<i<<" = "<<dist[i]<<endl;
    }

    int current = n;

    vector<int> path;
    path.push_back(n);


    while(current != 1){
        current = link[current];
        path.push_back(current);
    }

    reverse(path.begin(), path.end());

    for(int x : path){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}

/*

5 8
1 5 5
1 4 2
1 3 5
1 2 3
2 5 6
2 3 1
3 4 10
4 5 2

*/
