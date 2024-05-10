#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, a[500];
bool b[500], p0, p1;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    p0 = p1 = false;
    cin >> n;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    for (u32 i = 0; i < n; ++i) {
      cin >> b[i];
      if (b[i]) p1 = true;
      else p0 = true;
    }
    if (p1 && p0 || is_sorted(a, a + n)) cout << "YES\n";
    else cout << "NO\n";
  }
}

