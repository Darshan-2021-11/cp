#include <bits/stdc++.h>
using namespace std;

template <int SIZE>
struct bs {
  const static uint32_t IDX_RS = 5;
  const static uint32_t MASK = (sizeof(uint32_t) << 3) - 1;
  uint32_t data[(SIZE + MASK) >> IDX_RS];
  void init(int n) {
    fill_n(data, (n + MASK) >> IDX_RS, 0);
  }
  void set(int idx) {
    data[idx >> IDX_RS] |= (1U << (idx & MASK));
  }
  void reset(int idx) {
    data[idx >> IDX_RS] &= ~(1U << (idx & MASK));
  }
  void flip(int idx) {
    data[idx >> IDX_RS] ^= (1U << (idx & MASK));
  }
  int get(int idx) {
    return (data[idx >> IDX_RS] >> (idx & MASK)) & 1U;
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000;
  char p[N * N];
  bs<N * N> b;
  int n, m, x, y;
  char c;
  cin >> n >> m;
  b.init(n * m);
  pair<int, int> t, src, end;
  for (int i = 0, idx = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j, ++idx) {
      cin >> c;
      p[idx] = -1;
      if (c == '#') continue;
      b.set(idx);
      switch (c) {
        case 'A': src.first = i, src.second = j; break;
        case 'B': end.first = i, end.second = j; break;
      }
    }
  }
  queue<pair<int, int>> q;
  const char dirn[][3] = {
    {  1,  0, 'D' },
    {  0,  1, 'R' },
    { -1,  0, 'U' },
    {  0, -1, 'L' },
  };
  q.emplace(src.first, src.second);
  while (q.size()) {
    t = q.front(); q.pop();
    if (t == end) break;
    for (int i = 0; i < 4; ++i) {
      x = dirn[i][0] + t.first, y = dirn[i][1] + t.second;
      if (x < n && x >= 0 && y < m && y >= 0 && b.get(x * m + y))
        q.emplace(x, y), p[x * m + y] = i, b.reset(x * m + y);
    }
  }
  if (p[end.first * m + end.second] == -1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  stack<char> sc;
  t = end;
  y = 0;
  while (t != src) {
    x = t.first * m + t.second;
    sc.push(dirn[p[x]][2]);
    t.first -= dirn[p[x]][0], t.second -= dirn[p[x]][1], ++y;
  }
  cout << y << '\n';
  while (sc.size()) cout << sc.top(), sc.pop();
}
