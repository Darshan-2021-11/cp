#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, c0, c1;
char s;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    c1 = c0 = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> s;
      if (s == '1') ++c1;
      else ++c0;
    }
    if (n == 1) {
      cout << "BOB\n";
    } else if (n == 2) {
      if (c1 == c0) cout << "BOB\n";
      else cout << "ALICE\n";
    } else if (n & 1) {
      if (abs(c1 - c0) == 1)
        cout << "ALICE\n";
      else
        cout << "BOB\n";
    } else {
      if (c1 == c0)
        cout << "BOB\n";
      else
        cout << "ALICE\n";
    }
  }
}

