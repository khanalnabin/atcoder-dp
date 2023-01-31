#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	const int one = s.length();
	const int two = t.length();
	cout << "One " << one << " Two: " << two << endl;
	string dp[one + 1][two + 1];
	for (int i = 0; i <= one; i++) {
		for (int j = 0; j <= two; j++) {
			dp[i][j] = "";
		}
	}

	for (int i = one - 1; i >= 0; i--) {
		for (int j = two - 1; j >= 0; j--) {
			if (s[i] == t[j]) {
				dp[i][j] = s[i] + dp[i + 1][j + 1];
			} else {
				if (dp[i + 1][j].length() > dp[i][j + 1].length()) {
					dp[i][j] = dp[i + 1][j];
				} else {
					dp[i][j] = dp[i][j + 1];
				}
			}
		}
	}
	cout << dp[0][0] << endl;
}
