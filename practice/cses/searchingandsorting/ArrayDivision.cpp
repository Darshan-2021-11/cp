#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int n, k, tk, mx, a[(int)2e5];
ll l, mid, h, tsum, psum, OptimalSum;
bool tkeqk;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  l = mx, h = OptimalSum = 2e14;
  while (l <= h) {
    tk = 1, tsum = psum = 0, mid = l + h >> 1;
    for (int i = 0; i < n; ++i)
      if (tsum + a[i] > mid) psum = max(psum, tsum), tsum = a[i], ++tk;
      else tsum += a[i];
    psum = max(tsum, psum);

    if (tk == k) {
      if (OptimalSum >= psum) OptimalSum = psum, h = mid - 1;
      else l = mid + 1;
    }
    else if (tk < k) h = mid - 1, OptimalSum = psum;
    else l = mid + 1;
  }
  cout << OptimalSum << '\n';
}
