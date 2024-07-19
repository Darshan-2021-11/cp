#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'000;
static i32 T, n, c[2];
static char cc, pc;
static bool yes, f1, l1;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    yes = pc = c[0] = c[1] = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) {
      cin >> cc;
      if (cc == '0' && cc == pc) continue;
      else c[0] += cc == '0', c[1] += cc == '1';
      pc = cc;
    }
    yes = c[1] > c[0];
    cout << (yes ? "YES\n" : "NO\n");
  }
}
