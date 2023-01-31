#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int height[n];
  int cost[n];
  for (int i = 0; i < n; i++) {
    cost[i] = INT_MAX;
    cin >> height[i];
  }
  cost[0] = 0;
  for (int i = 0; i < n; i++) {
    if (i < (n - 1)) {
      cost[i + 1] = min(cost[i + 1], cost[i] + abs(height[i + 1] - height[i]));
    }
    if (i < (n - 2)) {
      cost[i + 2] = min(cost[i + 2], cost[i] + abs(height[i + 2] - height[i]));
    }
  }
  std::cout << cost[n - 1] << std::endl;
}
