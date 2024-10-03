#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 1001;
  i32 pf[N][N] {}, n, q;
  char ch;
  cin >> n >> q;
  for (i32 i = 1; i <= n; ++i) for (i32 j = 1; j <= n; ++j) cin >> ch, pf[i][j] = ch == '*';
  for (i32 i = 1; i <= n; ++i) for (i32 j = 1; j <= n; ++j)
    pf[i][j] += pf[i - 1][j] - pf[i - 1][j - 1] + pf[i][j - 1];
  while (q--) {
    i32 a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b;
    cout << pf[c][d] - pf[a][d] + pf[a][b] - pf[c][b] << '\n';
  }
}
