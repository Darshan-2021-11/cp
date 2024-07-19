#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, b[2], a[2];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> b[0] >> b[1];
    cin >> a[0] >> a[1];
    if (
        (a[0] < a[1] && b[0] > b[1]) ||
        (a[1] < a[0] && b[1] > b[0])
        ) cout << "NO\n";
    else cout << "YES\n";
  }
}

