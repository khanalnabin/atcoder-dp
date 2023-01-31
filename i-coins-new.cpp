#include <bits/stdc++.h>

using namespace std;

using veci = vector<int>;
using vecf = vector<double>;

int main() {
	int n;
	cin >> n;

	vector<double> p(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	vector<double> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = p[i] * dp[i - 1];
		for (int j = i - 1; j >= 0; --j) {
			dp[j] = (dp[j] * (1 - p[i])) + (j >= 1 ? ((dp[j - 1]) * p[i]) : 0);
		}
	}
	double result = 0;
	for (int i = int(n / 2) + 1; i <= n; i++) {
		result += dp[i];
	}
	cout << setprecision(10) << result << endl;
}
