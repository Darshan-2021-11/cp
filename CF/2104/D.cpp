#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 10'000'002;
	vector<bool> p(N, true);
	vector<int64_t> primes;
	p[0] = p[1] = false;
	for (int i = 2; i * i < N; ++i) {
		if (!p[i]) continue;
		for (int64_t j = int64_t(i) * i; j < N; j += i) p[j] = false;
	}
	for (int i = 0; i < N; ++i) if (p[i]) primes.push_back(i);
	partial_sum(primes.begin(), primes.end(), primes.begin());

	int64_t sum;
	int TC = 1, n, v, a[400'000];
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + n, greater<int64_t>());
		for (int i = n - 1; ~i; --i) {
			if (sum >= primes[i]) {
				v = i;
				break;
			}
			sum -= a[i];
		}
		cout << n - 1 - v << '\n';
	}
}
