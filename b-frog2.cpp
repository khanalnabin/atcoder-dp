#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int cost[n], height[n];
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		cost[i] = INT_MAX;
	}
	cost[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if ((i + j) < n) {
				cost[i + j] =
					min(cost[i + j], cost[i] + abs(height[i + j] - height[i]));
			}
		}
	}
	cout << cost[n - 1] << endl;
}
