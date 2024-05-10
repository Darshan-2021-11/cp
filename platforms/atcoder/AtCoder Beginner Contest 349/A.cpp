#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int t, n, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  ans = 0;
  for (u32 i = 0; i < n - 1; ++i) {
    cin >> t;
    ans -= t;
  }
  cout << ans << '\n';

}

