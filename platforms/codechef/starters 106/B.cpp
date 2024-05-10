#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve() {
  int n, k, oddCount = 0, ans = 0;
  cin >> n >> k;

  int a[n];
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  if(k == 1) {
    for (size_t i = 0; i < n; i++) {
      if(a[i] & 1)
        ++ans;
      
    }
    goto answer;
  }

  for (size_t i = 0; i < k; i++) {
   if(a[i] & 1)
     ++oddCount;
  }
  if(oddCount)
    ++ans;

  for (size_t i = 0; i < n - k; i++) {
    (a[i] & 1) && --oddCount;
    (a[i + k] & 1) && ++oddCount;
    if(oddCount)
      ++ans;
  }

answer:
  cout << ans << '\n';
  return 0;
}

int main() {
  int t;
  cin >> t;

  while(t--)
    solve();
  return 0;
}
