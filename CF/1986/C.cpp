#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, n, m, t;
static char a[100'000], b[100'000];
static bool idx[100'000];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n >> m;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i];
      idx[i] = false;
    }
    for (i32 i = 0; i < m; ++i) {
      cin >> t;
      idx[t - 1] = true;
    }
    for (i32 i = 0; i < m; ++i) cin >> b[i];
    sort(b, b + m);
    t = 0;
    for (i32 i = 0; i < n; ++i) {
      if (idx[i]) a[i] = b[t++];
      cout << a[i];
    }
    cout << '\n';
  }
}

