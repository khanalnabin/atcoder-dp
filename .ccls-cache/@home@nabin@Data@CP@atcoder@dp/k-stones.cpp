#include <bits/stdc++.h>
using namespace std;
int dp[100001][2];
bool canTaroChose(int n, int *a, int k, bool taro) {
	if (dp[k][taro] != -1) {
		return dp[k][taro];
	}
	if (k <= 0) {
		return !taro;
	}
	bool result;
	if (taro) {
		result = false;
		for (int i = 0; i < n; i++) {
			if (k - a[i] >= 0)
				result = canTaroChose(n, a, k - a[i], false) || result;
		}

	} else {
		result = true;
		for (int i = 0; i < n; i++) {
			if (k - a[i] >= 0)
				result = canTaroChose(n, a, k - a[i], true) && result;
		}
	}
	dp[k][taro] = result;
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}

	bool result = canTaroChose(n, a, k, true);
	if (result == true) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
}
