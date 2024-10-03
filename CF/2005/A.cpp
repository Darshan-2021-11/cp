#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n;
  const char *a = "aeiou";
  cin >> TC;
  while (TC--) {
    cin >> n;
    int cnt[5];
    for (int i = 0; i < 5; ++i) cnt[i] = n / 5;
    for (int i = 0; i < n % 5; ++i) ++cnt[i];
    for (int i = 0; i < 5; ++i) for (int j = 0; j < cnt[i]; ++j) cout << a[i];
    cout << '\n';
  }
}
