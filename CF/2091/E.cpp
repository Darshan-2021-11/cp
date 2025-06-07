#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 2e7;
	int64_t ans;
	int TC = 1, n;
	vector<bool> isPrime(N + 1, true);
	vector<int64_t> primes;
	{
		int cnt = 1;
		isPrime[0] = isPrime[1] = false;
		for (int p = 2; p * p <= N; p++) {
			if (!isPrime[p]) continue;
			++cnt;
			for (int i = p * p; i <= N; i += p)
				isPrime[i] = false;
		}
		for (int i = 1; i <= N; ++i) if (isPrime[i]) primes.push_back(i);
	}
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		int idx = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		ans += idx;
		for (int i = 2; i <= n; ++i) {
			int l = 0, r = primes.size();
			while (l < r) {
				idx = l + r >> 1;
				if (primes[idx] * i <= n) l = idx + 1;
				else r = idx;
			}
			if (!r) break;
			ans += r;
		}
		cout << ans << '\n';
	}
}
