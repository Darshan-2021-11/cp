#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n, cnt1;
  cin >> TC;
  char c;
  while (TC--) {
    cnt1 = 0;
    cin >> n;
    for (int i = 0; i < n << 1; ++i) cin >> c, cnt1 += c == '1';
    if (cnt1 > n) cnt1 = (n << 1) - cnt1;
    cout << (cnt1 & 1) << ' ' << cnt1 << '\n';
  }
}
