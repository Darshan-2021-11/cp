#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a[262144], T = 1, n, ans;

u32 swap_cnt(u32 l, u32 r) {
  if (l - r < 2) return 0;
  u32 mid = (l + r) >> 1, swaps = a[l] > mid, dist = mid - l + 1;
  if (swaps) for (u32 i = l; i <= mid; ++i) swap(a[i], a[i + dist]);
  return swaps + swap_cnt(l, mid) + swap_cnt(mid + 1, r);

}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    ans = swap_cnt(0, n - 1);
    if (is_sorted(a, a + n)) cout << ans << '\n';
    else cout << -1 << '\n';
  }
}
