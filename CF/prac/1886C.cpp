#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 1'000'001;
static i64 TC, n, nc, t, steps, pos;
static char a[N], c;
int main() {
  while ((c = getchar()) != '\n') TC = TC * 10 + (c ^ '0');
  while (TC--) {
    n = nc = pos = 0, t = 1;
    while ((a[n] = getchar()) != '\n') ++n;
    while ((c = getchar()) != '\n') pos = pos * 10 + (c ^ '0');
    steps = n; while (pos > steps) pos -= steps, --steps;
    --pos;
    steps = n - steps;
    while (steps) {
      if (a[nc] > a[t]) {
        if (nc) --nc;
        else a[nc] = a[t++];
        --steps;
      } else a[++nc] = a[t++];
    }
    while (t < n) a[++nc] = a[t++];
    putchar(a[pos]);
  }
}

