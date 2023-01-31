#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T> using vec = vector<T>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  vec<int> move(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> move[i];
  }
  vec<int> winner(K + 1, 2);
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= N; j++) {
      if (move[j] > i)
        continue;
      if (winner[i - move[j]] == 2) {
        winner[i] = 1;
      }
    }
  }
  if (winner[K] == 1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}
