#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(16), cout.setf(ios::fixed);
  int TC = 1, n, p;
  double pb;
  cin >> TC;
  for (int _ = 1; _ <= TC; ++_) {
    cin >> n >> p;
    pb = double(p) / 100;
    cout << "Case #" << _ << ": " << (pow(pb, - double(1) / n) - 1) * pb * 100 << '\n';
  }
}
