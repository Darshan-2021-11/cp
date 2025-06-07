#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 10;
	int TC = 1, n, s;
	char a[N];
	cin >> TC;
	while (TC--) {
		s = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i], s += a[i] == '1';
		s *= n;
		for (int i = 0; i < n; ++i) if (a[i] == '1') --s; else ++s;
		cout << s << '\n';
	}
}
