#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1e6 + 1;
	int TC = 1, spf[N] {}, fx[30], fy[30], x, y, k, nx, ny, u, v, ans;
	for (int64_t i = 2; i < N; ++i) {
		if (spf[i]) continue;
		spf[i] = i;
		for (int64_t j = i * i; j < N; j += i) if (!spf[j]) spf[j] = i;
	}
	cin >> TC;
	while (TC--) {
		nx = ny = ans = 0;
		cin >> x >> y >> k;
		while (x != 1 && y != 1) {
			u = spf[x], v = spf[y];
			if ((u > k) | (v > k)) break;
			if (u == v) x /= u, y /= v;
			else if (u < v) fx[nx++] = u, x /= u;
			else fy[ny++] = v, y /= v;
		}
		while (x != 1) {
			u = spf[x];
			if (u > k) break;
			fx[nx++] = u, x /= u;
		}
		while (y != 1) {
			v = spf[y];
			if (v > k) break;
			fy[ny++] = v, y /= v;
		}
		if (x != y) {
			cout << -1 << '\n';
			continue;
		}
		const auto eval = [&] (int (&f)[30], int &n) {
			while (n) {
				set<int64_t> s, t;
				s.insert(f[--n]);
				t = s;
				for (int i = 0; i < n; ++i) {
					for (const auto &j: s) {
						auto z = j * f[i];
						if (z > k) break;
						t.insert(z);
					}
					s = t;
				}
				v = *s.rbegin() / f[n];
				u = 0;
				for (int i = 0; i < n; ++i) {
					if (v > 1 && f[i] == spf[v]) v /= spf[v];
					else f[u++] = f[i];
				}
				n = u;
				++ans;
			}
		};
		eval(fx, nx);
		eval(fy, ny);
		cout << ans << '\n';
	}
}
