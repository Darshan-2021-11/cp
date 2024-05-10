#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n;
ll osum, esum, t, maxelm;
bool allnegative;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    osum = esum = 0;
    maxelm = LLONG_MIN;
    allnegative = true;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      if (t > 0) (i & 1) ? osum += t: esum += t, allnegative = false;
      else maxelm = max(maxelm, t);
    }
    cout << (allnegative ? maxelm : osum > esum ? osum: esum) << '\n';
  }
}

