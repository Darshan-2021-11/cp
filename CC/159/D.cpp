#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;
int64_t inv(int64_t a) {
  return a == 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 20;
  int64_t TC = 1, n, a[N], k, cnt2;
  cin >> TC;
  while (TC--) {
    cnt2 = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << ((k + 1) * inv(2 * k)) % m << '\n';
  }
}
