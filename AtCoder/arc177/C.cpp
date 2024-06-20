#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static const u32 dx[] = { 1, 0, (u32)-1,  0 },
                 dy[] = { 0, 1,  0, (u32)-1 };
static u32 n, d, ax, ay, dist[500][500];
static char C[500][500];
static bool V[500][500], cost;
static deque<tuple<u32, u32, u32>> dq;

u32 zeroOneBFS(u32 sx, u32 sy, u32 tx, u32 ty, char tgt) {
  for (u32 i = 0; i < n; ++i) for (u32 j = 0; j < n; ++j) dist[i][j] = -1;
  dist[sx][sy] = 0;
  dq.emplace_back(0, sx, sy);

  while (dq.size()) {
    tie(d, ax, ay) = dq.front(); dq.pop_front();
    if (ax == tx && ay == ty) break;
    if (V[ax][ay]) continue;
    V[ax][ay] = true;
    for (u32 i = 0; i < 4; ++i) {
      const u32 bx = ax + dx[i];
      const u32 by = ay + dy[i];
      if (bx >= n || by >= n) continue;
      cost = C[bx][by] != tgt;
      if (dist[bx][by] > d + cost) {
        dist[bx][by] = d + cost;
        if (cost)
          dq.emplace_back(d + cost, bx, by);
        else
          dq.emplace_front(d, bx, by);
      }
    }
  }
  for (u32 i = 0; i < n; ++i) for (u32 j = 0; j < n; ++j) V[i][j] = false;
  dq.clear();
  return dist[tx][ty];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (u32 i = 0; i < n; ++i)
    for (u32 j = 0; j < n; ++j) {
      cin >> C[i][j];
    }
  cout << zeroOneBFS(0, 0, n - 1, n - 1, 'R') + zeroOneBFS(0, n - 1, n - 1, 0, 'B') << '\n';
}
