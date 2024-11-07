#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  //const int N = 
  int64_t TC = 1, n, t;
  cin >> TC;
  while (TC--) {
    cin >> n;
    if (!(n & 1)) {
      cout << 2 << '\n';
      continue;
    } else if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    cout << ((n * n) >> 1) + 2 << '\n';
  }
}
