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

static i32 TC, n, mpn, u, nu, a[200'000], mpk[200'000], mpv[200'000];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    mpn = u = nu = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    mpk[0] = a[0];
    mpv[0] = 1;
    for (i32 i = 1; i < n; ++i) {
      if (a[i] == mpk[mpn]) ++mpv[mpn];
      else mpk[++mpn] = a[i], mpv[mpn] = 1;
    }
    for (i32 i = 0; i <= mpn; ++i) {
      u += mpv[i] == 1;
      nu += mpv[i] > 1;
    }
    cout << nu + (u ? 1 + ((u - 1) >> 1) : 0) << '\n';
  }
}

