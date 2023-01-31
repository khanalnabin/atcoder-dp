#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> grid(H + 1);
	for (int i = 0; i <= H; i++) {
		grid[i] = vector<char>(W + 1);
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) {
				grid[i][j] = '#';
			} else {
				char c;
				cin >> c;
				grid[i][j] = c;
			}
		}
	}

	ll mod = 1000000007;
	vector<vector<ll>> dp(H + 1);
	for (int i = 0; i <= H; i++) {
		dp[i] = vector<ll>(W + 1);
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else {
				if (i == 1 && j == 1) {
					dp[i][j] = 1;
				} else {
					ll ways = 0;
					if (grid[i - 1][j] == '.') {
						ways += (dp[i - 1][j] % mod);
					}
					if (grid[i][j - 1] == '.') {
						ways += (dp[i][j - 1] % mod);
					}
					dp[i][j] = ways;
				}
			}
		}
	}
	cout << dp[H][W] % (mod) << endl;
}
