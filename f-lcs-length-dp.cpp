#include <bits/stdc++.h>

using namespace std;
struct element {
	int value;
	std::pair<int, int> parent;
};
int main() {
	string s, t;
	cin >> s >> t;
	const int one = s.length();
	const int two = t.length();
	element dp[one + 1][two + 1];
	for (int i = 0; i <= one; i++) {
		for (int j = 0; j <= two; j++) {
			dp[i][j] = {0, {-1, -1}};
		}
	}

	for (int i = one - 1; i >= 0; i--) {
		for (int j = two - 1; j >= 0; j--) {
			if (s[i] == t[j]) {
				dp[i][j] = {1 + dp[i + 1][j + 1].value, {i + 1, j + 1}};
			} else {
				if (dp[i + 1][j].value > dp[i][j + 1].value) {
					dp[i][j] = {dp[i + 1][j].value, {i + 1, j}};
				} else {
					dp[i][j] = {dp[i][j + 1].value, {i, j + 1}};
				}
			}
		}
	}
	int i = 0;
	int j = 0;
	string str;
	while (i < one && j < two) {
		element current = dp[i][j];
		if (s[i] == t[j]) {
			str += s[i];
		}
		i = current.parent.first;
		j = current.parent.second;
	}
	cout << str << endl;
}
