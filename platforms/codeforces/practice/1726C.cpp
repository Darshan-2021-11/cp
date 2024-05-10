#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, components, maxDepth, i, j;
char t;
bool present[(u32)1e5 + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    maxDepth = components = 0;
    cin >> n;
    n <<= 1;
    for (i = 0, j = 0; i < n; ++i) {
      cin >> t;
      if (t == '(') {
        if (!present[j]) present[j++] = true, ++components, maxDepth = max(maxDepth, j);
        else ++j;
      } else present[j--] = false;
    }
    cout << components << '\n';
    for (i = 0; i < maxDepth; ++i) present[i] = false;
  }
}

