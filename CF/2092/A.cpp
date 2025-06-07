#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		cout << *max_element(a, a + n) - *min_element(a, a + n) << '\n';
	}
}
