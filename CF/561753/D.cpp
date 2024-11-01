#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int64_t n, x, a[N], ans;
  cin >> n;
  map<int, int64_t> m;
  map<int, int64_t>::iterator it;
  for (int i = 0; i < n; ++i) cin >> a[i], ++m[a[i]];
  ans = 0;
  if ((x = ((it = m.begin())->second)) >= 3) {
    ans += (it->second) * (it->second - 1) * (it->second - 2);
    ans /= 6;
    cout << ans << '\n';
  } else if (x == 2) {
    ++it;
    cout << it->second << '\n';
  } else {
    ++it;
    if ((x = it->second) != 1) {
      cout << (it->second) * (it->second - 1) / 2 << '\n';
    } else {
      ++it;
      cout << (it->second) << '\n';
    }
  }
}
