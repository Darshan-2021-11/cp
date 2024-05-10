#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T, n, i, j, k, a[(u32)2e5];
u64 ans, sum, tsum;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    sum = tsum = ans = 0;
    cin >> n >> k;
    k <<= 1;
    for (i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    for (i = 0; i < k; ++i) {
      tsum += a[i];
    }
    ans = max(ans, sum - tsum);
    for (i = n - 1, --k, j = n - 1; k < n; k -= 2, --i) {
      tsum -= a[k] + a[k - 1];
      tsum += a[i];
      ans = max(ans, sum - tsum);
    }
    cout << ans << '\n';
  }
}

