#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    string s, t;
    cin >> n >> s;
    t = s;
    vector<int> s0, s1;
    bool start1 = true;
    for (int i = 0; i < n; i += 2) {
      if (s[i] != s[i + 1]) {
        if (s[i] - '0' != start1) s0.push_back(i), s[i] = '0' + start1;
        else s0.push_back(i + 1), s[i + 1] = '0' + start1;
        start1 = !start1;
      }
    }
    bool possible = true;
    for (int i = 0; i < n; i += 2) {
      if (s[i] != s[i + 1]) {
        possible = false;
      }
    }
    if (possible) {
      cout << s0.size() << '\n';
      //cout << s << '\n';
      for (int &i: s0) cout << i + 1 << ' ';
      cout << '\n';
      continue;
    }
    start1 = false;
    s = t;
    for (int i = 0; i < n; i += 2) {
      if (s[i] != s[i + 1]) {
        if (s[i] - '0' != start1) s1.push_back(i), s[i] = '0' + start1;
        else s1.push_back(i + 1), s[i + 1] = '0' + start1;
        start1 = !start1;
      }
    }
    possible = true;
    for (int i = 0; i < n; i += 2) {
      if (s[i] != s[i + 1]) {
        possible = false;
      }
    }
    if (possible) {
      cout << s1.size() << '\n';
      for (int &i: s1) cout << i + 1 << ' ';
      cout << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}

