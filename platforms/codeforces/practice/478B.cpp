#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u64 nCk(u32 n, u32 k) {
  u64 nCk = 1;
  for (u32 i = 1; i <= k; ++i) nCk = (nCk * (n - k + i)) / i;
  return nCk;
}

u32 m, n, nbym, nmodm;
u64 minv, maxv, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  nbym = n / m, nmodm = n % m;
  if (nmodm)
    minv = ((1LL * nbym * (nbym + 1)) >> 1) * nmodm,
    minv += ((1LL * nbym * (nbym - 1)) >> 1) * (m - nmodm);
  else minv =  ((1LL * nbym * (nbym - 1)) >> 1) * m;
  n -= m - 1;
  maxv = (1LL * n * (n - 1)) >> 1;
  cout << minv << ' ' << maxv << '\n';
}
