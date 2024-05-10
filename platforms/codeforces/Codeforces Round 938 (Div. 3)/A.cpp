#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, a, b, minab;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> a >> b;
    minab = a << 1 < b ? a << 1: b;
    cout << (minab * (n >> 1) + a * (n & 1)) << '\n';
  }
}

