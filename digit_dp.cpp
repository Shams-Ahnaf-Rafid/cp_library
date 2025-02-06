#include<bits/stdc++.h>
using namespace std;

int dp[10][10][20][2][2][2];
vector<int>v1,v2;

// v1 boro_number, v2 choto_number

int chk(int mn, int mx, int i, int bt1, int bt2, int suru) {
    if(i < 0) return 1;
    int &ans = dp[mn][mx][i][bt1][bt2][suru];
    if(ans != -1) return ans;
    ans = 0;
    for(int j = 0; j <= 9; j++) {
        if(bt1 == 0 && j > v1[i]) continue;
        if(bt2 == 0 && j < v2[i]) continue;
        if(j == 0 && suru == 0) {
                int bt11 = bt1|(j < v1[i]);
            ans|=chk(mn, mx,i-1,bt11, bt2,0);
        }
            if(j < mn || j > mx) continue;
            int bt11 = bt1|(j < v1[i]);
            int bt22 = bt2|(j > v2[i]);
            ans|=chk(mn, mx,i-1,bt11,bt22,1);
    }
    return ans;
}

vector<int>ans;
void walk(int mn, int mx, int i, int bt1, int bt2, int suru) {
    if(i < 0) return;
    for(int j = 0; j <= 9; j++) {
        if(bt1 == 0 && j > v1[i]) continue;
        if(bt2 == 0 && j < v2[i]) continue;
        if(j == 0 && suru == 0) {
                int bt11 = bt1|(j < v1[i]);
            int ans=chk(mn, mx,i-1,bt11, bt2,0);
            if(ans) {
                walk(mn, mx, i-1, bt11, bt2, 0);
                return;
            }
        }
            if(j < mn || j > mx) continue;
            int bt11 = bt1|(j < v1[i]);
            int bt22 = bt2|(j > v2[i]);
            int anss=chk(mn, mx,i-1,bt11,bt22,1);
            if(anss) {
                ans.push_back(j);
                walk(mn, mx, i-1, bt11, bt22, 1);
                return;
            }
    }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
      long long int l, r, e = 0;
      cin >> l >> r;
      v1.clear();
      v2.clear();
      ans.clear();
      memset(dp, -1, sizeof(dp));
      while (v2.size() <= 19) {
          v2.push_back(l%10);
          l /= 10;
          v1.push_back(r%10);
          r /= 10;
      }
      for (int i = 0; i <= 9; i++) {
          for (int j = 0; j <= 9; j++) {
              if (j+i > 9) break;
              int f = chk (j, j+i, 19, 0, 0, 0);
              if (f) {
                  walk (j, j+i, 19, 0, 0, 0);
                  e = 1;
                  break;
              }
          }
          if (e) break;
      }
      e = 0;
      for (int i = 0; i < ans.size(); i++) {
          if (ans[i] == 0 && e == 0) continue;
          else {
              cout << ans[i];
              e = 1;
          }
      }
      cout << "\n";
  }
}
