#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ent[n][3];
	for (int i = 0; i < n; i++) {
		cin >> ent[i][0] >> ent[i][1] >> ent[i][2];
	}

	int dp[n][3];
	for (int i = 0; i < 3; i++) {
		dp[0][i] = ent[0][i];
	}

	// every dp is the sum of its current entertainment and 
	// the max of the entertainments that can come there
	for (int i = 1; i < n; i++) {
		dp[i][0] = ent[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = ent[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = ent[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}
