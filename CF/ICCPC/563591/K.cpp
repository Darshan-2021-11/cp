#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  string k, t;
  int q;
  freopen("king.in", "r", stdin);
  freopen("king.out", "w", stdout);
  for (int i = 0, x; i < 3; ++i) {
    cin >> x;
    t = to_string(x);
    if (i != 2) {
      if (x / 10 == 0) t = '0' + to_string(x);
    } else {
      while (t.size() < 5) t = '0' + t;
    }
    t += k;
    k = t;
  }
  cin >> q;
  vector<pair<string, int>> s(q);
  for (int j = 0; j < q; ++j) {
    for (int i = 0, x; i < 3; ++i) {
      cin >> x;
      if (i != 2) {
        t = to_string(x);
        if (x / 10 == 0) t = '0' + to_string(x);
      } else {
        t = to_string(x + 18);
        while (t.size() < 5) t = '0' + t;
      }
      t += s[j].first;
      s[j].first = t;
    }
    s[j].second = j;
  }
  sort(s.begin(), s.end());
  //cout << k << '\n';
  //for (int j = 0; j < q; ++j) cout << s[j].first << ' ' << s[j].second << '\n';
  for (int i = q - 1; ~i; --i) {
    if (s[i].first > k) continue;
    else {
      cout << s[i].second + 1;
      return 0;
    }
  }
  cout << -1;
}
