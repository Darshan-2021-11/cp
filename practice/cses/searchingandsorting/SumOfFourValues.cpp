#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a[1000], n, n2, x, t, i, j;
tuple<u32, u32, u32> pairs[(u32)1e6];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> x;
  for (i = 0; i < n; ++i)
    cin >> a[i];
  n2 = 0;
  for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j) {
      if (i == j) continue;
      t = a[i] + a[j];
      if (t < x) pairs[n2++] = { t, i, j };
    }
  }
  if (n < 4 || n2 < 4) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  sort(pairs, pairs + n2);
  for (i = 0, j = n2 - 1; i < j;) {
    if ((t = get<0>(pairs[i]) + get<0>(pairs[j])) < x) ++i;
    else if (t > x) --j;
    else {
      if (
          get<1>(pairs[i]) == get<1>(pairs[j]) ||
          get<1>(pairs[i]) == get<2>(pairs[j]) ||
          get<2>(pairs[i]) == get<1>(pairs[j]) ||
          get<2>(pairs[i]) == get<2>(pairs[j])) {
        if (i + 1 == j) {
          goto end;
        } else if (get<0>(pairs[i]) == get<0>(pairs[i + 1])) ++i;
        else --j;
      } else {
        cout
          << get<1>(pairs[i]) + 1 << ' '
          << get<2>(pairs[i]) + 1 << ' '
          << get<1>(pairs[j]) + 1 << ' '
          << get<2>(pairs[j]) + 1 << '\n';
        return 0;
      }
    }
  }
end:
  cout << "IMPOSSIBLE\n";
  return 0;
}
