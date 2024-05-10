#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> primes = { 3, 5, 7, 11 };

int solve() {
  int n, s, tmp, oddFactors = 0;
  cin >> n;

  s = sqrt(n);
  if(s * s == n) {
    ++oddFactors;
    goto answer;
  }
  while(!(n & 1))
    n >>= 1;

  if(n == 0){
    goto answer;
  }
  for (size_t i = 0; primes[i] <= n || ; i++) {
    if(primes.end() < n) {
      increasePrimes(n);
    }
    while(!(n % primes[i])) {
      ++oddFactors, n -= primes[i];
    }
    if(n == 0)
      goto answer;
  }

answer:
  cout << oddFactors << ' ' << (oddFactors & 1 ? "Alice" : "Bob") << '\n';
  return 0;
}

int main() {
  for (size_t i = 13; i <= sqrt(INT_MAX) + 1; i += 2) {
    int r = sqrt(i);
    bool isPrime = true;
    for (size_t j = 0; i < primes.size(); j++) {
      if(primes[j] > r){
        break;
      }
      if(!(i % primes[j])) {
        isPrime = false;
        break;
      }
    }
    if(isPrime)
      primes.push_back(i);
  }
  int t;
  cin >> t;

  while(t--)
    solve();
  return 0;
}
