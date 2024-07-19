#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

// Custom comparator for descending order
struct DescendingOrder {
  bool operator()(const u32 &a, const u32 &b) const {
    return a > b;
  }
};

static u32 n, t, x, ans;
static map<u32, u32, DescendingOrder> mp;
static vector<map<u32, u32>::iterator> it;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  mp[0];
  it.push_back(mp.begin());
  cin >> n;
  for (u32 i = 0; i < n; ++i) {
    cin >> t;
    x = (mp[t] = (*mp.upper_bound(t)).second + 1);
    if (it.size() == x) it.push_back(mp.lower_bound(t)), ans = x;
    else {
      if ((*it[x]).first == t) continue;
      mp.erase(it[x]), it[x] = mp.lower_bound(t);
    }
    for (const auto &[i, j]: mp) cout << i << ',' << j << ' ';
    cout << '\n';
  }
  cout << ans;
}
