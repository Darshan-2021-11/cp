#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 50;
	int TC = 1, n, m;
	char a[N][N];
	bool b[N][N][2];
	bool pos;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j], b[i][j][0] = b[i][j][1] = false;
		pos = true;
		//rows
		for (int i = 0; i < n; ++i) {
			for (int j = 0, prev = '1'; j < m; ++j) {
				if (a[i][j] <= prev) prev = a[i][j], b[i][j][0] = true;
				else break;
			}
		}
		//cols
		for (int j = 0; j < m; ++j) {
			for (int i = 0, prev = '1'; i < n; ++i) {
				if (a[i][j] <= prev) prev = a[i][j], b[i][j][1] = true;
				else break;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == '1') pos &= b[i][j][0] | b[i][j][1];
			}
		}
		cout << (pos ? "YES\n" : "NO\n");
	}
}
