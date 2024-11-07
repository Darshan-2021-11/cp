#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, cnt[16], q, t;
  char v;
  string s;
  cin >> TC;
  while (TC--) {
    fill_n(cnt, 16, 0);
    cin >> s;
    const int n = s.size();
    for (int i = 0; i < n - 3; ++i) {
      t = 0;
      for (int k = 0; k < 4; ++k) t <<= 1, t += s[i + k] ^ '0';
      ++cnt[t];
    }
    cin >> q;
    for (int i = 0, idx; i < q; ++i) {
      cin >> idx >> v;
      --idx;
      if (n < 4) { cout << "NO\n"; continue; }
      for (int j = max(idx - 3, 0); j <= min(n - 3, idx); ++j) {
        t = 0;
        for (int k = 0; k < 4; ++k) t <<= 1, t += s[j + k] ^ '0';
        --cnt[t];
      }
      s[idx] = v;
      for (int j = max(idx - 3, 0); j <= min(n - 3, idx); ++j) {
        t = 0;
        for (int k = 0; k < 4; ++k) t <<= 1, t += s[j + k] ^ '0';
        ++cnt[t];
      }
      cout << (cnt[0b1100] ? "YES\n": "NO\n");
    }
  }
}
