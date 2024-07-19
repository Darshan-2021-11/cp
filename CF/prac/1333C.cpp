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

static i32 n, s, p, t, c, a[200'000];
static i64 exc, ans, sum;
static map<i64, i32> mp;
static map<i64, i32>::iterator it;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  mp[0] = 0;
  for (i32 i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    if (a[i] == 0)
      ans += ((i64)(i - s) * (i - s + 1) >> 1) - exc,
      mp.clear(),
      mp[0] = sum,
      p = s = i + 1,
      exc = t = 0;
    else {
      if ((it = mp.find(sum)) != mp.end()) {
        c = (*it).second;
        if (c >= p) {
          t += c + 1 - p;
          p = c + 1;
        }
      }
      mp[sum] = i + 1;
      exc += t;
    }
  }
  ans += ((i64)(n - s) * (n - s + 1) >> 1) - exc;
  cout << ans << '\n';
}
