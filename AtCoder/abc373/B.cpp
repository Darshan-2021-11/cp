#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int ans = 0, pos[26];
  char c;
  for (int i = 0; i < 26; ++i) {
    cin >> c;
    pos[c - 'A'] = i;
  }
  for (int i = 1; i < 26; ++i) ans += abs(pos[i] - pos[i - 1]);
  cout << ans;
}
