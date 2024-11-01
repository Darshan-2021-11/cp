#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 102;
  int TC = 1, n, w[N], ans;
  cin >> TC;
  while (TC--) {
    cin >> n;
    fill_n(w, N, 0);
    for (int i = 0, t1, t2; i < n; ++i) {
      cin >> t1 >> t2;
      w[t1] = max(w[t1], t2);
    }
    for (int i = 100; i; --i) w[i] = max(w[i], w[i + 1]);
    ans = w[1] + 2;
    for (int i = 2; i < N; ++i) {
      if (w[i - 1] > w[i]) ans += w[i - 1] - w[i];
      if (w[i]) ans += 2;
      else break;
    }
    cout << ans << '\n';
  }
}
