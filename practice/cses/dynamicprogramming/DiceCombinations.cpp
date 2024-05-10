#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int n,
    a[7] = {
      1 << 0,
      1 << 1,
      1 << 2,
      1 << 3,
      1 << 4,
      1 << 5,
    };
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  if (n < 7) { cout << a[n - 1]; return 0; }
  for (int i = 6; i < n; ++i) {
    a[6] = 0;
    for (int j = 1; j <= 6; ++j) {
      a[6] += a[6 - j];
      if (a[6] >= mod) a[6] -= mod;
    }
    for (int j = 1; j <= 6; ++j) {
      a[j - 1] = a[j];
    }
  }
  cout << a[6];
}

