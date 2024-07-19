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

static char c;
static bool r, yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  for (i32 i = 0; i < 3; ++i) {
    cin >> c;
    if (c == 'M') yes = r;
    if (c == 'R') r = true;
  }
  cout << (yes ? "Yes" : "No");
}

