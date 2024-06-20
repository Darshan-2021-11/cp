#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, total_wins;
static char grid[3][3], wins[4];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    for (u32 i = 0; i < 3; ++i) {
      wins[i] = 0;
      for (u32 j = 0; j < 3; ++j) {
        cin >> grid[i][j];
        switch (grid[i][j]) {
          case 'O': grid[i][j] = 0; break;
          case 'X': grid[i][j] = 1; break;
          case '+': grid[i][j] = 2; break;
          case '.': grid[i][j] = 3;
        }
      }
    }

    for (u32 i = 0; i < 3; ++i)
      if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
        wins[grid[i][0]] = true;
    for (u32 i = 0; i < 3; ++i)
      if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
        wins[grid[0][i]] = true;

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
      wins[grid[0][0]] = true;
    else if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])
      wins[grid[0][2]] = true;

    if ((total_wins = accumulate(wins, wins + 3, 0)) > 1 || !total_wins) {
      cout << "DRAW\n";
    } else {
      for (u32 i = 0; i < 3; ++i) {
        if (!wins[i]) continue;
        switch (i) {
          case 0: cout << 'O' << '\n'; break;
          case 1: cout << 'X' << '\n'; break;
          case 2: cout << '+' << '\n';
        }
        break;
      }
    }

  }
}
