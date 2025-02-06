#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  Edge (int a, int b, int c) {
    u = a, v = b, w = c;
  }
};

bool neg = false;
vector<Edge> E;
long long int dist[1009], n;

void bellman_ford (int s) {
  for (int i = 1; i <= n; i++) dist[i] = 1e18;
  dist[s] = 0;
  for (int i = 1; i < n; i++) {
      for (Edge e: E) {
          if (dist[e.v] > dist[e.u]+ e.w) dist[e.v] = dist[e.u] + e.w;
      }
  }
  for (Edge e: E) {
      if (dist[e.v] > dist[e.u]+ e.w) {
          neg = true;
      }
  }
}

int main () {
  int n, e, s;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      E.push_back(Edge(a,b,c));
  }
  cin >> s;
  bellman_ford (s);
  if (neg == true) cout << "Negative Cycle Detected\n";
}
