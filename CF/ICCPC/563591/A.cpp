#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int w, h, x[2], y[2];
  freopen("anniversary.in", "r", stdin);
  freopen("anniversary.out", "w", stdout);
  cin >> w >> h >> x[0] >> y[0] >> x[1] >> y[1];
  if (x[0] != x[1])
    cout << x[0] << ' ' << 0 << ' ' << x[1] << ' ' << h << '\n';
  else 
    cout << 0 << ' ' << y[0] << ' ' << w << ' ' << y[1] << '\n';
}
