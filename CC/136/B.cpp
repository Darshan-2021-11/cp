#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u64 ans;
static int sum;
static u32 TC, n, c0, c1;
static char a[(u32)1e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n;
    map<int, u32> cnt;
    ++cnt[0];
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
    }
    ans = ((u64)n * (n + 1)) >> 1;
    for (u32 i = 0; i < n; ++i) {
      sum += a[i] == '0' ? -1 : 1;
      ans += cnt[sum];
      ++cnt[sum];
    }
    cout << ans << '\n';
    ans = c0 = c1 = 0;
  }
}

