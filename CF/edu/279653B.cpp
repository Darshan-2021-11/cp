#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

template <int MOD>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::istream& operator>>(std::istream& is, Modular       &a) {return is >> a.value;}
  friend std::ostream& operator<<(std::ostream& os, Modular const &a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
using m_int = Modular<1'000'000'007>;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  m_int st[N << 1], d[N], v;
  int n, h, m, q_t, l, r, l0, r0;
  cin >> n >> m;
  h = (sizeof(int) << 3) - __builtin_clz(n);
  fill_n(st, n << 1, m_int(1));
  fill_n( d, n << 0, m_int(1));
  auto operation = [](auto x, auto y) -> auto {
    return x * y;
  };
  auto apply = [&](int p, auto val) -> void {
    operation(st[p], val * (h - ((sizeof(int) << 3) - __builtin_clz(n))));
    if (p < n) operation(d[p], val);
  };
  auto build = [&](int p) -> void {
    while (p >>= 1) st[p] = (st[p << 1] + st[p << 1 | 1]) * d[p];
  };
  auto push = [&](int p) -> void {
    int s = h; do {
      int i = p >> s;
      if (d[i] == 1) continue;
      apply(    i << 1, d[i]);
      apply(i << 1 | 1, d[i]);
      d[i] = 1;
    } while (--s);
  };
  auto inc = [&]() -> void {
    l += n, r += n, l0 = l, r0 = r;
    do {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    } while (l >>= 1, r >>= 1, l < r);
    build(l0), build(r0 - 1);
  };
  auto query = [&]() -> auto {
    l += n, r += n;
    push(l), push(r - 1);
    m_int res = 0;
    do {
      if (l & 1) res += st[l++].value;
      if (r & 1) res += st[--r].value;
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
      cout << query() << '\n';
    }
  }
}
