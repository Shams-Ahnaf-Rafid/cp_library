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

pair<int, int> edge_vertices[nmax];     /// edge_vertices[1] = 1st edge (u, v)


/// E log E
int main(){

    int v, e;
    cin>>v>>e;

    for(int i = 1; i<=v; i++) makeset(i);


    vector< pair<int, int> > edges;

    for(int i = 0; i<e; i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge_vertices[i].first = a;
        edge_vertices[i].second = b;
        edges.push_back(make_pair(c, i));
    }



    sort(edges.begin(), edges.end());
    ///reverse(edges.begin(), edges.end());  /// for maximum spanning tree


    int mst_cost = 0;
    int edge_cnt = 0;

    for(auto E : edges){
        int u = edge_vertices[E.second].first;
        int v = edge_vertices[E.second].second;

        if(fnd(u) == fnd(v)) continue;      /// dsu

        unite(u, v);            /// dsu
        mst_cost += E.first;
        edge_cnt++;

        ///cout<<"taking "<<u<<" "<<v<<" with cost "<<E.first<<endl;
    }

    if(edge_cnt == v-1)
        cout<<mst_cost;
    else
        cout<<"no mst"<<endl;

}
