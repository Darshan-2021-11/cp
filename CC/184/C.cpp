#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, cnt[2][2];
	char c;
	cin >> TC;
	while (TC--) {
		cnt[0][0] = cnt[0][1] = 0;
		cnt[1][0] = cnt[1][1] = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> c, ++cnt[0][c - '0'];
		for (int i = 0; i < n; ++i) cin >> c, ++cnt[1][c - '0'];
	}
}
