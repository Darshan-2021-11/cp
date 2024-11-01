#include <bits/stdc++.h>
using namespace std;

int64_t SOD(int64_t num) {
  int64_t res = 0;
  while (num > 0) res += num % 10, num /= 10;
  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t x, y, l, r;
  cin >> x >> y;
  l = 1, r = x + 1;
  while (l < r) {
    int64_t t = (l + r) >> 1;
    if (t - SOD(t) >= y) r = t;
    else l = t + 1;
  }
  cout << x - l + 1 << '\n';
}
