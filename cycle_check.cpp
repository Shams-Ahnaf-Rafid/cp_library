
/// find cycle in undirected graph

bool cycle (int node, int par) {
    vis[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (!vis[child]) {
            if (cycle (child, node) == true) {
                    return true;
            }
        }
        else {
                if (child != par) {
                        return true;
                }
        }
    }
    return false;
}

/// which nodes are in cycle in undirected graph

int p[mx], c[mx];

/// c[i] = 1 means it is in a cylce

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == p[u]) continue;
        if (!vis[v]) {
            p[v] = u;
            dfs(v);
        }
        else if (!c[v]) {
            int x = u;
            while (x != v) {
                c[x] = 1;
                x = p[x];
            }
            c[v] = 1;
        }
    }
}

/// find cycle in directed graph
int color[200009];

void cycle(int v){
  color[v] = 1; // grey
  for(int w : graph[v]){
    if(color[w] == 1){
            c = 1;
    }
    if(color[w] == 0) cycle(w);
  }
  color[v] = 2; // black
}

for (int i = 1; i <= n; i++) {
        if (color[i] == 0) dfs(i); /// if color white then dfs
        /// don't clear graph here
}

