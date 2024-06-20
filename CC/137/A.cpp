#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static int TC, n, k, t, adjsum, madjsum, a[1000];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n >> k;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    adjsum = 0;
    for (u32 i = 0; i < n - 1; ++i) adjsum += abs(a[i] - a[i + 1]);
    madjsum = adjsum;

    t = adjsum - abs(a[0] - a[1]);
    madjsum = max({ madjsum, t + abs(a[1] - k), t + abs(a[1] - 1) });

    t = adjsum - abs(a[n - 1] - a[n - 2]);
    madjsum = max({ madjsum, t + abs(a[n - 2] - k), t + abs(a[n - 2] - 1) });

    for (u32 i = 1; i < n - 1; ++i) {
      t = adjsum - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]);
      madjsum = max({
          madjsum,
          t + abs(a[i - 1] - k) + abs(a[i + 1] - k),
          t + abs(a[i - 1] - 1) + abs(a[i + 1] - 1),
          });
    }
    cout << madjsum << '\n';
  }
}

