#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> visited(1e5 + 1, 0);

vector<vector<int>> adj_list(1e5 + 1);

vector<int> dp(1e5 + 1, 0);

vector<int> in(1e5 + 1, 0);

void func(int s) {
	visited[s] = true;
	for (auto i : adj_list[s]) {
		dp[i] = max(dp[s] + 1, dp[i]);
		in[i]--;
		if (in[i] == 0 && !visited[i]) {
			func(i);
		}
	}
}

int main() {
	unsigned int n, m;
	cin >> n >> m;

	dp[0] = 0;
	in[0] = 0;

	for (int i = 1; i <= n; i++) {
		in[i] = 0;
		dp[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int source, destination;
		cin >> source >> destination;
		in[destination]++;
		adj_list[source].push_back(destination);
	}
	for (int k = 1; k <= n; k++) {
		if (in[k] == 0 && !visited[k]) {
			func(k);
		}
	}
	int max_value = -1;
	for (int i = 1; i <= n; i++) {
		max_value = max(max_value, dp[i]);
	}
	cout << max_value << endl;
}
