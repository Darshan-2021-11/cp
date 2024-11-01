#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n, cnt[2], res;
  char c[N];
  cin >> TC;
  while (TC--) {
    res = 1, cnt[0] = cnt[1] = 0;
    cin >> n;
    cin >> c[0];
    map<int, int> m;
    m[0] = 0;
    map<int, int>::iterator it;
    for (int i = 1; i < n; ++i) {
      cin >> c[i];
      if (c[i] != c[i - 1]) ++cnt[c[i - 1] == 'b'];
      if ((it = m.find(cnt[0] - cnt[1])) == m.end()) m[cnt[0] - cnt[1]] = i;
      else res = max(i - it->second + 1, res);
    }
    cout << res << '\n';
  }
}
