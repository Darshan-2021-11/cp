#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static int TC, h, w, x[2], y[2], xd;
static bool notdraw;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> h >> w >> x[0] >> y[0] >> x[1] >> y[1];
    xd = x[1] - x[0] - 1;
    if (x[0] >= x[1]) cout << "DRAW\n";
    else if (y[0] == y[1]) {
      cout << (xd & 1 ? "BOB\n" : "ALICE\n");
    } else {
      if (xd & 1) {
        // Alice moves already once away from Bob
        if (y[0] > y[1]) {
          y[0] = max(1, y[0] - 1);
          notdraw = w - y[1] - (xd >> 1) < 2;
        } else {
          y[0] = min(w, y[0] + 1);
          notdraw = y[1] - (xd >> 1) - 1 < 2;
        }
        cout << (notdraw ? "BOB\n" : "DRAW\n");
      } else {
        if (y[0] > y[1]) {
          notdraw = y[0] - (xd >> 1) - 1 < 2;
        } else {
          notdraw = w - y[0] - (xd >> 1) < 2;
        }
        cout << (notdraw || abs(y[0] - y[1]) == 1 ? "ALICE\n" : "DRAW\n");
      }
    }
  }
}

