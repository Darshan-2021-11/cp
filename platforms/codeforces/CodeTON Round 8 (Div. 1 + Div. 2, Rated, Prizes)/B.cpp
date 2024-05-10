#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int a[u32(2e5)], ans[u32(2e5)], T = 1, n, i, j, t;
bool p[u32(2e5)];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
		cin >> n;
		memset(p, 0, n);
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		i = 0;
		while (a[i] < 0) {
			p[0 - a[i]] = true;
			ans[i] = 0 - a[i];
			++i;
		}
		ans[i] = 0;
		p[0] = true;
		j = 1;
		while (++i < n) {
			while (j < n - 1 && p[j]) ++j;
			if (a[i] > 0) {
				p[j] = true;
				ans[i] = j;
			} else {
				t = j - a[i];
				p[t] = true;
				ans[i] = t;
			}
		}
		for (i = 0; i < n; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}

