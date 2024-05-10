#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, c, d, a[250'000], b[250'000], total, a00, t, idx;
bool same;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    same = true;
    cin >> n >> c >> d;
    total = n * n;
    for (u32 i = 0; i < total; ++i) {
        cin >> a[i];
    }
    sort(a, a + total);
    a00 = a[0], idx = 0;
    for (u32 i = 0; i < n; ++i) {
      t = a00;
      for (u32 j = 0; j < n; ++j) {
        b[idx++] = t;
        t += c;
      }
      a00 += d;
    }
    sort(b, b + total);
    for (u32 i = 0; i < total; ++i) if (a[i] != b[i]) { same = false; break; }
    if (same) cout << "YES\n";
    else cout << "NO\n";
  }
}

