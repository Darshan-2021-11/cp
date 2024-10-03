#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 101;
  bitset<N> b;
  int n, m, i, j;
  char c;
  cin >> n >> m;
  for (i = 0; i < m; ++i) {
    cin >> j >> c;
    if (b[j - 1]) cout << "No\n";
    else {
      if (c == 'M') cout << "Yes\n", b[j - 1] = true;
      else cout << "No\n";
    }
  }
}
