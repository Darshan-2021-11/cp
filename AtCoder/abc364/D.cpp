#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001;
static i32 a[N], n, q, b, k, ans;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> q;
  for (i32 i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (i32 i = 0; i < q; ++i) {
    cin >> b >> k;
    i32 l = 0, r = 2e8, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (upper_bound(a, a + n, b + mid) - lower_bound(a, a + n, b - mid) >= k)
        r = mid;
      else l = mid + 1;
    }
    cout << l << '\n';
  }
}
