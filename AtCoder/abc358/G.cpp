#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static const i32 directions[4][2] = {
  {  1,  0 },
  {  0,  1 },
  { -1,  0 },
  {  0, -1 },
};

static i32 grid[50][50], h, w, k, x, y, xt, yt;
static i64 ans, visited[50];

void dfs(i32 x, i32 y) {
  for (i32 i = 0; i < 4; ++i) {
    xt = x + directions[i][0];
    xt = y + directions[i][0];
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> h >> w >> k >> x >> y;
  --x, --y;
  for (i32 i = 0; i < h; ++i) {
    for (i32 j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }
}

