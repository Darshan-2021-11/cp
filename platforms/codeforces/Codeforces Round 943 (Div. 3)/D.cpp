#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u64 T = 1, n, k, ps, pb, p[(u32)2e5], a[(u32)2e5], msasha, tsasha, mbodya, tbodya;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    msasha = mbodya = tbodya = tsasha = 0;
    cin >> n >> k >> pb >> ps;
    --ps, --pb;
    for (u32 i = 0; i < n; ++i) cin >> p[i];
    for (u32 i = 0; i < n; ++i) cin >> a[i];

    for (u32 i = 1; i <= min(n, k); ++i) {
      tsasha += a[ps];
      msasha = max(tsasha + (k - i) * a[ps], msasha);
      ps = p[ps] - 1;
      tbodya += a[pb];
      mbodya = max(tbodya + (k - i) * a[pb], mbodya);
      pb = p[pb] - 1;
    }
    if (mbodya == msasha) cout << "Draw\n";
    else if (mbodya > msasha) cout << "Bodya\n";
    else cout << "Sasha\n";
  }
}

