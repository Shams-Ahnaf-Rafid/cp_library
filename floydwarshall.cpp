#include <bits/stdc++.h>
using namespace std;

const int nmax = 500;

long long int dist[nmax][nmax];

void floydwarshall(int v){
    for(int k = 1; k<=v; k++){
        for(int i = 1; i<= v; i++){
            for(int j = 1; j<=v; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int u = 1; u <= n; u++) {
        for(int v = 1; v <= n; v++){
            if(u == v) {
                dist[u][v] = 0;
            }
            else {
                dist[u][v] = 1e18;
            }
        }
    }
    for(int i = 0; i<m; i++){
        int u, v;
        long long int c;
        cin>>u>>v>>c;
        dist[u][v] = min(c, dist[u][v]);

    }

    floydwarshall(n);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
3 3
1 2 1
2 3 2
3 1 5
*/
