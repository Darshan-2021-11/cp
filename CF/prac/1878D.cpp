#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'002;
static i32 TC, n, k, q, l[N], r[N], id[N];
static char a[N];
static bitset<N> flip;

int main() {
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    for (i32 i = 1; i <= n; ++i) cin >> a[i], flip[i] = 0;
    for (i32 i = 1; i <= k; ++i) cin >> l[i], cout << l[i] << ' ';
    for (i32 i = 1; i <= k; ++i) {
      cin >> r[i];
      for (i32 j = l[i]; j <= r[i]; ++j) id[j] = i;
    }
    cin >> q;
    while (q--) {
      i32 idx, li, ri;
      cin >> li;
      idx = id[li];
      ri = l[idx] + r[idx] - li;
      if (li > ri) swap(li, ri);
      flip[li] = flip[li] ^ 1, flip[ri + 1] = flip[ri + 1] ^ 1;
    }
    for (i32 i = 1; i <= n; ++i) {
      flip[i] = flip[i] ^ flip[i - 1];
    }
    for (i32 i = 1, ik, opp; i <= n; ++i) {
      if (!flip[i]) continue;
      ik = id[i], opp = l[ik] + r[ik] - i;
      assert(i <= opp);
      swap(a[i], a[opp]);
      flip[opp] = 0;
    }
    for (i32 i = 1; i <= n; ++i) cout << a[i];
    cout << '\n';
  }
}
