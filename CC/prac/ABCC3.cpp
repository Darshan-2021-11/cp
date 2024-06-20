#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, i, n, cnt[3], tc[2][2], mn;
static char a[(u32)3e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    mn = UINT32_MAX;
    cin >> n;
    for (i = 0; i < n; ++i) {
      cin >> a[i];
      ++cnt[a[i] - 'a'];
    }
    if (!cnt[1]) {
      cout << 0 << '\n';
      goto clean;
    }
    for (i = 0; a[i] != 'b'; ++i) {
      tc[0][0] += a[i] == 'a';
      tc[1][0] += a[i] == 'c';
    }
    mn = min(mn, cnt[2] - tc[1][0]);
    for (++i, --cnt[1]; cnt[1]; ++i, --cnt[1], tc[0][0] += tc[0][1], tc[0][1] = 0, tc[1][0] += tc[1][1], tc[1][1] = 0) {
      while (a[i] != 'b') {
        tc[0][1] += a[i] == 'a';
        tc[1][1] += a[i] == 'c';
        ++i;
      }
      mn = min(mn, tc[0][0] + cnt[2] - tc[1][0] - tc[1][1]);
    }
    mn = min(mn, tc[0][0]);
    cout << mn << '\n';
clean:
    memset(cnt, 0, sizeof(cnt));
    memset(tc, 0, sizeof(tc));
  }
}
