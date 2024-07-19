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

static i32 TC, maxans, ans;
static string a, b;


int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    maxans = 0;
    cin >> a >> b;
    for (int i = 0; i < b.size(); ++i) {
      ans = 0;
      for (int j = 0, k = i; j < a.size(); ++j) {
        if (a[j] == b[k]) ++ans, ++k;
        if (k == b.size()) break;
      }
      maxans = max(ans, maxans);
    }
    cout << a.size() + b.size() - maxans << '\n';
  }
}
