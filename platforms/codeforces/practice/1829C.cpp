#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, t, mt01, mt10, mt11, skill;
bool b01, b10, b11;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    mt01 = mt10 = mt11 = UINT32_MAX;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      cin >> skill;
      switch(skill) {
        case 01: mt01 = min(mt01, t); break;
        case 10: mt10 = min(mt10, t); break;
        case 11: mt11 = min(mt11, t); break;
      }
    }
    b11 = mt11 != UINT32_MAX, b10 = mt10 != UINT32_MAX, b01 = mt01 != UINT32_MAX;
    if (b11 && b10 && b01) cout << min(mt11, mt01 + mt10) << '\n';
    else if (b11) cout << mt11 << '\n';
    else if (b10 && b01) cout << mt01 + mt10 << '\n';
    else cout << -1 << '\n';
  }
}

