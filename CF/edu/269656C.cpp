#pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

const i32 N = 400'000, logN = 19;

static i32 next_int() {
  i32 x = 0; char ch;
  while ((ch = getchar()) < '0' || ch > '9') continue;
  x = ch ^ '0';
  while ((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + (ch ^ '0');
  return x;
}

template <i32 N>
struct suffix_array {
  i32 p[N + 1], c[N + 1], lcp[N + 1], _n; char data[N + 1];
  suffix_array() noexcept : _n(0) { while ((data[_n] = getchar()) != '\n') ++_n; make(); }
  suffix_array(const char *source, i32 size) noexcept : _n(size) { assert(N >= (1 << 8)); copy(source, source + size, data); make(); }
  void make() noexcept { i32 cn[N + 1], pn[N + 1]; array<i32, 2> pre, cur; data[_n++] = '\0';
    {
      fill_n(lcp, (1 << 8), 0); for (i32 i = 0; i < _n; ++i) ++lcp[c[i] = data[i] - '\0']; for (i32 i = 0; i < (1 << 8); ++i) pn[i] = lcp[i] != 0;
      partial_sum(lcp, lcp + (1 << 8), lcp); for (i32 i = 0; i < _n; ++i) p[--lcp[c[i]]] = i;
      pn[0] = 0; partial_sum(pn, pn + (1 << 8), pn); for (i32 i = 0; i < _n; ++i) c[i] = pn[c[i]];
    }
    for (i32 k = 0; (1 << k) < _n; ++k, copy(cn, cn + _n, c)) {
      for (i32 i = 0; i < _n; ++i) { pn[i] = p[i] - (1 << k); if (pn[i] < 0) pn[i] += _n; }
      fill_n(lcp, _n, 0); for (i32 i = 0; i < _n; ++i) ++lcp[c[i]]; partial_sum(lcp, lcp + _n, lcp); for (i32 i = _n - 1; ~i; --i) p[--lcp[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0; i32 x = p[0] + (1 << k); if (x >= _n) x -= _n; pre = { c[p[0]], c[x] };
      for (i32 i = 1; i < _n; ++i, pre = cur) {
        x = p[i] + (1 << k); if (x >= _n) x -= _n; cur = { c[p[i]], c[x] };
        if (cur == pre) cn[p[i]] = cn[p[i - 1]]; else cn[p[i]] = cn[p[i - 1]] + 1;
      }
    }
    for (i32 i = 0, k = 0, x = c[i], y = p[x - 1]; i < _n - 1; lcp[x - 1] = k, ++i, k = max(k - 1, 0), x = c[i], y = p[x - 1]) while (data[i + k] == data[y + k]) ++k;
    lcp[_n - 1] = 0;
  }
  template <bool ub> i32 bs(const char *other, i32 other_size) const noexcept { i32 hi = _n, lo = 1, x; next: while (lo < hi) { x = (lo + hi) >> 1; for (i32 i = 0; i < other_size; ++i) { if (data[p[x] + i] == other[i]) continue; if (data[p[x] + i] < other[i]) lo = x + 1; else hi = x; goto next; } if constexpr (ub) lo = x + 1; else hi = x; } return lo; }
  i32 count(const char *other, i32 other_size) const noexcept { return bs<1>(other, other_size) - bs<0>(other, other_size); }
  i32 size() const { return _n; }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  suffix_array<N> s;
  i32 n = next_int();
  //i32 p[N];
  array<i32, 2> sub[N];
  for (i32 i = 0; i < n; ++i)
    sub[i][0] = next_int() - 1, sub[i][1] = next_int() - sub[i][0];

  /*
  //radix sort
  {
    i32 cnt[N], pn[N];
    // normal count sort according to 2nd element
    fill_n(cnt, s.size(), 0);
    for (i32 i = 0; i < n; ++i) ++cnt[sub[i][1]];
    partial_sum(cnt, cnt + s.size(), cnt);
    for (i32 i = n - 1; ~i; --i) pn[--cnt[sub[i][1]]] = i;
    // count sort of 1st element
    // according to the order of the permutation of sorted suffix array
    fill_n(cnt, s.size(), 0);
    for (i32 i = 0; i < n; ++i) ++cnt[s.c[sub[i][0]]];
    partial_sum(cnt, cnt + s.size(), cnt);
    for (i32 i = n - 1; ~i; --i) p[--cnt[s.c[sub[pn[i]][0]]]] = pn[i];

   for (i32 i = 0; i < s.size(); ++i) printf("%d ", s.p[i]);
   putchar('\n');
   for (i32 i = 0; i < s.size(); ++i) printf("%d ", s.lcp[i]);
   putchar('\n');
  }
 for (i32 i = 0; i < n; ++i) {
   printf("%d,%d ", sub[p[i]][0], sub[p[i]][1]);
   for (i32 j = sub[p[i]][0]; j - sub[p[i]][0] < sub[p[i]][1]; ++j) putchar(s.data[j]);
   putchar('\n');
 }
  {
    bitset<N> present;
    for (i32 i = 0, j = 0, k; i < n; ++i) {
      while (s.p[j] != sub[p[i]][0]) ++j;
      k = j;
      if (!s.lcp[j]) {
        printf("%d %d %d\n", i, j, k);
        continue;
      }
      do ++k; while(s.lcp[k] != 0 && k < n);
      printf("%d %d %d\n", i, j, k);
      i = j = k;
    }
  }
  */
  // the radix sort code above does not work for comparasion based sorting which we need
  // later on, so we abandon that method totally
  {
    /*
    for (i32 i = 0; i < s.size(); ++i) printf("%d ", s.p[i]);
    putchar('\n');
    for (i32 i = 0; i < s.size(); ++i) printf("%d ", s.lcp[i]);
    putchar('\n');
    */
    i32 st[logN][N + 1], lgn = __lg(s.size()) + 1;
    copy(s.lcp, s.lcp + s.size(), st[0]);
    for (int i = 1; i <= lgn; i++)
      for (int j = 0; j + (1 << i) <= s.size(); j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    sort(sub, sub + n, [&](array<i32, 2> x, array<i32, 2> y) {
        if (x[0] == y[0]) return x[1] < y[1];
        i32 l = s.c[x[0]], r = s.c[y[0]], ll = l, rr = r;
        if (l > r) swap(ll, rr);
        i32 lgt = __lg(rr - ll), cmn = min(st[lgt][ll], st[lgt][rr - (1 << lgt)]);
        if (x[1] <= cmn || y[1] <= cmn) {
          if (x[1] == y[1]) return x[0] < y[0];
          else return x[1] < y[1];
        } else if (x[1] <= cmn) return false;
        else if (y[1] <= cmn) return true;
        else return l < r;
      });
  }
    for (i32 i = 0; i < n; ++i) {
      printf("%d %d\n", sub[i][0] + 1, sub[i][1] + sub[i][0]);
    }
}
