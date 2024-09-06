#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const u32 N = 1000, dir[4][2] = { { 1, 0 }, { 0, 1 }, { UINT32_MAX, 0 }, { 0, UINT32_MAX } };
static u32 n, m, res;
static char a[N][N];
static array<bitset<N>, N> vis;

static void dfs(u32 i, u32 j) {
  vis[i][j] = true;
  for (u32 k = 0, x, y; k < 4; ++k) {
    x = i + dir[k][0], y = j + dir[k][1];
    if (x < n && y < m && a[x][y] == '.' && !vis[x][y]) dfs(x, y);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (u32 i = 0; i < n; ++i) for (u32 j = 0; j < m; ++j)
    cin >> a[i][j], vis[i][j] = false;
  for (u32 i = 0; i < n; ++i) for (u32 j = 0; j < m; ++j)
    if (a[i][j] == '.' && !vis[i][j]) dfs(i, j), ++res;
  cout << res;
}

