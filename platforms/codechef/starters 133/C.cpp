#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, ans, ia, ibs, ibl, ic;
static char a[(u32)2e5];
vector<u32> idxa, idxb, idxc;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    idxa.clear(), idxb.clear(), idxc.clear();
    ans = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      switch(a[i]) {
        case 'a': idxa.push_back(i);
                    break;
        case 'b': idxb.push_back(i);
                    break;
        case 'c': idxc.push_back(i);
                    break;
      }
    }
    if (!idxa.size() || !idxb.size() || !idxc.size()) {
      cout << 0 << '\n';
      continue;
    }
    ia = 0, ibs = 0, ibl = idxb.size() - 1, ic = idxc.size() - 1;
    while ((ia < idxa.size()) && (ic < idxc.size())) {
      while (ibs < idxb.size() && idxa[ia] > idxb[ibs]) ++ibs;
      if (ibs >= idxb.size()) {
        break;
      }
      while (ibl < idxb.size() && idxb[ibl] > idxc[ic]) --ibl;
      if (ibl >= idxb.size()) {
        break;
      }
      u32 remove_c = lower_bound(idxc.begin(), idxc.end(), idxb[ibs]) - idxc.begin(),
          remove_a = idxa.end() - lower_bound(idxa.begin(), idxa.end(), idxb[ibl]);
      if (!remove_a || !remove_c) {
        break;
      }
      else if (remove_a > remove_c) --ic, ++ans;
      else ++ia, ++ans;
    }
    cout << ans << '\n';
  }
}

