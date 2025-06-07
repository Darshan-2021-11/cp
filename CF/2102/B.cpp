#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int TC = 1, n, cnt, a[N];
	cin >> TC;
	while (TC--) {
		cnt = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] < 0) a[i] = -a[i];
			cnt += a[i] >= a[0];
		}
		cout << (cnt >= ((n + 1) >> 1) ? "YES\n" : "NO\n");
	}
}
