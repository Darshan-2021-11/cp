#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, x, l, r, a[N];

	// sieve of eratosthenes
	vector<bool> isPrime(N + 1, true);
	{
		isPrime[0] = isPrime[1] = false;
		for (int p = 2; p * p <= N; p++) {
			if (!isPrime[p]) continue;
			for (int i = p * p; i <= N; i += p)
				isPrime[i] = false;
		}
	}

	cin >> TC;
	while (TC--) {
		x = -1;
		cin >> n;
		vector<bool> t(n + 1);
		if (x & 1) l = r = (n + 1) >> 1;
		else l = n >> 1, r = l + 1;
		while (l > 0 && r <= n) {
			if (isPrime[l]) { x = l; break; }
			if (isPrime[r]) { x = r; break; }
			--l, ++r;
		}
		l = 0;
		if (x != -1) {
			a[0] = x, t[x] = true;
			for (l = 2; l <= n; ++l) {
				if (l & 1) {
					if (x + (l >> 1) > n) { --l; break; }
					a[l - 1] = x + (l >> 1);
					t[x + (l >> 1)] = true;
				} else {
					if (x - (l >> 1) <= 0) { --l; break; }
					a[l - 1] = x - (l >> 1);
					t[x - (l >> 1)] = true;
				}
			}
		}
		for (r = 1; r <= n; ++r) {
			if (t[r]) continue;
			a[l++] = r;
		}
		for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
	}
}
