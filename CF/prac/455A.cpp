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

static const i64 N = 100'000;
static i32 n, a[N];
static i64 dp[N], ans;
static mp<i32, N> m;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i32 i = 0; i < n; ++i) cin >> a[i];
  m.make(a, n);
  /*
  for (i32 i = 0; i < m._n; ++i) {
    cout << m.data[i] << ':' << m.freq[i] << ",\n"[i == m._n - 1];
  }
  */
  for (i32 i = 0; i < m.size(); ++i) {
    dp[i] = static_cast<i64>(m.data[i]) * m.freq[i];
    if (m.data[i] - 1 == m.data[i - 1]) {
      if (i > 2) dp[i] += max(dp[i - 3], dp[i - 2]);
      else if (i > 1) dp[i] += dp[i - 2];
    } else {
      if (i > 1) dp[i] += max(dp[i - 2], dp[i - 1]);
      else if (i) dp[i] += dp[i - 1];
    }
  }
  cout << *max_element(dp, dp + m.size()) << '\n';
  for (i32 i = 0; i < m.size(); ++i) dp[i] = 0;
}
