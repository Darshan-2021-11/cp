#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, cnt[4], mv[4];
static char a[(u32)2e5], b[(u32)2e5];
static bool yes, t1, t2;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    yes = true;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      switch (a[i]) {
        case 'N': ++cnt[0]; a[i] = 0; break;
        case 'S': ++cnt[1]; a[i] = 1; break;
        case 'E': ++cnt[2]; a[i] = 2; break;
        case 'W': ++cnt[3]; a[i] = 3; break;
      }
    }
    if (
        // n is odd
        (n & 1) ||
        // only one of the north/south (& obviously east/west also follow this) have odd count
        ((cnt[0] ^ cnt[1]) & 1)
        )
      yes = false;
    else {
      if ((t1 = cnt[0] & cnt[1] & 1) & (t2 = cnt[2] & cnt[3] & 1)) {
        for (u32 i = 0; i < 2; ++i) ++mv[i];
      } else if (t1) {
        if (n == 2) yes = false;
        else for (u32 i = 0; i < 2; ++i) ++mv[i];
      } else if (t2) {
        if (n == 2) yes = false;
        else for (u32 i = 2; i < 4; ++i) ++mv[i];
      }
      for (u32 i = 0; i < 4; ++i) mv[i] += cnt[i] >> 1;
    }
    if (!yes) {
      cout << "NO\n";
      goto clean;
    }
    for (u32 i = 0; i < n; ++i) {
      if (mv[a[i]]) {
        cout << 'R';
        --mv[a[i]];
      } else cout << 'H';
    }
    cout << '\n';
clean:
    for (auto &i: cnt) i = 0;
    for (auto &i: mv) i = 0;
  }
}
