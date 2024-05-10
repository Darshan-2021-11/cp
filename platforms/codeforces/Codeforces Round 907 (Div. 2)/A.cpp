#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;

// since n <= 20, these are all the possible power of 2's to compare with
const int powerOf2s[5] = { 1, 2, 4, 8, 16 };

int solve()
{
  int n, tmp = 0;
  cin >> n;
  int a[n];
  bool possible = true;

  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n - 1; ++i) {
    if(powerOf2s[tmp] != i + 1) {
      if(a[i] > a[i + 1]) {
        possible = false;
      }
    } else
      ++tmp;
  }
  if(possible)
    cout << "YES\n";
  else
    cout << "NO\n";

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
