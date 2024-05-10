#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, m, n, p[(u32)2e5], q[(u32)2e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> m >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> p[i];
    }
    for (u32 i = 0; i < n; ++i) {
      cin >> q[i];
    }
    
  }
}

