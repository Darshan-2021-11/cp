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

static i32 TC, n, a[200'000], b[200'000], sm[2], s[2], ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    sm[0] = sm[1] = s[0] = s[1] = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (i32 i = 0; i < n; ++i) cin >> b[i];
    for (i32 i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
        if (a[i] == 1) ++sm[0];
        else if (a[i] == -1) ++sm[1];
      } else {
        if (a[i] < b[i]) {
          s[1] += b[i];
        } else {
          s[0] += a[i];
        }
      }
    }
    if (s[0] > s[1]) swap(s[0], s[1]);
    if (sm[0] >= s[1] - s[0]) {
      sm[0] -= s[1] - s[0];
      s[0] = s[1];
      s[1] += (sm[0] >> 1) + (sm[0] & 1);
      s[0] += (sm[0] >> 1);
    } else {
      s[0] += sm[0];
      sm[0] = 0;
    }
    if (sm[1] >= s[1] - s[0]) {
      sm[1] -= s[1] - s[0];
      s[1] = s[0];
      ans = s[0] - (sm[1] >> 1) - (sm[1] & 1);
    } else {
      ans = s[0];
    }
    cout << ans << '\n';
  }
}

