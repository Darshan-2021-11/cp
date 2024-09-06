#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

template <typename T, i32 N>
struct mp {
  T data[N];
  i32 freq[N];
  i32 _n;
 
  void make(const T (&arr)[N], const i32 n) {
    for (i32 i = 0; i < n; ++i) data[i] = arr[i];
    sort(data, data + n, less<T>());
    freq[_n = 0] = 1;
    for (i32 i = 1; i < n; ++i)
      if (data[i] == data[i - 1]) ++freq[_n];
      else data[++_n] = data[i], freq[_n] = 1;
    ++_n;
  }
  i32 get(const T n) const {
    i32 idx = lower_bound(data, data + _n, n) - data;
    if (idx == _n || data[idx] != n) return 0;
    return freq[idx];
  }
  i32 operator[](const T n) {
    return get(n);
  }
  i32 size() const {
    return _n;
  }
};

static const i32 N = 200'001;
static i32 TC, n, q, a[N], u, v;
static mp<i32, N> f;
static i64 ans, x, y, D;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    f.make(a, n);
    cin >> q;
    for (i32 i = 1; i <= q; ++i) {
      ans = 0;
      cin >> x >> y;
      D = x * x - (y << 2);
      if (!D && !(x & 1)) {
        x >>= 1;
        ans = ((i64)f[x] * (f[x] - 1)) >> 1;
      }
      else if (D > 0) {
        D = sqrtl(D);
        u = (x + D) >> 1, v = (x - D) >> 1;
        if (u + v == x && (i64)u * v == y) ans = (i64)f[u] * f[v];
      }
      cout << ans << " \n"[i == q];
    }
  }
}
