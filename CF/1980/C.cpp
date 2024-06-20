#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, i, n, a[(u32)2e5], b[(u32)2e5], m, d[(u32)2e5], df;
static bool yes, p;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = true, df = 0;
    map<u32, vector<u32>> dm;
    set<u32> ab;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 0; i < n; ++i) cin >> b[i];
    cin >> m;
    for (i = 0; i < m; ++i) { cin >> d[i]; dm[d[i]].push_back(i); }
    int x = d[m - 1];
    for (i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        if (dm.count(b[i]) && dm[b[i]].size()) {
          ++df;
          d[dm[b[i]].back()] = -1;
          dm[b[i]].pop_back();
        } else {
          yes = false;
          goto print;
        }
      } else
        ab.insert(a[i]);
    }
    p = false;
    for (i = 0; i < n; ++i) {
      if (x == b[i]) p = true;
    }
print:
    cout << (yes && p? "YES\n" : "NO\n");
  }
}
