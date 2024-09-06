#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 300'001;
static i32 TC, n, mn, back[5], front[6];
static char a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  back[4] = front[5] = INT_MAX;
  while (TC--) {
    fill(back, back + 4, 0);
    fill(front, front + 5, 0);
    cin >> n;
    mn = n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (i32 i = n - 1; ~i; --i) {
      switch(a[i]) {
        case 'k': ++back[3];                        break;
        case 'c': if (back[3] > back[2]) ++back[2]; break;
        case 'a': if (back[2] > back[1]) ++back[1]; break;
        case 'b': if (back[1] > back[0]) ++back[0];
      }
    }
    /*
    cout << "back : ";
    for (i32 i = 0; i < 4; ++i) cout << back[i] << ' ';
    */
    while (back[0]) {
      mn -= 3;
      for (i32 i = 0; i < 4; ++i) --back[i];
      for (i32 i = 0; i < 4; ++i) if (back[i] < back[i + 1]) { ++back[i]; break; }
    }
    for (i32 i = 0; i < n; ++i) {
      switch(a[i]) {
        case 'f': ++front[4];                          break;
        case 'r': if (front[4] > front[3]) ++front[3]; break;
        case 'o': if (front[3] > front[2]) ++front[2]; break;
        case 'n': if (front[2] > front[1]) ++front[1]; break;
        case 't': if (front[1] > front[0]) ++front[0];
      }
    }
    /*
    cout << "front : ";
    for (i32 i = 0; i < 5; ++i) cout << front[i] << ' ';
    */
    while (front[0]) {
      mn -= 4;
      for (i32 i = 0; i < 5; ++i) --front[i];
      for (i32 i = 0; i < 5; ++i) if (front[i] < front[i + 1]) { ++front[i]; break; }
    }
    cout << mn << '\n';
  }
  //for (i32 i = 'a'; i <= 'z'; ++i) cout << (char)i << ':' << i - 'a' + 1 << ' ';
}
