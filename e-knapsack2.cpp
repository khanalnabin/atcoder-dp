#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18 + 5;
int main() {
	int n;
	ll w;
	cin >> n >> w;
	ll weights[n + 1];
	int values[n + 1];
	weights[0] = 0;
	values[0] = 0;
	int sum_values = 0;
	for (int i = 1; i <= n; i++) {
		cin >> weights[i] >> values[i];
		sum_values += values[i];
	}
	ll dp[n + 1][sum_values + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum_values; j++) {
			if (j == 0) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = INF;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum_values; j++) {
			dp[i][j] =
			    min(dp[i - 1][j], (j - values[i]) >= 0
			                          ? weights[i] + dp[i - 1][j - values[i]]
			                          : INF);
		}
	}
	ll answer = 0;
	for (ll j = 0; j <= sum_values; j++) {
		if (dp[n][j] <= w) {
			answer = max(answer, j);
		}
	}
	cout << answer << endl;
}
