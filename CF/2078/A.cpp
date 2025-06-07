#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 500;
	int TC = 1, n, x, a[N], sum;
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n >> x;
		for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
		cout << (sum % n || sum / n != x ? "NO\n" : "YES\n");
	}
}
