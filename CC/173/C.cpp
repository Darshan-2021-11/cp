#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, m, a[N], b[N << 1], f[N << 1], k;
	int *c;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i], b[i + m] = b[i];
		fill_n(f, m << 1, -1);
		k = 0;
		for (int j = 1; j < m << 1; j++) {
			int i = f[j - k - 1];
			while (i != -1 && b[j] != b[k + i + 1]) {
				if (b[j] < b[k + i + 1]) k = j - i - 1;
				i = f[i];
			}
			if (b[j] != b[k + i + 1]) {
				if (b[j] < b[k]) k = j;
				f[j - k] = -1;
			} else {
				f[j - k] = i + 1;
			}
		}
		c = b + k;
		k = 0;
		bool start = false;
		for (int i = 0; i < n; ++i) {
		fill_n(f, m << 1, -1);
		k = 0;
		for (int j = 1; j < m << 1; j++) {
			int i = f[j - k - 1];
			while (i != -1 && b[j] != b[k + i + 1]) {
				if (b[j] < b[k + i + 1]) k = j - i - 1;
				i = f[i];
			}
			if (b[j] != b[k + i + 1]) {
				if (b[j] < b[k]) k = j;
				f[j - k] = -1;
			} else {
				f[j - k] = i + 1;
			}
		}
		c = b + k;
		fill_n(f, m << 1, -1);
		k = 0;
		for (int j = 1; j < m << 1; j++) {
			int i = f[j - k - 1];
			while (i != -1 && b[j] != b[k + i + 1]) {
				if (b[j] < b[k + i + 1]) k = j - i - 1;
				i = f[i];
			}
			if (b[j] != b[k + i + 1]) {
				if (b[j] < b[k]) k = j;
				f[j - k] = -1;
			} else {
				f[j - k] = i + 1;
			}
		}
		c = b + k;
			if (start) a[i] = c[k++];
			if (a[i] > c[0]) {
				if (i + m > n) continue;
				start = true;
				k = 0;
				a[i] = c[k++];
			}
			if (k == m) start = false;
		}
		for (int i = n - m; i < n; ++i) {
			if (a[i] < c[i - (n - m)]) break;
			else if (a[i] == c[i - (n - m)]) continue;
			else if (a[i] > c[i - (n - m)]) {
				for (int j = i; j < n; ++j) a[j] = c[j - (n - m)];
				break;
			}
		}
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
	}
}
