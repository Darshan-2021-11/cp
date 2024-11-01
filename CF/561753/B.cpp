#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1;
  cin >> TC;
  while (TC--) {
    string s;
    cin >> s;
    if (s.size() > 10) {
      cout << s[0] << (s.size() - 2) << s[s.size() - 1] << '\n';
    } else cout << s << '\n';
  }
}
