#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 n, m, t, b[200'000];
static multiset<int> a;
static multiset<int>::iterator it;
static i64 cost;
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  yes = true;
  cin >> n >> m;
  for (i32 i = 0; i < n; ++i) cin >> t, a.insert(t);
  for (i32 i = 0; i < m; ++i) cin >> b[i];
  sort(b, b + n, greater<i32>());
  for (i32 i = 0; i < m; ++i) {
    if ((it = a.lower_bound(b[i])) != a.end()) {
      cost += *it;
      a.erase(it);
    } else {
      yes = false;
      break;
    }
  }
  cout << (yes ? cost : -1);
}

