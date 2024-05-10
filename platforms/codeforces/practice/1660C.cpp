#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 0, n, t, del;
bool cnt[26];
char c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);

  while (isdigit(c = getchar())) T = T * 10 + c - '0';
  while (T--) {
    del = n = 0;
    fill(cnt, cnt + 26, false);
    while ((c = getchar()) != '\n') {
      c -= 'a';
      if (!cnt[c]) cnt[c] = true;
      else {
        del += count(cnt, cnt + 26, true) - 1;
        fill(cnt, cnt + 26, false);
      }
      ++n;
    }
    del += count(cnt, cnt + 26, true);
    cout << del << endl;
  }
}
