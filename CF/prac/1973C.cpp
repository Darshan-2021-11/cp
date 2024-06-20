#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, idxn, ansi, a[(u32)2e5], b[(u32)2e5], idx[(u32)1e5];
static bool mxIdxParity;

const auto compare_idx = [](u32 x, u32 y) { return a[x] > a[y]; };
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    idxn = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == n) mxIdxParity = i & 1;
      if (!(i & 1)) idx[idxn++] = i;
    }

    if (mxIdxParity) {
      ansi = 0;
      sort(idx, idx + idxn, compare_idx);
      for (u32 i = 0; i < idxn; ++i) b[idx[i]] = ++ansi, ++idx[i];
      sort(idx, idx + idxn, compare_idx);
      for (u32 i = 0; i < idxn; ++i) b[idx[i]] = ++ansi;
    } else {
      ansi = n >> 1;
      sort(idx, idx + idxn, compare_idx);
      for (u32 i = 0; i < idxn; ++i) b[idx[i]] = ++ansi, ++idx[i];
      ansi = 0;
      sort(idx, idx + idxn, compare_idx);
      for (u32 i = 0; i < idxn; ++i) b[idx[i]] = ++ansi;
    }
    for (u32 i = 0; i < n; ++i) cout << b[i] << ' ';
    cout << '\n';
  }
}
