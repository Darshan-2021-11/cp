#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 25;
	int64_t sz[2], t;
	int n, x[2], y[2];
	bool b[2][N][N];
	string s0, s1;
	vector<bool> v;
	bool possible = true;

	cin >> n;

	for (int k = 0; k < 2; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		b[k][i][j] = 0;

	cin >> x[0] >> y[0];
	cin >> s0;
	sz[0] = s0.size() - 1;

	cin >> x[1] >> y[1];
	cin >> s1;
	sz[1] = s1.size() - 1;
	t = max(sz[0], sz[1]);
	b[0][x[0]][y[0]] = 1;
	b[1][x[1]][y[1]] = 1;
	if (b[0][x[1]][y[1]]) v.push_back(0);
	for (int i = 0; i < t; ++i) {
		if (sz[0] > t) {
			switch (s0[t]) {
				case 'r': ++y[0]; break;
				case 'l': --y[0]; break;
				case 'd': ++x[0]; break;
				case 'u': --x[0]; break;
			}
			b[0][x[0]][y[0]] = 1;
		}
		if (sz[1] > t) {
			switch (s1[t]) {
				case 'r': ++y[1]; break;
				case 'l': --y[1]; break;
				case 'd': ++x[1]; break;
				case 'u': --x[1]; break;
			}
			b[1][x[0]][y[0]] = 1;
		}
		if (b[0][x[1]][y[1]]) v.push_back(0);
	}

	if (v.size() & 1) {
	}
	if (!v.size()) goto print;
	if (v[0] == v[1]) {
		for (uint64_t i = 2; i < v.size(); i += 2) possible &= v[i] == v[i + 1];
	} else if (v[0] == v[v.size() - 1]) {
		for (uint64_t i = v.size() - 2; i > 0; i -= 2) possible &= v[i] == v[i - 1];
	} else possible = false;
print:
	if (possible) cout << "Impossible";
	else cout << v.size();
}
