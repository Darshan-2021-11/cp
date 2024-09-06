#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 1'000'000;
static i32 TC, n, nc, steps;
static i64 pos;
static char a[N], c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((c = getchar()) != '\n') TC = TC * 10 + (c ^ '0');
  while (TC--) {
    n = pos = steps = 0;
    while ((a[n] = getchar()) != '\n') ++n;
    nc = n;
    while ((c = getchar()) != '\n') pos = pos * 10 + (c ^ '0');
    while (pos > nc) printf("%lld\n", pos), pos -= nc, --nc;
    printf("%lld\n", pos);
  }
}

