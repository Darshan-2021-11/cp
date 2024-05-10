#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T, cnt[2], n;
char tmp;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (u32 i = 2; i <= n; ++i) {
      cin >> tmp;
      if (tmp == '0') ++cnt[0];
      else ++cnt[1];
      if (!cnt[0] || !cnt[1]) cout << 1 << ' ';
      else cout << i - min(cnt[0], cnt[1]) << ' ';
    }
    cout << '\n';
    cnt[0] = cnt[1] = 0;
  }
}

