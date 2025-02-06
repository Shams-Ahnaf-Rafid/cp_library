#include <bits/stdc++.h>
using namespace std;

int dp[502][502];
 // Min additions to get "jazz" from index i to j
  // Inclusive and 0-indexed

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	for (int j = 0; j <= s.size(); j++) {
		for (int i = 0; i < s.size() - j; i++) {
			// Base case: We just duplicate s[i]
			dp[i][i + j] = dp[i + 1][i + j] + 1;
			for (int k = i + 1; k <= i + j; k++) {
				if (s[k] == s[i]) {  // We try match s[i] and s[k]
					dp[i][i + j] =
					    min(dp[i][i + j], dp[i + 1][k - 1] + dp[k + 1][i + j]);
				}
			}
		}
	}
	cout << dp[0][s.size() - 1] << '\n';
	return 0;
}

