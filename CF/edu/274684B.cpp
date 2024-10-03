#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

i32 mod;
struct matrix {
  i32 data[2][2];
  matrix operator*(const matrix &other) {
    matrix res = {};
    for (i32 i = 0; i < 2; ++i)
      for (i32 k = 0; k < 2; ++k)
        for (i32 j = 0; j < 2; ++j)
          (res.data[i][j] += data[i][k] * other.data[k][j]) %= mod;
    return res;
  }
  matrix& operator*=(const matrix &other) {
    *this = *this * other;
    return *this;
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 n, m, l, r, t[18], tn;
  cin >> mod >> n >> m;
  matrix st[N << 1];
  for (i32 i = n; i < n << 1; ++i) {
    for (i32 j = 0; j < 2; ++j)
      for (i32 k = 0; k < 2; ++k) cin >> st[i].data[j][k];
  }
  for (i32 i = n - 1; i; --i) st[i] = st[i << 1] * st[i << 1 | 1];
  while (m--) {
    cin >> l >> r;
    --l;
    matrix res = {
      {
        { 1, 0 }, { 0, 1 }
      }
    };
    for (l += n, r += n, tn = 0; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res *= st[l++];
      if (r & 1) t[tn++] = --r;
    }
    while (tn) {
      res *= st[t[--tn]];
    }
    for (i32 i = 0; i < 2; ++i)
      for (i32 j = 0; j < 2; ++j)
        cout << res.data[i][j] << " \n"[j];
    cout << '\n';
  }
}

