#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
static const i32 N = 100'001;
static i32 T, n;
static i32 a[N], b[N], c[N], d[N], mpb[N << 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i], c[i] = a[i];
    for (i32 i = 0; i < n; ++i) cin >> b[i], d[i] = b[i];
    sort(c, c + n);
    sort(d, d + n);
    for (i32 i = 0; i < n; ++i) {
      mpb[b[i]] = i;
    }
    i64 op {};
    bool yes = true;
    for (i32 i = 0, x; i < n; ++i) {
      if (c[i] != d[i]) { yes = false; break; }
      if (a[i] != b[i]) {
        x = b[i];
        swap(b[i], b[mpb[a[i]]]);
        swap(mpb[a[i]], mpb[x]);
        ++op;
      }
    }
    cout << (!yes || op & 1 ? "NO\n": "YES\n");
  }
}
