#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int t, n, n2, x, y, d, s, v;
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1, 0 };
	cin >> t;
	while (t--) {
		cin >> n;
		n2 = n * n;
		vector<vector<int>> g(n, vector<int>(n, 0));
		x = y = (n - 1) / 2;
		d = 0, s = 1, v = 0;
		g[x][y] = v++;
		while (v < n2) {
			for (int rep = 0; rep < 2; rep++) {
				for (int i = 0; i < s; i++) {
					if (v >= n2) break;
					x += dx[d];
					y += dy[d];
					if (x >= 0 && x < n && y >= 0 && y < n) {
						g[x][y] = v++;
					}
				}
				d = (d + 1) & 3;
				if (v >= n2) break;
			}
			s++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << g[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
