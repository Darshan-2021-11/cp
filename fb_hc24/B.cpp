#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(10), cout.setf(ios::fixed);
  const int N = 10'000'001;
  std::vector<bool> mark(N, true);
  for (int p = 2; p * p < N; p++) {
    if (mark[p] == true) {
      for (int i = p * p; i < N; i += p)
        mark[i] = false;
    }
  }
  int TC = 1, n, ans;
  cin >> TC;
  for (int _ = 1; _ <= TC; ++_) {
    cin >> n;
    if (n < 5) ans = 0;
    else {
      ans = 2;
      for (int i = 7; i <= n; i += 2) ans += mark[i] & mark[i - 2];
    }
    cout << "Case #" << _ << ": " << ans << '\n';
  }
}
