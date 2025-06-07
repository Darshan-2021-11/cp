#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, cnt0[2];
	cin >> TC;
	char a[2][N];
	while (TC--) {
		cin >> n;
		cnt0[0] = cnt0[1] = 0;
		for (int i = 0; i < n; ++i) cin >> a[0][i], cnt0[i & 1] += a[0][i] == '0';
		for (int i = 0; i < n; ++i) cin >> a[1][i], cnt0[~i & 1] += a[1][i] == '0';
		cout << (cnt0[0] >= ((n >> 1) + (n & 1)) && (cnt0[1] >= (n >> 1)) ? "YES\n" : "NO\n");
	}
}
