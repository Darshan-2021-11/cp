#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n, ans;
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    cout << (n == 1 ? "Alice" : "Bob") << '\n';
  }
}
