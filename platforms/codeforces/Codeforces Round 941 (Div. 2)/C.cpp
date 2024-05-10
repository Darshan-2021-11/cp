#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, i, n, a[(u32)2e5];
bool alice, notone;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (i = n - 1; i > 0; --i) a[i] -= a[i - 1];
    for (i = 0; i < n; ++i) {
      if (a[i] != 1) {
        alice = ~i & 1;
        break;
      }
    }
    if (i == n) alice = n & 1;
    cout << (alice ? "Alice\n" : "Bob\n");
  }
}

