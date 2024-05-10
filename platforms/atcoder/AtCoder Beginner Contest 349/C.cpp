#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  char a[100'001], b[4];
  int an = 0, bn = 0, i;
  while ((a[an++] = getchar_unlocked()) != '\n');
  --an;
  while ((b[bn] = getchar_unlocked()) != '\n') b[bn++] += 32;
  for (i = bn = 0; i < an; ++i) {
    if (a[i] == b[bn]) {
      switch (++bn) {
        case 2:
          if (b[bn] != 'x')
            break;
        case 3:
          cout << "Yes\n";
          return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}

