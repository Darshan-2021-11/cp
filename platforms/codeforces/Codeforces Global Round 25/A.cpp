#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, cnt1, idx1;
char a[50];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cnt1 = 0, idx1 = UINT32_MAX;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == '1') {
        ++cnt1;
        if (idx1 == UINT32_MAX) idx1 = i;
      }
    }
    if (cnt1 & 1) cout << "NO\n";
    else if (cnt1 == 2) {
      u32 idx2 = n - 1;
      while (a[idx2] != '1') --idx2;
      if (idx2 - 1 == idx1) cout << "NO\n";
      else cout << "YES\n";
    } else cout << "YES\n";
  }
}

