#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 200'001;
static i64 k;
static i32 TC, n, op, opc, a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    /* Observing the pattern
    vector<vector<vector<i32>>> k(100); vector<i32> perm(n);
    iota(perm.begin(), perm.end(), 1);
    do {
      int res = 0;
      for (i32 i = 0; i < n; ++i) res += abs(i + 1 - perm[i]);
      k[res].push_back(perm);
    } while (next_permutation(perm.begin(), perm.end()));
    for (i32 i = 0; i < k.size(); ++i) cout << i << ',' << k[i].size() << '\n';
    */
    if (k & 1) {
      cout << "NO\n";
      continue;
    }
    else if (n == 1) {
      cout << (k == 0 ? "YES\n1\n" : "NO\n");
      continue;
    }
    opc = -1;
    iota(a + 1, a + n + 1, 1);
    const i32 nby2 = n >> 1;
    for (i32 i = 1; i <= nby2; ++i) {
      op = n + 1 - i;
      if (k < ((op - i) << 1)) { opc = i; continue; }
      swap(a[i], a[op]), k -= ((op - i) << 1);
    }
    if (k != 0) {
      if ((k == 2) & (opc != -1)) {
        swap(a[opc], a[opc + 1]);
      } else {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
    for (i32 i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
  }
}
