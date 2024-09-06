#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static const char* yesno[] = { "NO", "YES" };
static i32 TC, n, mnusrt, mxsrt;
static bool amb, yes;
static char c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((c = getchar()) != '\n') TC = TC * 10 + (c ^ '0');
  while (TC--) {
    mnusrt = INT_MAX, yes = 1, n = mxsrt = amb = 0;
    while ((c = getchar()) != '\n') {
      switch (c) {
        case '+': {
                    ++n;
                    if (n < 2) mxsrt = n, mnusrt = INT_MAX, amb = 0;
                    break;
                  }
        case '-': {
                    if (mxsrt == n)
                      --mxsrt;
                    --n;
                    if (n < 2) mxsrt = n, mnusrt = INT_MAX, amb = 0;
                    if (n >= mnusrt) continue;
                    amb = 1, mnusrt = INT_MAX;
                    break;
                  }
        case '0': {
                    if (n >= mnusrt) continue;
                    else if (mxsrt == n) yes = 0;
                    mnusrt = n, amb = 0;
                    break;
                  }
        case '1': {
                    if (n >= mnusrt) yes = 0;
                    mxsrt = n, amb = 0;
                    break;
                  }
      }
    }
    puts(yesno[yes]);
  }
}
