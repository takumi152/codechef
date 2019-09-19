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
  vector<int> N(T);
  vector<vector<vector<int> > > A(T), B(T);
  for (int i = 0; i < T; i++) {
    cin >> N[i];
    A[i] = vector<vector<int> >(N[i], vector<int>(N[i]));
    B[i] = vector<vector<int> >(N[i], vector<int>(N[i]));
    for (int j = 0; j < N[i]; j++) {
      for (int k = 0; k < N[i]; k++) {
        cin >> A[i][j][k];
      }
    }
    for (int j = 0; j < N[i]; j++) {
      for (int k = 0; k < N[i]; k++) {
        cin >> B[i][j][k];
      }
    }
  }

  vector<string> ans(T);
  for (int t = 0; t < T; t++) {
    vector<bool> noflip(N[t]), flip(N[t]);
    bool valid = true;
    // diagonal
    for (int i = 0; i < N[t]; i++) {
      if (A[t][i][i] != B[t][i][i]) {
        valid = false;
        break;
      }
    }
    if (!valid) {
      ans[t] = "No";
      continue;
    }
    // first row / column
    for (int i = 1; i < N[t]; i++) {
      if (A[t][i][0] == B[t][i][0] && A[t][0][i] == B[t][0][i]) {
        noflip[i] = true;
        //cerr << "f" << " " << i << " " << i << endl;
      }
      if (A[t][i][0] == B[t][0][i] && A[t][0][i] == B[t][i][0]) {
        flip[i] = true;
        //cerr << "nf" << " " << i << " " << i << endl;
      }
      if (!noflip[i] && !flip[i]) {
        valid = false;
        break;
      }
    }
    if (!valid) {
      ans[t] = "No";
      continue;
    }
    // other row / column
    for (int i = 1; i < N[t]; i++) {
      for (int j = i+1; j < N[t]; j++) {
        if ((flip[i] && flip[j]) || (noflip[i] && noflip[j])) {
          //cerr << "s" << endl;
          if (A[t][i][j] == B[t][i][j] && A[t][j][i] == B[t][j][i]) {
            if (A[t][i][j] == B[t][j][i] && A[t][j][i] == B[t][i][j]) continue;
            else if ((flip[i] && flip[j]) && (noflip[i] && noflip[j])) continue;
            else if ((flip[i] && flip[j])) {
              noflip[i] = false;
              noflip[j] = false;
              //cerr << "snf" << " " << i << " " << j << endl;
            }
            else if ((noflip[i] && noflip[j])) {
              flip[i] = false;
              flip[j] = false;
              //cerr << "sf" << " " << i << " " << j << endl;
            }
            continue;
          }
        }
        if ((noflip[i] && flip[j]) || (flip[i] && noflip[j])) {
          //cerr << "d" << endl;
          if (A[t][i][j] == B[t][j][i] && A[t][j][i] == B[t][i][j]) {
            if (A[t][i][j] == B[t][i][j] && A[t][j][i] == B[t][j][i]) continue;
            else if ((flip[i] && flip[j]) && (noflip[i] && noflip[j])) continue;
            else if ((flip[i] && noflip[j])) {
              noflip[i] = false;
              flip[j] = false;
              //cerr << "dnf" << " " << i << " " << j << endl;
            }
            else if ((noflip[i] && flip[j])) {
              flip[i] = false;
              noflip[j] = false;
              //cerr << "df" << " " << i << " " << j << endl;
            }
            continue;
          }
        }
        valid = false;
        break;
      }
      if (!valid) break;
    }
    if (!valid) {
      ans[t] = "No";
      continue;
    }
    ans[t] = "Yes";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
