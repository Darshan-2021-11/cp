#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    t = !n ? 0 : 15 - __builtin_ctz(n);
    for (int i = 1; i < 15; ++i) {
      ++n;
      t = min(t, i + (15 - __builtin_ctz(n)));
    }
    cout << t << '\n';
  }
}

