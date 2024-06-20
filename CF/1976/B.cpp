#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, a[(u32)2e5 + 10], b[(u32)2e5 + 10], mn;
static u64 steps;
static bool present;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    steps = present = 0, mn = INT_MAX;
    cin >> n;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    for (u32 i = 0; i < n + 1; ++i) cin >> b[i];
    for (u32 i = 0; i < n; ++i) {
      if (a[i] > b[i]) swap(a[i], b[i]);
      if (b[n] >= a[i] && b[n] <= b[i]) mn = 0;
      else if (b[n] < a[i]) mn = min(a[i] - b[n], mn);
      else if (b[n] > b[i]) mn = min(b[n] - b[i], mn);
      steps += b[i] - a[i];
    }
    steps += mn + 1;
    cout << steps << '\n';
  }
}

