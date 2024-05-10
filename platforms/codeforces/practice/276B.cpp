#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n, i, cnt[26], oddcnt;
char s;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  // never incremented `n` as per character count earlier giving WA
  while (cin >> s) if (s) ++cnt[s - 'a'], ++n;
  for (u32 i = 0; i < 26; ++i) { if (cnt[i] & 1) ++oddcnt; }
  if (oddcnt < 2) {
    cout << "First";
    return 0;
  }
  if (n & 1) cout << "First";
  else cout << "Second";
}

