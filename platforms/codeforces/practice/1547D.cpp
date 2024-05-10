#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, t, x, minand;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    minand = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      cout << ((minand | t) ^ t) << ' ';
      minand |= t;
    }
    cout << '\n';
  }
}

