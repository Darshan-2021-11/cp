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
        char c, negative = 1; c = getchar(); while (c == ' ' || c == '\n') c = getchar();
        if (c == '-') negative = -1, c = getchar();
        x = 0; while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); } x *= negative; return *this; }
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

static u64 T = 1, r, r2, rp1, rp12, pr, prp1, t, x;
int main() {
  //ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> r;
    r2 = r * r;
    rp1 = r + 1;
    rp12 = rp1 * rp1;
    for (u64 i = 1; i < r; ++i) {
      pr += x = sqrt(r2 - (t = i * i));
      if (x * x + t == r2) --pr;
    }
    pr += r - 1;
    for (u64 i = 1; i < rp1; ++i) {
      prp1 += x = sqrt(rp12 - (t = i * i));
      if (x * x + t == rp12) --prp1;
    }
    prp1 += rp1 - 1;
    cout << ((prp1 - pr) << 2) << '\n';
    pr = prp1 = 0;
  }
}
