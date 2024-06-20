#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC;
static u64 n, t;
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = true;
    cin >> n;
    while (n >= 10) {
      t = n % 10, n /= 10;
      if (t == 9) {
        yes = false;
      }
      n -= 1;
    }
    if (n) yes = false;
    cout << (yes ? "YES\n" : "NO\n");
  }
}

