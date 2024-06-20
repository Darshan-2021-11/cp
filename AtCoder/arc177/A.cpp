#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 x, coins[6], values[6] = { 1, 5, 10, 50, 100, 500 }, n, t, r;
bool yes = true;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  for (u32 i = 0; i < 6; ++i) cin >> coins[i];
  cin >> n;
  for (u32 i = 0; i < n; ++i) {
    cin >> x;
    for (u32 j = 5; j < 6; --j) {
      t = x / values[j], r = min(t, coins[j]);
      coins[j] -= r, x -= r * values[j];
    }
    if (x) yes = false;
  }
  cout << (yes ? "Yes\n" : "No\n");
}

