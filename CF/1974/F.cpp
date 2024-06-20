#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
namespace Fread { const int SZ = 1 << 17; char buf[SZ], *S, *T;
    inline char getchar() { if (S == T) { T = (S = buf) + fread(buf, 1, SZ, stdin);
    if (S == T) return '\n'; } return *S++; } }
namespace Fwrite { const int SZ = 1 << 12; char buf[SZ], *S = buf, *T = buf + SZ;
    inline void flush() { fwrite(buf, 1, S - buf, stdout); S = buf; }
    inline void putchar(char c) { *S++ = c; if (S == T) flush(); }
    struct NTR { ~ NTR() { flush(); }} ztr; }
#define getchar Fread::getchar
#define putchar Fwrite::putchar
namespace Fast { struct Reader { template<typename T> Reader& operator >> (T& x) {
    char c = getchar(); while (c < '0' || c > '9') c = getchar(); x = 0;
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); } return *this; }
    Reader& operator >> (char& c) { c = getchar();
    while (c == '\n' || c == ' ') c = getchar(); return *this; } } cin;
    struct Writer { template<typename T> Writer& operator << (T x) {
    if (x == 0) { putchar('0'); return *this; }
    if (x < 0) putchar('-'), x = -x;
    static int sta[45]; int top = 0; while (x) { sta[++top] = x % 10; x /= 10; }
    while (top) { putchar(sta[top] + '0'); --top; } return *this; }
    Writer& operator << (char c) { putchar(c); return *this; } } cout; }
#define cin Fast::cin
#define cout Fast::cout
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static array<u32, 2> x[(u32)2e5], y[(u32)2e5], xbe, ybe, xv, yv;
static u32 T = 1, a, b, n, m, xi, yi, i, j, mvcnt, alice, bob;
static bool available[(u32)2e5];
static char mv;
int main() {
  cin >> T;

  while (T--) {
    alice = bob = 0;
    cin >> a >> b >> n >> m;
    --a, --b;
    for (i = 0; i < n; ++i) {
      cin >> xi >> yi;
      --xi, --yi, x[i][0] = xi, y[i][0] = yi, x[i][1] = y[i][1] = i, available[i] = true;
    }

    sort(x, x + n); sort(y, y + n);
    xbe[0] = ybe[0] = xv[0] = yv[0] = 0,
    xbe[1] = ybe[1] = n - 1, xv[1] = a, yv[1] = b;
    for (i = 0; i < m; ++i) {
      cin >> mv >> mvcnt;
      switch (mv) {
        case 'U': {
                    xv[0] += mvcnt;
                    for (j = xbe[0]; j < n && x[j][0] < xv[0]; ++j) {
                      if (!available[x[j][1]]) continue;
                      if (i & 1) ++bob;
                      else ++alice;
                      available[x[j][1]] = false;
                    }
                    xbe[0] = j;
                  }
                  break;
        case 'D': {
                    xv[1] -= mvcnt;
                    for (j = xbe[1]; j < n && x[j][0] > xv[1]; --j) {
                      if (!available[x[j][1]]) continue;
                      if (i & 1) ++bob;
                      else ++alice;
                      available[x[j][1]] = false;
                    }
                    xbe[1] = j;
                  }
                  break;
        case 'L': {
                    yv[0] += mvcnt;
                    for (j = ybe[0]; j < n && y[j][0] < yv[0]; ++j) {
                      if (!available[y[j][1]]) continue;
                      if (i & 1) ++bob;
                      else ++alice;
                      available[y[j][1]] = false;
                    }
                    ybe[0] = j;
                  }
                  break;
        case 'R': {
                    yv[1] -= mvcnt;
                    for (j = ybe[1]; j < n && y[j][0] > yv[1]; --j) {
                      if (!available[y[j][1]]) continue;
                      if (i & 1) ++bob;
                      else ++alice;
                      available[y[j][1]] = false;
                    }
                    ybe[1] = j;
                  }
      }
    }
    cout << alice << ' ' << bob << '\n';
  }
}

