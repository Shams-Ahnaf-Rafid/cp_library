#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+9;
const int alpha = 26;
int tsz;
int nxt[mx][alpha];
int parent[mx], EndCnt[mx], WordCnt[mx];

int MakeNode (int par) {
  if (par == -1) tsz = 0;
  parent[tsz] = par, EndCnt[tsz] = 0, WordCnt[tsz] = 0;
  memset (nxt[tsz], -1, sizeof(nxt[tsz]));
  int ret = tsz++;
  return ret;
}

int TrieInsert (string &s) {
  int cur = 0;
  WordCnt[cur]++;
  for (int i = 0; i < (int)s.size(); i++) {
      if (nxt[cur][s[i]-'a']  == -1) {
          nxt[cur][s[i]-'a'] = MakeNode(cur);
      }
      cur = nxt[cur][s[i]-'a'];
      WordCnt[cur]++;
  }
  EndCnt[cur]++;
  return cur;
}

int TrieSearch (string &s) {
  int cur = 0;
  for (int i = 0; i < (int)s.size(); i++) {
      if (nxt[cur][s[i]-'a'] == -1) return 0;
      cur = nxt[cur][s[i]-'a'];
  }
  return EndCnt[cur];
}

/// failure[u] = lowest node v  such that s(v) is a suffix of s(u)
int failure[mx], pathEndCnt[mx];
vector<int>adj[mx];

void Aho() {
  queue<int>q;
  failure[0] = -1;
  for (int i = 0; i < alpha; i++) {
      if (nxt[0][i] == -1) continue;
      failure[nxt[0][i]] = 0;
      q.push(nxt[0][i]);
  }
  while (!q.empty()) {
      int v = q.front();
      q.pop();
      pathEndCnt[v] += pathEndCnt[failure[v]] + EndCnt[v];
      for (int i = 0; i < alpha; i++) {
          if (nxt[v][i] == -1) continue;
          int n = nxt[v][i], cur = failure[v];
          while (cur != 0 && nxt[cur][i] == -1) cur = failure[cur];
          if (nxt[cur][i] != -1) cur = nxt[cur][i];
          failure[n] = cur;
          q.push(n);
      }
  }
//  for (int i = 0; i < tsz; i++) {
//      adj[failure[i]].push_back(i);        /// adj[i] contains nodes whose failure link is i
//  }
  return;
}

int visitcnt[mx];

int Aho_Search (string &s) {
  int cur = 0;
  int found = 0;
  for (int i = 0; i < (int)s.size(); i++) {
      while (cur != 0 && nxt[cur][s[i]-'a'] == -1) cur = failure[cur];
      if (nxt[cur][s[i]-'a'] != -1) cur = nxt[cur][s[i]-'a'];
      found += pathEndCnt[cur];
      visitcnt[cur]++;
  }
  return found;
}

int dfs (int root) {
  for (int n : adj[root]) {
      visitcnt[root] += dfs(n);
  }
  return visitcnt[root];
}

int main () {
  cin.tie(0) -> sync_with_stdio(0);
   MakeNode(-1);
   int p;
   cin >> p;
   string s;
   vector<int>ends;
   for (int i = 0; i < p; i++) {
      cin >> s;
      int x = TrieInsert(s);
      ends.push_back(x);
   }
   Aho();
   cin >> s;
   int cnt = Aho_Search(s);
   cout << cnt << endl;
   dfs(0);
   for (int x : ends) {
      cout << visitcnt[x] << "\n";
   }
}
