#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	int C1 = 0, C2 = 0, C3 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			C1++;
		} else if (x == 2) {
			C2++;
		} else if (x == 3) {
			C3++;
		}
	}
	double dp[n + 1][n + 1][n + 1];
	for (int c3 = 0; c3 <= C3; c3++) {
		for (int c2 = 0; c2 <= n; c2++) {
			for (int c1 = 0; c1 <= n; c1++) {
				int c0 = n - c1 - c2 - c3;
				if (c0 == n || c0 < 0) {
					dp[c1][c2][c3] = 0;
					continue;
				}
				double EB = 0, EC = 0, ED = 0, EA = 0;
				double pb = (double)c3 / n;
				double pc = (double)c2 / n;
				double pd = (double)c1 / n;
				if (c3 > 0) {
					EB = dp[c1][c2 + 1][c3 - 1];
				}
				if (c2 > 0) {
					EC = dp[c1 + 1][c2 - 1][c3];
				}
				if (c1 > 0) {
					ED = dp[c1 - 1][c2][c3];
				}
				EA = (1 + EB * pb + EC * pc + ED * pd) / (1 - (double)c0 / n);
				dp[c1][c2][c3] = EA;
				// cout << "dp["<<c1<<"]["<<c2<<"]["<<c3<<"] = " << EA << endl;
			}
		}
	}
	cout << setprecision(15) << dp[C1][C2][C3] << endl;
}
