#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m, k;
	cin >> TC;
	while (TC--) {
		cin >> n >> m >> k;
		//const int v = n * m / k;
		vector a(n, vector<int>(m));
		if (m % k == 0) {
			for (int i = 0; i < n; ++i) {
				int l = i & 1 ? k + 1 : 0;
				for (int j = 0; j < m; ++j) {
					if (i & 1) {
						--l;
						a[i][j] = l;
						if (l == 1) l = k + 1;
					} else {
						++l;
						a[i][j] = l;
						if (l == k) l = 0;
					}
					if (i && a[i - 1][j] == a[i][j]) swap(a[i][j], a[i][j - 1]);
				}
				//cout << '\n';
			}
		} else {
			int l = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					++l;
					a[i][j] = l;
					if (l == k) l = 0;
					if (i && a[i - 1][j] == a[i][j]) swap(a[i][j], a[i][j - 1]);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
}
