#include <bits/stdc++.h>
using namespace std;

int main() {
  const int N = 200'000, MAX = 1'000'000;
  char IB[(N << 3) + 7], OB[N << 3];
  int mp[MAX + 1] {}, IB_N = 0, OB_N = 0, n, gcd = 1;
  auto read = [&]() -> int {
    int x = 0;
    while (IB[IB_N] >= '0' && IB[IB_N] <= '9') x = (x << 3) + (x << 1) + IB[IB_N++] - '0';
    ++IB_N;
    return x;
  };
  auto write = [&](int x) -> void {
    static char BUF[10];
    int i = 10;
    do BUF[--i] = x % 10 ^ '0'; while (x /= 10);
    while (i < 10) OB[OB_N++] = BUF[i++];
    OB[OB_N++] = ' ';
  };

  fread_unlocked(IB, 1, sizeof(IB), stdin);
  n = read();
  for (int i = 0; i < n; ++i) ++mp[read()];
  for (int i = 2, t; i <= MAX; ++i) {
    t = 0;
    for (int j = i; j <= MAX; j += i) t += mp[j];
    if (t > 1) gcd = i;
  }
  write(gcd);
  fwrite_unlocked(OB, 1, OB_N, stdout);
}
