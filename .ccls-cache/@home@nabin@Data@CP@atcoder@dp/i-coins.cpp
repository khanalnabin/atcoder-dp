#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename t> using vec = vector<t>;

int main() {
	int n;
	cin >> n;
	vec<float> p(n);
	for (auto &i : p) {
		cin >> i;
	}
	vec<float> dp(n, 0);
	dp[0] = p[0];
	ll allproduct = p[0];
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			dp[i] = allproduct;
			dp[i] += (dp[i - 1] - allproduct) * p[i];
		} else {
			dp[i] = (dp[i - 1] - allproduct) * p[i] + allproduct;
		}
		allproduct *= p[i];
	}
	for (int i = 0; i < n; i++) {
		cout << dp[i] << endl;
	}
}
