#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int64_t x = 1;
	int TC = 1, n, c[N], a[N], b[N], t[2][2], mx[2];
	for (int i = 0; i < N; ++i) {
		c[i] = x;
		if ((x <<= 1) >= 998244353) x -= 998244353;
	}
	cin >> TC;
	while (TC--) {
		mx[0] = mx[1] = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		for (int i = 0, u; i < n; ++i) {
			if (a[i] > a[mx[0]]) mx[0] = i;
			if (b[i] > b[mx[1]]) mx[1] = i;
			t[0][0] = a[mx[0]], t[0][1] = b[i - mx[0]];
			if (t[0][1] > t[0][0]) swap(t[0][1], t[0][0]);
			t[1][0] = a[i - mx[1]], t[1][1] = b[mx[1]];
			if (t[1][1] > t[1][0]) swap(t[1][1], t[1][0]);
			u = 0;
			for (int j = 0; j < 2; ++j) if (t[0][j] < t[1][j]) { u = 1; break; } else if (t[0][j] > t[1][j]) break;
			x = c[t[u][0]] + c[t[u][1]];
			if (x >= 998244353) x -= 998244353;
			cout << x << ' ';
		}
		cout << '\n';
	}
}
