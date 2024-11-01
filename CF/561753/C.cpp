#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int x[2], y[2], a, b;
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  cin >> a >> b;
  if ((x[1] - x[0]) % a != 0 || (y[1] - y[0]) % b != 0) cout << "NO\n";
  else {
    if (((x[1] - x[0]) / a - (y[1] - y[0]) / b) & 1) cout << "NO\n";
    else cout << "YES\n";
  }

}
