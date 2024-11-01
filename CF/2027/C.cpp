#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 300'000;
  int64_t TC = 1, n, t, mx;
  pair<int64_t, int64_t> a[N];
  cin >> TC;
  while (TC--) {
    cin >> n;
    cin >> t;
    for (int i = 1; i < n; ++i)
      cin >> a[i].first, a[i].first += i, a[i].second = i;
    sort(a + 1, a + n);
    set<int64_t> sel;
    sel.insert(n);
    mx = n;
    for (int i = 1; i < n; ++i) {
      if (sel.find(a[i].first) != sel.end()) {
        sel.insert(t = a[i].first + a[i].second);
        mx = max(mx, t);
      }
      while (sel.size() && *sel.begin() < a[i].first) sel.erase(sel.begin());
    }
    cout << mx << '\n';
  }
}
