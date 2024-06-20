#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, m;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n >> m;
    vector<vector<int>>
      ar(n, vector<int>(m)),
      br(n, vector<int>(m)),
      ac(m, vector<int>(n)),
      bc(m, vector<int>(n));

    for (u32 i = 0; i < n; ++i) {
      for (u32 j = 0; j < m; ++j) {
        cin >> ar[i][j];
        ac[j][i] = ar[i][j];
      }
    }
    for (u32 i = 0; i < n; ++i) {
      for (u32 j = 0; j < m; ++j) {
        cin >> br[i][j];
        bc[j][i] = br[i][j];
      }
    }
    for (u32 i = 0; i < n; ++i) {
      sort(ar[i].begin(), ar[i].end());
      sort(br[i].begin(), br[i].end());
    }
    sort(ar.begin(), ar.end());
    sort(br.begin(), br.end());
    for (u32 j = 0; j < m; ++j) {
      sort(ac[j].begin(), ac[j].end());
      sort(bc[j].begin(), bc[j].end());
    }
    sort(ac.begin(), ac.end());
    sort(bc.begin(), bc.end());
    cout << (ar == br && ac == bc ? "YES\n" : "NO\n");
  }
}
