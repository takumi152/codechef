#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  vector<int> N(T), M(T);
  for (int i = 0; i < T; i++) {
    cin >> N[i] >> M[i];
  }

  vector<string> ans(T);
  for (int i = 0; i < T; i++) {
    if (N[i] % 2 == 1 && M[i] % 2 == 1) {
      ans[i] = "NO";
    }
    else {
      ans[i] = "YES";
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
