#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(1e5 + 1);

vector<int> memo(1e5 + 1, -1);

int func(int s) {
	if (memo[s] != -1) {
		return memo[s];
	}
	int value = 0;
	for (auto i : adj_list[s]) {
		value = max(value, 1 + func(i));
	}
	memo[s] = value;
	return value;
}

int main() {

	unsigned int n, m;
	cin >> n >> m;

	int in[n + 1];
	int dp[n + 1];

	for (int i = 0; i < m; i++) {
		int source, destination;
		cin >> source >> destination;
		adj_list[source].push_back(destination);
	}
	int max_length = -1;
	for (int i = 1; i <= n; i++) {
		max_length = max(max_length, func(i));
	}
	cout << max_length << endl;
}
