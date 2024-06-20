#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static pair<u32, u32> c[(u32)2e5];
static u32 idx[(u32)2e5], n, m, minCost, t, i;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  m = n;
  for (i = 0; i < n; ++i) idx[i] = i, cin >> c[i].first >> c[i].second;
  sort(idx, idx + n, [](u32 x, u32 y) { return c[x] > c[y]; });
  minCost = c[idx[0]].second;
  for (i = 1; i < n; ++i) {
    t = c[idx[i]].second;
    if (t > minCost) idx[i] = UINT32_MAX, --m;
    minCost = min(minCost, t);
  }
  sort(idx, idx + n);
  cout << m << '\n';
  for (i = 0; i < m; ++i) cout << idx[i] + 1 << ' ';
}
