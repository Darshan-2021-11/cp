#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n;
static char a[20];
static bool ch, yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = true, ch = false;
    cin >> n;
    cin >> a[0];
    if (isalpha(a[0])) ch = true;
    for (u32 i = 1; i < n; ++i) {
      cin >> a[i];
      if (isalpha(a[i])) ch = true;
      if (ch && isdigit(a[i])) yes = false;
      if (a[i] < a[i - 1]) yes = false;
    }
    cout << (yes ? "YES\n": "NO\n");
  }
}

