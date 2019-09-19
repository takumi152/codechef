#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

typedef long long int ll;
typedef tuple<int, int, int> Ti3;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  vector<int> R(T), C(T), K(T);
  for (int i = 0; i < T; i++) {
    cin >> R[i] >> C[i] >> K[i];
  }

  vector<int> ans(T);
  for (int t = 0; t < T; t++) {
    queue<Ti3> que;
    que.emplace(R[t]-1, C[t]-1, K[t]);
    vector<vector<bool> > visited(8, vector<bool>(8));
    while (!que.empty()) {
      auto now = que.front();
      que.pop();
      auto r = get<0>(now);
      auto c = get<1>(now);
      auto k = get<2>(now);
      if (k < 0) break;
      if (visited[r][c]) continue;
      visited[r][c] = true;
      if (r > 0) {
        que.emplace(r-1, c, k-1);
        if (c > 0) que.emplace(r-1, c-1, k-1);
        if (c < 7) que.emplace(r-1, c+1, k-1);
      }
      if (r < 7) {
        que.emplace(r+1, c, k-1);
        if (c > 0) que.emplace(r+1, c-1, k-1);
        if (c < 7) que.emplace(r+1, c+1, k-1);
      }
      if (c > 0) que.emplace(r, c-1, k-1);
      if (c < 7) que.emplace(r, c+1, k-1);
    }
    int count = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (visited[i][j]) count++;
      }
    }
    ans[t] = count;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
