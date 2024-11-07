#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

char IBUF[int(1e5)*8+7], OBUF[int(1e5)*4];
int pre[int(1e6) + 1]{};
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
  for (int i = 1; i < 1e6 + 1; ++i) pre[i] = 1;
  for (int i = 2; i < 1e6 + 1; ++i) {
    for (int j = i; j < 1e6 + 1; j += i) ++pre[j];
  }
  fread_unlocked(IBUF, 1, sizeof(IBUF), stdin);
  int n;
  n = read();
  while (n--) {
    write(pre[read()]);
  }
  fputs(OBUF, stdout);
}
