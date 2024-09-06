#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 n;
static struct {
  i32 data[3];
} p {{ 0, 0, 0 }}, c {{ 0, 0, 0 }};
static char cc;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  cin >> cc;
  if (cc == 'R') ++p.data[1];
  else if (cc == 'P') ++p.data[2];
  else ++p.data[0];
  for (i32 i = 1; i < n; ++i) {
    cin >> cc;
    switch (cc) {
      case 'R':
        c.data[1] = max(p.data[0], p.data[2]) + 1;
        c.data[0] = max(p.data[1], p.data[2]);
        break;
      case 'P':
        c.data[2] = max(p.data[0], p.data[1]) + 1;
        c.data[1] = max(p.data[0], p.data[2]);
        break;
      case 'S':
        c.data[0] = max(p.data[1], p.data[2]) + 1;
        c.data[2] = max(p.data[0], p.data[1]);
        break;
    }
    for (i32 j = 0; j < 3; ++j) p.data[j] = c.data[j];
  }
  cout << *max_element(p.data, p.data + 3);
}
