#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, a[(u32)500], b[(u32)500];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (u32 i = 0; i < n - 1; ++i) {
      cin >> a[i];
    }
    b[0] = a[0] + 1;
    cout << b[0] << ' ';
    for (u32 i = 0; i < n - 2; ++i) {
      b[i + 1] = (a[i + 1] * ((i + 2) * 500 + 500) / b[i]) * b[i] + a[i];
      cout << b[i + 1] << ' ';
    }
    cout << a[n - 2] << '\n';
  }
}

