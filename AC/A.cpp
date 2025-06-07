#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100;
	int TC = 1, n, a[N];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		if (a[i] <= a[i - 1]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
