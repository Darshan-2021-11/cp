#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

template <typename T, i32 N>
struct mp {
  pair<T, i32> data[N];
  i32 _n;
 
  void make(const T (&arr)[N], const i32 n) {
    for (i32 i = 0; i < n; ++i) data[i].first = arr[i];
    sort(data, data + n, less<pair<T, i32>>());
    data[_n = 0].second = 1;
    for (i32 i = 1; i < n; ++i)
      if (data[i].first == data[i - 1].first) ++data[_n].second;
      else data[++_n].first = data[i].first, data[_n].second = 1;
    ++_n;
  }
  i32 get(const T n) const {
    i32 idx = lower_bound(data, data + _n, n) - data;
    if (idx == _n || data[idx] != n) return 0;
    return data[idx].second;
  }
  i32 operator[](const T n) {
    return get(n);
  }
  i32 size() const {
    return _n;
  }
};

static const i32 N = 200'001;
static i32 TC, n, t, r, a[N], ans, mxans;
static mp<i32, N> m;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    m.make(a, n);
    ans = n, mxans = 0, r = 0;
    for (i32 i = 0; i < m._n; ++i) r += m.data[i].second - 1;
    sort(m.data, m.data + m._n, [](pair<i32, i32> x, pair<i32, i32> y) { return x.second < y.second; });
    for (i32 i = 0; i < m._n; ++i) {
      t = ans % (m._n - i);
      if (t <= r) { mxans = max(ans - t, mxans); }
      r -= m.data[i].second - 1, ans -= m.data[i].second;
    }
    cout << mxans << '\n';
  }
}
