#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, t, ans;
char b[4'000 + 1];
int dfs(const vector<vector<u32>>& a, int index) {
  int colors = b[index];
  for (auto&& i: a[index]) {
    colors += dfs(a, i);
  }
  if (colors == 0) ++ans;
  return colors;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ans = 0;
    cin >> n;
    vector<vector<u32>> a(n);
    for (u32 i = 1; i < n; ++i) {
      cin >> t;
      a[--t].push_back(i);
    }
    for (u32 i = 0; i < n; ++i) {
      cin >> b[i];
      switch (b[i]) {
        case 'W': b[i] = -1; break;
        case 'B': b[i] = 1; break;
      }
    }
    dfs(a, 0);
    cout << ans << '\n';
  }
}

