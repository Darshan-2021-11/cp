#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u64 l, r, lt, rt, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> l >> r;
  vector<u64> ranges = { l };
  lt = l;
  if (lt) {
    rt = lt + (~lt + 1 & lt);
    while (rt <= r) {
      ranges.push_back(rt);
      lt = rt;
      rt = lt + (~lt + 1 & lt);
    }
  }
  for (u32 i = 60; i < 64; --i) {
    t = 1ULL << i;
    if ((r & t) != (lt & t)) {
      lt |= 1ULL << i;
      ranges.push_back(lt);
    }
  }
  cout << ranges.size() - 1 << '\n';
  for (u32 i = 1; i < ranges.size(); ++i) {
    cout << ranges[i - 1] << ' ' << ranges[i] << '\n';
  }
}
