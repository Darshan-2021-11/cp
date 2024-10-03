#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int k;
  string s;
  while (cin >> quoted(s) >> k) {
    const int n = s.size();
    const array<char, 5> v = { 'a', 'e', 'i', 'o', 'u', };
    int64_t ans = 0;
    int cc = 0, si[5] {};
    array<vector<int>, 5> idx;
    bool hv;
    for (int i = 0, r = 0, vi, last = -1; i < n; ++i) {
      hv = true;
      for (int j = 0; j < v.size(); ++j) hv &= si[j] != idx[j].size();
      while (r < n) {
        if ((vi = find(v.begin(), v.end(), s[r]) - v.begin()) == v.size()) {
          if (cc == k) break;
          if (++cc == k) last = r;
        } else {
          idx[vi].push_back(r);
          if (!hv) {
            bool _hv = true;
            for (int j = 0; j < v.size(); ++j) _hv &= si[j] != idx[j].size();
            if (_hv) last = r, hv = true;
          }
        }
        ++r;
      }
      for (int j = 0; j < v.size(); ++j) if (si[j] != idx[j].size())
        last = max(last, idx[j][si[j]]);
      if (hv && cc == k) ans += r - last;
      if ((vi = find(v.begin(), v.end(), s[i]) - v.begin()) == v.size()) --cc;
      else ++si[vi];
    }
    cout << ans << '\n';
  }
}
