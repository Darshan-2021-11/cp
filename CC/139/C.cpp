#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static u64 TC, n, c, a[100], vstd, vs, us;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    us = 0, vstd = 1;
    cin >> n >> c;
    cin >> a[0];
    vs = a[0];
    for (i32 i = 1; i < n; ++i) {
      cin >> a[i];
      us += a[i];
    }
    sort(a + 1, a + n, greater<u64>());
    while (vstd < n) {
      if (us * vs <= c) break;
      vs += a[vstd], us -= a[vstd];
      ++vstd;
    }
    cout << vstd << '\n';
  }
}

