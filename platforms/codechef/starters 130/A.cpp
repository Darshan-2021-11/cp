#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, flips;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    flips = 0;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; ++i) if (s[i] == s[i - 1]) ++flips;
    cout << flips << '\n';
  }
}

