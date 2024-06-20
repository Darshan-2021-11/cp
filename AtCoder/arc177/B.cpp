#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 n, m;
static char s[30];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (u32 i = 0; i < n; ++i) {
    cin >> s[i];
    if (s[i] == '1') m += (i << 1) + 1;
  }
  cout << m << '\n';
  for (u32 i = n - 1; i < n; --i) {
    if (s[i] != '1') continue;
    for (u32 j = 0; j <= i; ++j) {
      cout << 'A';
    }
    for (u32 j = 0; j < i; ++j) {
      cout << 'B';
    }
  }
}

