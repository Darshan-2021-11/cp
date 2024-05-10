#include <bits/stdc++.h>
using namespace std;

int mind, maxd, n, l, r, i, a[200000];
long long mindsum, maxdsum, maximumSubArraySumII;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> mind >> maxd;
  for (i = 0; i < mind; ++i) {
    cin >> a[i];
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
    cin >> a[i];
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
  cout << maximumSubArraySumII << '\n';
}
