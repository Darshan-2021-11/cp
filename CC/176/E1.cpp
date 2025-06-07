#include <bits/stdc++.h>
using namespace std;





int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 2001, M = 31624;
	int64_t TC = 1, n, a[N], b[N], nxt[N << 1], adj[N << 1], head[N], primes[M], pm;
	bool prime[M];
	const auto SieveOfEratosthenes = [&]() -> void {
		pm = 0;
		memset(prime, true, sizeof(prime));
		for (int p = 2; p * p < M; p++) {
			if (prime[p] == true) {
				for (int i = p * p; i < M; i += p)
					prime[i] = false;
			}
		}
		for (int p = 2; p < M; p++) {
			if (prime[p]) {
				primes[pm++] = p;
			}
		}
	};
	SieveOfEratosthenes();
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			head[i] = b[i] = 0;
		}
		for (int i = 1, t = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			--u, --v;
			adj[t] = u, nxt[t] = head[v], head[v] = t++;
			adj[t] = v, nxt[t] = head[u], head[u] = t++;
		}
		for (int i = 0; i < n; ++i) {
			const auto dfs = [&](auto self, int c, int p, int mex) ->void {
				int cand = INT_MAX;
				for (int j = 0;; ++j) {
					if (a[c] <= primes[j] * primes[j] && a[c] > 1000) break;
					if (a[c] % primes[j]) {
						cand = primes[j];
						break;
					}
				}
				mex = min(mex, cand);
				b[i] += mex;
				for (int j = head[c], u; j; j = nxt[j]) if ((u = adj[j]) != p) {
					self(self, u, c, mex);
				}
			};
			dfs(dfs, i, i, INT_MAX);
			cout << b[i] << ' ';
		}
		cout << '\n';
	}
}
