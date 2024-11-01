#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int n, k;
  struct node {
    int64_t v;
    explicit node() : v(0) {}
    explicit node(int64_t val) : v(val) {}
    void merge(node &x, node &y) { v = x.v + y.v; }
  };
  node st[2][N << 1];
  node *r[2] = { st[0], st[1] };
  auto build = [r, n]() -> void {
    for (int i = n - 1; i; --i) {
      r[1][i].merge(r[1][i << 1], r[1][i << 1 | 1]);
    }
  };
  cin >> n >> k;
  for (int i = n; i < n << 1; ++i)
    cin >> st[0][i].v, st[1][i].v = 1;
  for (int j = 0; j < k; ++j) {
    build();
    for (int i = n - 1; ~i; --i) {
    }
    swap(r[0], r[1]);
  }
}
