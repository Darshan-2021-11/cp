#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 TC, n, m, d, sum, ans;
static i32 a[N], t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    priority_queue<i32, vector<i32>, greater<i32>> pq;
    cin >> n >> m >> d;
    sum = ans = 0;
    for (i32 i = 0; i < n; ++i) {
      sum -= d;
      cin >> a[i];
      if (a[i] <= 0)
        continue;
      pq.push(a[i]);
      if (pq.size() > m) {
        t = pq.top();
        pq.pop();
        sum += a[i] - t;
      } else sum += a[i];
      ans = max(sum, ans);
    }
    cout << ans << '\n';
  }
}
