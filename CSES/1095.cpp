#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

char IBUF[int(2e5)*22+7], OBUF[int(2e5)*11];
int IBUF_I = 0, OBUF_I = 0;
 
int read() {
  int x = 0;
  while (IBUF[IBUF_I]>='0' && IBUF[IBUF_I]<='9')
    x = 10*x+IBUF[IBUF_I++]-'0';
  ++IBUF_I;
  return x;
}
void write(int x) {
  static char BUF[10];
  int i = 10;
  do { BUF[--i] = x%10+'0'; } while (x /= 10);
  while (i < 10) OBUF[OBUF_I++] = BUF[i++];
  OBUF[OBUF_I++] = '\n';
}

int main() {
  fread_unlocked(IBUF, 1, sizeof(IBUF), stdin);
  int64_t a, b, r;
  const int MOD = 1e9 + 7;
  int n;
  n = read();
  while (n--) {
    a = read(), b = read();
    r = 1;
    while (b) {
      if (b & 1) (r *= a) %= MOD;
      (a *= a) %= MOD;
      b >>= 1;
    }
    write(r);
  }
  fwrite_unlocked(OBUF, 1, OBUF_I, stdout);
}
