#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, k, sqrtk;
static u64 ans;
static bool prime[1'000'001], yes;
static vector<i32> primes;
void SieveOfEratosthenes(int nc)
{
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= nc; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= nc; i += p)
        prime[i] = false;
    }
  }
  for (int i = 2; i <= nc; ++i) {
    if (!prime[i]) continue;
    primes.push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  SieveOfEratosthenes(1'000'000);
  cin >> TC;

  while (TC--) {
    ans = 0;
    cin >> k;
    if (prime[k]) {
      for (const auto &i: primes) {
        if (i > k) break;
        ans += (u64)k * i;
      }
    } else {
      for (const auto &i: primes) {
        ans += (u64)k * i;
        if (k % i == 0) break;
      }
    }
    cout << ans << '\n';
  }
}

