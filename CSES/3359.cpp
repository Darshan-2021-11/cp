#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 3001;
	int TC = 1, n, u, tidx, idx[N * N], eidx[N];
	char a[N][N];
	//cin >> TC;
	while (TC--) {
		cin >> n;
		eidx[0] = eidx[1] = 0;
		// only keep `y` idx, as we know the total sum of x & y in each step
		idx[eidx[1]++] = 0;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 1, j, k; i < n; ++i) {
			eidx[i + 1] = eidx[i];
			for (j = eidx[i - 1]; i < eidx[i]; ++j)
		}
	}
}
