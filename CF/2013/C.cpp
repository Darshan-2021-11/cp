#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, x;
  cin >> TC;
  while (TC--) {
    cin >> n;
    string s = "0";
    cout << "? " << s << endl;
    cin >> x;
    if (!x) {
      cout << "! ";
      for (int i = 0; i < n; ++i) cout << '1';
      cout << endl;
      continue;
    }
    while (s.size() < n) {
      cout << "? " << s << '0' << endl;
      cin >> x;
      if (x) { s += '0'; continue; }
      cout << "? " << s << '1' << endl;
      cin >> x;
      if (x) { s += '1'; continue; }
      else break;
    }
    while (s.size() < n) {
      cout << "? " << '0' << s << endl;
      cin >> x;
      if (x) s = '0' + s;
      else s = '1' + s;
    }
    cout << "! " << s << endl;
  }
}
