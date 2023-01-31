#include <bits/stdc++.h>
using namespace std;

// macros
#define ll long long
#define printarr(name, i, j, value)                                            \
	cout << name << "[" << i << "][" << j << "] : " << value << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i < n; i++)
//-------
ll modvalue = 1000000007;

template <typename T> using vec = vector<T>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vec<int> each(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> each[i];
	}

	// dp[i][j] : the no of ways to divide j candies if only first i persons are
	// considered
	vec<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		vec<ll> ps(K + 1);
		ps[0] = dp[i - 1][0];
		for (int j = 1; j <= K; j++) {
			ps[j] = (ps[j - 1] + dp[i - 1][j]) % modvalue;
		}
		for (int j = 0; j <= K; j++) {
			if (j > each[i])
				dp[i][j] = (ps[j] + modvalue - ps[j - each[i] - 1]) % modvalue;
			else
				dp[i][j] = ps[j];
		}
	}

	for (int i = 1; i <= N; i++) {
		vec<ll> ps(K + 1);
		ps[0] = dp[i - 1][0];
		for (int j = 1; j <= K; j++) {
			ps[j] = (ps[j - 1] + dp[i - 1][j]) % modvalue;
		}
		for (int j = 0; j <= K; j++) {
			/* if (j > each[i])                                                 */
			/* 	dp[i][j] = (ps[j] + modvalue - ps[j - each[i] - 1]) % modvalue; */
			/* else                                                             */
			/* 	dp[i][j] = ps[j];                                               */
			for(int count  = 0; count <= N ; count++){
				
			}
		}
	}
	cout << dp[N][K] << endl;
	/* for (int i = 0; i <= N; i++) {  */
	/* 	for (int j = 0; j <= K; j++) { */
	/* 		cout << dp[i][j] << " ";      */
	/* 	}                              */
	/* 	cout << endl;                  */
	/* }                               */
}
