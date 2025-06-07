#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, mp[(N << 1) + 1], mp2[(N << 1) + 1];
	array<int, 2> a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		fill_n(mp, (n << 1) + 1, 0);
		fill_n(mp2, (n << 1) + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i][0] >> a[i][1];
			if (a[i][0] == a[i][1])
				mp2[a[i][0]] = true, ++mp[a[i][0]];
		}
		for (int i = 1; i <= n << 1; ++i)
			mp[i] += mp[i - 1];
		for (int i = 1; i <= n << 1; ++i)
			mp2[i] += mp2[i - 1];
		for (int i = 0; i < n; ++i) {
			if (a[i][0] == a[i][1]) cout << (mp[a[i][0]] - mp[a[i][0] - 1] == 1);
			else
				cout << ((mp2[a[i][1]] - mp2[a[i][0] - 1]) < (a[i][1] - a[i][0] + 1));
		}
		cout << '\n';
	}
}
