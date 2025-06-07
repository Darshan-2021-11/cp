#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, mx, b[N], a[N], mp[N];
	cin >> TC;
	while (TC--) {
		mx = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> b[i], --b[i], a[i] = -1, mp[i] = 0;
		for (int i = 0; i < n; ++i) {
			if (!mp[b[i]]) a[i] = b[i], ++mp[b[i]];
		}
		for (int i = 0, j = 0; i < n; ++i) {
			if (a[i] != -1) goto print;
			while (mp[j] != 0) ++j;
			a[i] = j++;
print:
			cout << a[i] + 1 << ' ';
		}
		cout << '\n';
	}
} 
