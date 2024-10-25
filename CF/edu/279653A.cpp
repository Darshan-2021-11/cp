#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  struct node {
    int64_t val;
    node() : val(LLONG_MAX) {}
    node(int64_t x) : val(x) {}
    void merge(node &x, node &y, int64_t offset = 0) {
      val = min(x.val, y.val) + offset;
    }
  };
  node st[N << 1];
  int64_t d[N];
  int n, h, m, q_t, l, r, v, l0, r0;
  cin >> n >> m;
  h = (sizeof(int) << 3) - __builtin_clz(n);
  fill_n(st, n << 1, node(0));
  fill_n( d, n << 0, 0);
  auto apply = [&](int p, int val) -> void {
    st[p].val += val;
    if (p < n) d[p] += val;
  };
  auto push = [&](int p) -> void {
    int s = h; do {
      int i = p >> s;
      if (!d[i]) continue;
      apply(    i << 1, d[i]);
      apply(i << 1 | 1, d[i]);
      d[i] = 0;
    } while (--s);
  };
  auto build = [&](int p) -> void {
    while (p >>= 1) st[p].merge(st[p << 1], st[p << 1 | 1], d[p]);
  };
  auto inc = [&]() -> void {
    l += n, r += n, l0 = l, r0 = r;
    do {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    } while (l >>= 1, r >>= 1, l < r);
    build(l0), build(r0 - 1);
  };
  auto query = [&]() -> node {
    l += n, r += n;
    push(l), push(r - 1);
    node res;
    do {
      if (l & 1) res.merge(res, st[l++]);
      if (r & 1) res.merge(res, st[--r]);
    } while (l >>= 1, r >>= 1, l < r);
    return res;
  };
  while (m--) {
    cin >> q_t;
    if (q_t == 1) {
      cin >> l >> r >> v;
      inc();
    } else {
      cin >> l >> r;
      cout << query().val << '\n';
    }
  }
}
