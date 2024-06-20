#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, one, two, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> one >> two;
    ans = two >> 1;
    if (two & 1) { ++ans; if (ans) one -= 7 * ans + 4; }
    else one -= 7 * ans;
    cout << (one > 99 ? ans : ans + (one / 15) + !!(one % 15)) << '\n';
  }
}

