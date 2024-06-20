#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static const u32 MAX = (u32)4e5 + 7;
static u32 TC, n, sum, carry, bn;
static char a[MAX];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    sum = carry = 0;
    bn = MAX;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] ^= '0';
      sum += a[i];
    }
    for (u32 i = n - 1; ~i && sum; --i) {
      carry += sum;
      a[--bn] = (carry % 10) ^ '0';
      carry /= 10;
      sum -= a[i];
    }
    while (carry) {
      a[--bn] = (carry % 10) ^ '0';
      carry = carry / 10;
    }
    for (u32 i = bn; i < MAX; ++i) cout << a[i];
    cout << '\n';
  }
}
