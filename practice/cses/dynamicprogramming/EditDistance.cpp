#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 na, nb;
char a[5000], b[5000], t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((t = getchar_unlocked()) != '\n') a[na++] = t;
  while ((t = getchar_unlocked()) != '\n') b[nb++] = t;
  for (u32 i = 0; i < na; ++i) cout << a[i];
  cout << '\n';
  for (u32 i = 0; i < nb; ++i) cout << b[i];
  cout << '\n';
}
