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

static u32 TC, n, c, mi, a[200'000];
static u64 sum, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    mi = 0;
    cin >> n >> c;
    sum = c;
    for (u32 i = 0; i < n; ++i) { cin >> a[i]; if (a[i] > a[mi]) mi = i; }
    for (u32 i = 0; i < n; ++i) {
      sum += a[i];
      if (i == mi) cout << (a[0] + c >= a[mi] ? i : 0) << ' ';
      else if (sum >= a[mi]) cout << i << ' ';
      else cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}

