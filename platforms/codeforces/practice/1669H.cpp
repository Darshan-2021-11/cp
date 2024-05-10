#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, a[31], n, t, k;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> k;
    for (u32 i = 30; i < 31; --i) a[i] = n;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      for (u32 j = 30; j < 31; --j) if (t >> j & 1) --a[j];
    }
    t = 0;
    for (u32 i = 30; i < 31; --i) if (a[i] > k) continue; else k -= a[i], t |= 1 << i;
    cout << t << '\n';
  }
}

