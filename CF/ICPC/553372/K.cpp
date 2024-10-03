#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 500'000;
  int TC = 1, a[N], n, ans;
  cin >> TC;
  while (TC--) {
    ans = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n - 1; i; --i) if (a[i - 1] < a[i]) ++ans;
    cout << ans << '\n';
  }
}
