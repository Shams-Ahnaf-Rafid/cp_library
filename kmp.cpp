#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+10;

int failure[mx];

int kmp (string &s) {
  int cur = 0, mxcur = 0;
  failure[0] = cur;
  for (int i = 1; i < s.size(); i++) {
      while (cur != 0 && s[cur] != s[i]) cur = failure[cur-1];
      if (s[cur] == s[i]) ++cur;
      failure[i] = cur;
      mxcur = max(mxcur, cur);
  }
  return mxcur;
}

vector<int>adj[mx];

void build_prefix_tree (int n) {
  for (int i = 0; i < n; i++) {
      int par = failure[i];
      adj[par].push_back(i+1);
  }
}
/// kmp builds a prefix function which gives large prefix
/// size from the suffix of i (s[0......i])
/// 1. pattern matching
/// s = p+"$"+s , check pattern p in string s
/// 2. for a repeated string  s = abababab
/// failure function looks like = 00123456
/// 3. we can find border from kmp
/// iterating while loop from last element of failure function
/// 4. how many times all prefix of p in string s
/// count every failure value then
/// count from last count[failure[i]] += count[i] .....1 index

int main () {
  string s;
  cin >> s;
  kmp(s);
  build_prefix_tree (s.size());
}
