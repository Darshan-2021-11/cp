#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, k, q, a[100], b;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> k >> q;
    for (u32 i = 0; i < k; ++i) {
      cin >> a[i];
    }
    for (u32 i = 0; i < q; ++i) {
      cin >> b;
      cout << min(a[0] - 1, b) << ' ';
    }
    cout << '\n';
  }
}

