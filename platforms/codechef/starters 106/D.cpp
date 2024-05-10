#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;

  bool nis1 = (n == 1), mis1 = (m == 1);
  if(nis1 && mis1) {
    cout << 0 << '\n';
  } else if(nis1) {
    cout << max(m-y, y-1) << '\n';
  } else if(mis1) {
    cout << max(n-x, x-1) << '\n';
  } else {
    int x1 = max(n-x, x-1);
    int y1 = max(m-y, y-1);
    cout << x1 * y1 << '\n';
  }
  return 0;
}

int main() {
  int t;
  cin >> t;

  while(t--)
    solve();
  return 0;
}
