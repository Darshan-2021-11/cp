#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, m, i, k, d, a, dq[(u32)2e5], dqf, dqb;
static u64 cost[(u32)2e5], mincostn[100], mincost, tmincost;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> m >> k >> d;
    for (i = 0; i < n; ++i) {
      dqf = dqb = 0;
      cin >> cost[0];
      ++cost[0];
      dq[dqb++] = 0;
      for (u32 j = 1; j < m; ++j) {
        if (dq[dqf] + d + 1 < j) ++dqf;
        cin >> a;
        cost[j] = cost[dq[dqf]] + a + 1;
        while (dqf != dqb && cost[dq[dqb - 1]] >= cost[j]) --dqb;
        dq[dqb++] = j;
      }
      mincostn[i] = cost[m - 1];
    }
    for (i = 0; i < k; ++i)
      mincost += mincostn[i];
    tmincost = mincost;
    for (; i < n; ++i)
      tmincost += mincostn[i] - mincostn[i - k],
      mincost = min(mincost, tmincost);
    cout << mincost << '\n';
    mincost = 0;
  }
}
