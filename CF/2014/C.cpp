#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, a[N], n, *mx, unhappy;
  int64_t sum, average, l, r, mid;
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sum = accumulate(a, a + n, 0LL);
    mx = max_element(a, a + n);
    l = 0, r = 1e15;
    while (l < r) {
      unhappy = 0;
      mid = (l + r) >> 1;
      average = (sum + mid + n - 1) / n;
      average = (average >> 1) + (average & 1);
      for (int i = 0; i < n; ++i)
        if (a + i != mx) unhappy += average > a[i];
      if (unhappy > (n >> 1)) r = mid;
      else l = mid + 1;
    }
    cout << (l == 1e15 ? -1 : l) << '\n';
  }
}
