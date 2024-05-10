#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, a[100], n, liars;
bool possible;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    liars = 0, possible = true;
    cin >> n;
    for (u32 i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a + n);
    // why this loop works to find out the number of liars in the `n` people
    // is that the liars are the only one who tells more numbers of liars are
    // present than originally are, so starting from the most bigger number,
    // if they are saying there are some `a` liars, they must come under them
    // and hence are lying..., so we increase liars count by 1 if they say
    // there are liars smaller or equal to the current number of liars, they
    // are telling truth.
    for (u32 i = n - 1; i < n; --i) if (a[i] > liars) ++liars; else break;
    // now we check that if someone originally predicted the total number of
    // liars but were considered incorrect and hence reaching contradiction
    for (u32 i = n - liars; i < n; ++i) if (a[i] == liars) { possible = false; break; }
    if (possible) cout << liars << '\n';
    else cout << -1 << '\n';
  }
}

