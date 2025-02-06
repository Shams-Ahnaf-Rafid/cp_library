const int MX = 2009;
int ans;

vector<int>graph[MX];
bool vis[MX];
int col[MX];

void dfs(int s){
  vis[s]=1;
  for(int i=0;i<graph[s].size();i++){
    int x=graph[s][i];
    if(!vis[x]){
            if (col[s] == 1) col[x] = 2;
            else col[x] = 1;
            dfs(x);
    }
    else {
            if (col[s] == col[x]) ans = 1;
    }
  }
}
// if ans == 1 it is not a bipartite graph

