#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T> using vec = vector<T>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vec<ll> points(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i];
	}

	vec<vec<ll>> dp(N, vec<ll>(N, 0));
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			if (i == j) {
				dp[i][j] = points[i];
				/* printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]); */
			} else {
				dp[i][j] =
				    max((points[i] - dp[i + 1][j]), (points[j] - dp[i][j - 1]));
				/* printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]); */
			}
		}
	}
	cout << dp[0][N - 1] << endl;
}
