#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, a[(int)1e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ll sum = 0;
    bool negpresent = false, pospresent = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      if (a[i] < 0) negpresent = true;
      else if (a[i] > 0) pospresent = true;
      a[i] = -a[i];
    }
    if (n == 1) {
      cout << sum << '\n';
      continue;
    }

    ll mindsum = 0, maxdsum = 0, maximumSubArraySumII;
    int mind = 2, maxd = n, l = 0, r = 0, i;

    {

      for (i = 0; i < mind; ++i) {
        maxdsum += a[i];
      }
      maximumSubArraySumII = maxdsum;

      // We take a three pointer approach for this,
      // 1 2 3 ... l l+1 l+2 ... r r+1 r+2 ... i ... n    // Our pointer configuration
      // l: represents the leftmost pointer
      //  this is the leftmost point of which we have the sum's lower limit of both mindsum, maxdsum,
      //  always maintains a maximum distance of `maxd` from the rightmost pointer `i`.
      // r: represents the middle most pointer
      //  this is the rightmost point of which we have the sum from `l` to `r` stored in mindsum
      //  always maintains a minimum distance of `mind` from the rightmost pointer `i`.
      // i: represents the rightmost pointer,
      //  this is the one that actually moves towards the end of the array iteratively,
      //  and sum from `l` to `i` is stored in maxdsum

      // Whenever we see that the mindsum is negative or the element at the leftmost pointer is negative, we can remove
      // them to get the optimal maximum sum requirement of ours.

      // For this, we do three things
      // i) Check for exceeds upper limit of maxd
      // ii) Check for below limit of mind &&
      //  a) progress `l` if a[l] < 0
      //  b) update `l` to `r` and remove sum in between them if the mindsum is negative

      for (i = mind; i < n; ++i) {
        // for the case (i) and (ii)(a)
        if (i - l + 1 > maxd)
          maxdsum -= a[l], mindsum -= a[l], ++l;
        while (a[l] < 0 && i - l + 1 > mind)
          maxdsum -= a[l], mindsum -= a[l], ++l;

        // for the case (ii)(b) if
        // a[r] > 0, mindsum < 0, and mindsum + a[r] > 0
        if (mindsum < 0 && i - l + 1 > mind)
          maxdsum -= mindsum, mindsum = 0, l = r;

        maxdsum += a[i];
        mindsum += a[r++];

        // for the case (ii)(b) if
        // a[r] < 0, mindsum > 0, and mindsum + a[r] < 0
        if (mindsum < 0 && i - l + 1 > mind)
          maxdsum -= mindsum, mindsum = 0, l = r;
        maximumSubArraySumII = max(maxdsum, maximumSubArraySumII);
      }
    }

    if (maximumSubArraySumII > 0)
      sum = abs(sum + (maximumSubArraySumII << 1));
    cout << sum << '\n';
  }
}
