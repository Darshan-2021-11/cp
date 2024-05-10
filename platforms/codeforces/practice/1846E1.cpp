#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n;
bool possible[u32(1e6) + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  for (u32 i = 2, j; (j = i * i + i + 1) < u32(1e6) + 1; ++i)
    do possible[j] = true; while((j = j * i + 1) < u32(1e6) + 1);
  cin >> T;

  while (T--) {
    cin >> n;
    cout << (possible[n] ? "YES\n" : "NO\n");
  }
}
