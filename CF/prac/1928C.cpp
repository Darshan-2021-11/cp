#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

// maximum number of factors of a number <= 1e9 = 1344
static u32 TC, n, x, c1, c2, sqc2, ks[1345 << 1], kn, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    kn = 0;
    cin >> n >> x;
    if ((n - x) & 1) {
      cout << 0 << '\n';
      continue;
    }
    // by solving (2k - 2) * u + x = n && (2k - 2) * u + x - 2 = n,
    // and cancelling common 2's i.e., the places where we can get the number `x`,
    // we get two constants. Our approach would be to find the factors of both
    // the numbers and their union would be our answer.
    c1 = n - x, c2 = n + x - 2;
    // LEARNING 1
    // one more thing to note here is that, if the is a common multiplier of both
    // factor and the number to find the factors of, like 50, then
    // factors of 50 <= sqrt(50)
    // but if there is a multiplier(m), then
    // factors of 50 <= sqrt(50 * m) would give us incorrect answer as
    // the factors would be of form 1*m, 2*m,... and the upper bound remain as
    // sqrt(50 * m), so we never actually reach to sqrt(50) * m, as we are limited
    // to sqrt(50) * sqrt(m),
    // so in order to satisfy it, we also need to increase the upper bound having
    // multiplier m from sqrt(50 * m) to sqrt(50* m * m),
    // or increase the upper bound by extra m inside the sqrt() function.
    // In this case, the increment can be `m`, to ensure proper finding of factors.
    //
    // LEARNING 2
    // if we decide to remove the common factor but increment by 1 the possible
    // factors however, we can still keep the upperbound tied to sqrt(50 * m),
    // but we need to essentially ensure that the factor is always a multiple of `m`,
    // otherwise we would struggle like in this problem for hours to understand
    // the intuition.
    // ALSO THIS UPPER LIMIT IS NOT OPTIMAL THAN REMOVING THE COMMON FACTOR ENTIRELY
    // OR FROM LEARNING 1
    sqc2 = sqrt(c2);
    for (u32 i = 2; i >> 1 <= sqc2; ++i) {
      // here we apply LEARNING 2 and check if `i` is a multiple of 2 or not
      if (!(c2 % i) && !(i & 1)) ks[kn++] = (i >> 1) + 1, ks[kn++] = c2 / i + 1;
      if (!(c1 % i) && !(i & 1)) ks[kn++] = (i >> 1) + 1, ks[kn++] = c1 / i + 1;
    }
    sort(ks, ks + kn);
    kn = unique(ks, ks + kn) - ks;
    ans = kn;
    for (u32 i = 0; i < kn; ++i) if (ks[i] < x) --ans; else break;
    cout <<  ans << '\n';
  }
}
