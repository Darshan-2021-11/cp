#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int ans = 0;
  string s;
  for (int i = 1; i <= 12; ++i) {
    cin >> s;
    ans += s.size() == i;
  }
  cout << ans;
}
