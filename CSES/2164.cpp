#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

char IBUF[int(1e5)*22+7], OBUF[int(1e5)*11];
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
  OBUF[OBUF_I++] = ' ';
}

int main() {
  fread(IBUF, 1, sizeof(IBUF), stdin);
  int n, k, q, l, r, x, shift, odd;
  q = read();
  while (q--) {
    n = read(), k = read();
    l = r = odd = shift = 0, x = n;
    while (k > x >> 1) {
      k -= x >> 1, odd |= (x & 1) << shift, x = (x >> 1) + (x & 1), ++shift;
      if (x == 1) goto comp;
    }
    l = (k << 1) - 1, r = x - l - 1;
comp:
    while (shift--) {
      if (odd >> shift & 1) {
        ((--x) <<= 1) |= 1;
        if (!l) swap(l, r);
        else {
          (--l) <<= 1, (++r) <<= 1;
          continue;
        }
      } else x <<= 1;
      l <<= 1, (r <<= 1) |= 1;
    }
    write(l + 1);
  }
  fputs(OBUF, stdout);
}
