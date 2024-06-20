#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, m, ans, cnt[7];
static char a[50];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    cin >> n >> m;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      ++cnt[a[i] - 'A'];
    }
    for (u32 i = 0; i < 7; ++i) {
      if (cnt[i] < m) ans += m - cnt[i];
    }
    cout << ans << '\n';
  }
}

