#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;

ll compare[30];
ll add[30];

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
    for (size_t j = 0; j < n; j++) {
      if(!(a[j] & compare[tmp]))
        a[j] += add[tmp];
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
  for (size_t i = 0; i < 30; i++) {
    compare[i] = (1 << i) - 1;  
    add[i] = 1 << (i - 1);
  }
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}
