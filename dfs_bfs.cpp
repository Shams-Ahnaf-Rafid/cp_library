#include <bits/stdc++.h>
using namespace std;
vector<int>graph[200009];
bool vis[200009];
int dis[200009];

// dfs

void dfs(int s){
  vis[s] = 1;
  for(int x:graph[s]) {
    if (!vis[x]) dfs(x);
  }
}

// bfs

void bfs(int source){
  queue<int>Q;
  dis[source]=0;
  Q.push(source);
  while(!Q.empty()){
    int node=Q.front();
    Q.pop();
    for(auto next : graph[node]){
        if(dis[next] == -1){
            dis[next]=dis[node]+1;
            Q.push(next);
        }
    }
  }
}

int main () {
}


