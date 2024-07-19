#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 300'000;
static i32 a[N], n, k, ans;

bool check(i32 diff) {
  i32 pi = 0;
  for (i32 i = k + pi; i < n; ++i) {
    if (a[i] - a[pi] <= diff) continue;
    else if (i == pi + k) return false;
    else pi = i, i += k - 1;
  }
  return (a[n - 1] - a[pi] <= diff) && (n - 1 - pi >= k);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> k;
  --k;
  if (!k) {
    cout << 0;
    return 0;
  }
  for (i32 i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  i32 l = 0, r = ans = a[n - 1] - a[0], mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  cout << ans;
}

