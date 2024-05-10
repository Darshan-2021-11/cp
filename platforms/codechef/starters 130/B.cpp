#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, a[(int)2e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int minelm = *min_element(a, a + n);
    if (a[0] > minelm || a[n - 1] > minelm) cout << "NO\n";
    else cout << "YES\n";
  }
}

