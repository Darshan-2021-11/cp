#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;

int solve()
{
  int n, q;
  cin >> n >> q;
  ll a[n], tmp;

  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < q; i++) {
    cin >> tmp;
    tmp = 1 << tmp;
    for (size_t j = 0; j < n; j++) {
      if(!(a[j] % tmp))
        a[j] += (tmp >> 1);
    }
  }
  for (size_t i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}
