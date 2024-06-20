#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static int a, b, c, d, xdiff, ydiff, xoff, yoff;
static const int area[2][4] = {
  { 2, 1, 0, 1 },
  { 1, 2, 1, 0 },
},
  twobyfour = 8;
static u64 ans;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> a >> b >> c >> d;
  xdiff = c - a, ydiff = d - b, xoff = a % 4, yoff = b % 2;
  if (xoff < 0) xoff += 4;
  if (yoff < 0) yoff += 2;
  cout << xoff << ' ' << yoff << '\n';
  ans = 0;
}

