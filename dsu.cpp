#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

int master[nmax], sz[nmax];

void makeset(int u){
    master[u] = u;
    sz[u] = 1;
}

int fnd(int u){
    if(master[u] == u) return u;
    return master[u] = fnd(master[u]);
}

bool unite(int u, int v){
    u = fnd(u);
    v = fnd(v);
    if(u == v) return false;

    if(sz[u] < sz[v]){
        master[u] = v;
        sz[v] += sz[u];
    }
    else{
        master[v] = u;
        sz[u] += sz[v];
    }
    return true;
}
