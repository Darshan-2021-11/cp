#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int TC = 1, n, t;
  int64_t res, sum;
  cin >> TC;
  while (TC--) {
    res = sum = 0;
    set<int64_t> s;
    s.insert(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      sum += t;
      if (s.find(sum) != s.end()) ++res, s.clear(), sum = 0, s.insert(0);
      else s.insert(sum);
    }
    cout << res << '\n';
  }
}
