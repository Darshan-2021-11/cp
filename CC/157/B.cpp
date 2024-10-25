#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 300'000;
  bitset<N> b;
  int TC = 1, n, cnt1;
  char c;
  cin >> TC;
  while (TC--) {
    cnt1 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> c, cnt1 += (b[i] = c == '1');
    if (cnt1 == 0) cout << n << '\n';
    else cout << (cnt1 & 1) << '\n';
  }
}
