#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC;
static i64 n, sqrtnmi2, i2;
static bool prime[100001], yes;
static vector<i64> primes;

void SieveOfEratosthenes(int nc)
{
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= nc; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= nc; i += p)
        prime[i] = false;
    }
  }
  prime[0] = prime[1] = prime[2] = false;
  for (int i = 3; i <= nc; ++i) {
    if (!prime[i]) continue;
    primes.push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  SieveOfEratosthenes(sizeof(prime) - 1);

  while (TC--) {
    yes = false;
    cin >> n;
    n -= 4;
    for (const auto &i: primes) {
      i2 = i * i;
      if (i2 >= n) break;
      sqrtnmi2 = sqrtl(n - i2);
      if (!prime[sqrtnmi2] || sqrtnmi2 * sqrtnmi2 + i2 != n || sqrtnmi2 == i) continue;
      yes = true;
      break;
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
}
