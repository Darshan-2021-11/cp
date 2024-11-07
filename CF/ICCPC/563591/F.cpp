#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int d[4], c[4], x, ans[2] {};
  freopen("folding.in", "r", stdin);
  freopen("folding.out", "w", stdout);
  for (int i = 0; i < 4; ++i) cin >> d[i];
  if (d[0] < d[1]) swap(d[0], d[1]);
  if (d[2] < d[3]) swap(d[2], d[3]);
  for (int i = 0; i < 4; ++i) c[i] = d[i];
  if (d[0] < d[2] || d[1] < d[3]) {
    cout << -1;
    return 0;
  }
  while (d[0] > d[2]) {
    ++ans[0];
    x = (d[0] + 1) >> 1;
    if (x > d[2]) d[0] = x;
    else { d[0] = d[2]; break; }
  }
  while (d[1] > d[3]) {
    ++ans[0];
    x = (d[1] + 1) >> 1;
    if (x > d[3]) d[1] = x;
    else { d[1] = d[3]; break; }
  }
  for (int i = 0; i < 4; ++i) d[i] = c[i];
  swap(d[2], d[3]);
  if (d[0] < d[2] || d[1] < d[3]) {
    cout << ans[0];
    return 0;
  }
  while (d[0] > d[2]) {
    ++ans[1];
    x = (d[0] + 1) >> 1;
    if (x > d[2]) d[0] = x;
    else { d[0] = d[2]; break; }
  }
  while (d[1] > d[3]) {
    ++ans[1];
    x = (d[1] + 1) >> 1;
    if (x > d[3]) d[1] = x;
    else { d[1] = d[3]; break; }
  }
  cout << min(ans[0], ans[1]);
}
