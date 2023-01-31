#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	int n;
	ll w;
	cin >> n >> w;
	int values[n + 1];
	ll weights[n + 1];
	values[0] = 0;
	weights[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		cin >> weights[i] >> values[i];
	}
	ll *dp[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new ll[w + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (ll j = 0; j <= w; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (ll j = 1; j <= w; j++) {
			dp[i][j] =
			    max(dp[i - 1][j], j - weights[i] >= 0
			                          ? dp[i - 1][j - weights[i]] + values[i]
			                          : 0);
		}
	}
	ll m = dp[0][w];
	for (int i = 1; i <= n; i++) {
		m = max(m, dp[i][w]);
	}
	cout << m << endl;
}
