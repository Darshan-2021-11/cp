#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, lastidx, a[(u32)2e5], mn[(u32)2e5];
static u64 cost;
static bool dir;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cost = dir = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] = i;
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    mn[n - 1] = a[n - 1];
    for (u32 i = n - 2; i < n; --i) {
      mn[i] = min(a[i], mn[i + 1]);
    }
    cout << cost << '\n';
  }
}
