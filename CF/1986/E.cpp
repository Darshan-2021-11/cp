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

static u64 ans, oddsum, evensum;
static i32 TC, i, ai, n, nmp, k, mp[100'000][2], ocmk;
static array<i32, 2>  a[100'000];
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = true, ans = oddsum = evensum = nmp = 0, ocmk = -1;
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
      cin >> a[i][1];
      a[i][0] = a[i][1] % k;
    }
    sort(a, a + n);
    if (n == 1) {
      cout << ans << '\n';
      continue;
    }
    mp[nmp][0] = a[0][0], mp[nmp][1] = 1;
    for (i = 1; i < n; ++i) {
      if (a[i][0] != mp[nmp][0])
        mp[++nmp][0] = a[i][0],
        mp[nmp][1] = 1;
      else
        ++mp[nmp][1];
    }
    if (n & 1) {
      for (i = 0; i <= nmp; ++i) {
        if (mp[i][1] & 1) {
          if (ocmk == -1) ocmk = i;
          else break;
        }
      }
      if (nmp + 1 != i || ocmk == -1) {
        cout << -1 << '\n';
        continue;
      } else {
        for (i = 0; i < n; ++i) {
          if (a[i][0] == mp[ocmk][0]) break;
        }
        ai = i, oddsum = evensum = 0;
        for (i = ai + 2; i - ai < mp[ocmk][1]; i += 2) {
          oddsum += (a[i][1] - a[i - 1][1]) / k;
        }
        ans = oddsum;
        for (i = ai + 1; i - ai < mp[ocmk][1] - 1; i += 2) {
          evensum += (a[i][1] - a[i - 1][1]) / k;
          oddsum -= (a[i + 1][1] - a[i][1]) / k;
          ans = min(ans, evensum + oddsum);
        }
      }
      for (i = 1; i < n; ++i) {
        if (a[i][0] == mp[ocmk][0]) continue;
        if (a[i][0] == a[i - 1][0])
          ans += (a[i][1] - a[i - 1][1]) / k, ++i;
      }
    } else {
      for (i = 0; i <= nmp; ++i) {
        if (mp[i][1] & 1)
          break;
      }
      if (nmp + 1 != i) {
        cout << -1 << '\n';
        continue;
      }
      for (i = 1; i < n; ++i) {
        if (a[i][0] == a[i - 1][0])
          ans += (a[i][1] - a[i - 1][1]) / k, ++i;
      }
    }
    cout << ans << '\n';
  }
}
