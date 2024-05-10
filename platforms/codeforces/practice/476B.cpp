#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int q, states, ans, tsum;
char c;

void calculate(int lq, int lsum2) {
  if (lq == q) { if(lsum2 == ans) ++states; return; }
  calculate(lq + 1, lsum2 - 1), calculate(lq + 1, lsum2 + 1);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((c = getchar()) != '\n') ans += c == '+' ? 1 : -1;
  while ((c = getchar()) != '\n') if (c == '?') q += 1; else tsum += c == '+' ? 1 : -1;
  if (!q) cout << (float)(ans == tsum) << '\n';
  else {
    calculate(0, tsum);
    cout << (float)states / (float)(1 << q) << '\n';
  }
}

