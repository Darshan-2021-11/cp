#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, i;
ll a[(u32)3e5], t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (n & 1) { cout << "YES\n"; continue; }
    for (i = 1; i < n - 1; ++i) {
      t = a[i - 1] - a[i];
      a[i] += t, a[i + 1] += t;
    }
    cout << (a[n - 2] <= a[n - 1] ? "YES\n": "NO\n");
  }
}

